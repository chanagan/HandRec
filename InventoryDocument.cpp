//
// Created by Chris Hanagan on 9/8/18.
//
#include <wx/textfile.h>
#include <wx/arrstr.h>

#include "InventoryDocument.h"
#include "InvStockItem.h"

#include <wx/arrimpl.cpp>
WX_DEFINE_OBJARRAY(ArrayOfMatnr);

void InventoryDocument::LoadInventory(wxString curr_path) {
    CurrentDocPath = curr_path;

    // load the inventory document
    LoadInventoryDocument();


    // process the inventory items from the document
    LoadInventoryStock();

}

void InventoryDocument::LoadStockItem(size_t) {

}

void InventoryDocument::LoadInventoryDocument() {
    size_t line_idx = 0;
    wxString lStr;
    InvStockItem *invStockItem;
    wxTextFile file(CurrentDocPath);
    wxArrayString line_fields;

    file.Open();
    all_inv_lines = new wxArrayString;
    num_of_lines = file.GetLineCount();

    for (lStr = file.GetFirstLine(); !file.Eof(); lStr = file.GetNextLine()) {
        // if this a document filler line, ignore it
        if (is_not_used(lStr)) {
            continue;
        }

        // these are per document data
        line_fields = wxSplit(lStr, ' ');
        if (line_fields[0] == "(CurrentDate)") {
            inv_date = line_fields[1];
            continue;
        }
        if (line_fields[0] == "(Inv") {
            inv_num = line_fields[3];
            continue;
        }
        if (line_fields[0] == "(MATNR)") {
            // this is the National Stock Number (NSN) and
            // each inventory item has a unique one of these
            invStockItem = new InvStockItem(line_fields[1], line_idx);
            nsn_list.Add(invStockItem);
        }

        all_inv_lines->Add(lStr);
        line_idx++;

    }
    file.Close();
    num_of_lines = (int) all_inv_lines->GetCount();
}

void InventoryDocument::LoadInventoryStock() {
    bool item_done;
    size_t nsn_count = nsn_list.Count();
    int jj;
    InvStockItem *tmp_stock_item;
    wxString tmp_line;
    wxArrayString line_fields;

    // loop through all the stock items (NSNs)
    for (int i = 0; i < nsn_count; i++) {
        int fld_count = 1;
        int fld_count_req = 5;
        size_t lines_idx;
        tmp_stock_item = &nsn_list.Item((size_t) i);
        lines_idx = tmp_stock_item->getNsn_idx();
        tmp_line = all_inv_lines->Item(lines_idx);

        // first, back up until hit (LIN)
        item_done = false;
        do {
            // keep track of how many fields we've filled for this item
            // already have the NSN
            lines_idx--;
            // first, don't go back beyond first line
            if (lines_idx > num_of_lines) {
                item_done = true;
                continue;
            }
            // split the fields out to get the key field
            tmp_line = all_inv_lines->Item(lines_idx);
            line_fields = wxSplit(tmp_line, ' ');
            // if we backed up to this, we're near the beginning
            if (line_fields[0] == "(LIN)") {
                tmp_stock_item->setLin(line_fields[1]);
                fld_count++;
                item_done = true;
                continue;
            }
            if (line_fields[0] == "(QTY)") {
                tmp_stock_item->setQuantity(line_fields[1]);
                fld_count++;
            }
            if (line_fields[0] == "(NOM)") {
                tmp_stock_item->setNomen(tmp_line.substr(6));
                fld_count++;
            }
            if (line_fields[0] == "(MPO)") {
                tmp_stock_item->setMpo(line_fields[1]);
                fld_count++;
            }
        } while (!item_done);

        lines_idx = tmp_stock_item->getNsn_idx();

        // if we don't have enough fields yet,
        // now go forward to find the rest of the fields
        if (fld_count < fld_count_req) {
            do {
                lines_idx++;
                // first, don't go back beyond first line
                if (lines_idx > num_of_lines) {
                    item_done = true;
                    break;
                }
                // split the fields out to get the key field
                tmp_line = all_inv_lines->Item(lines_idx);
                line_fields = wxSplit(tmp_line, ' ');
//                // if we backed up to this, we're near the beginning
//                if (line_fields[0] == "(LIN)") {
//                    tmp_stock_item->setLin(line_fields[1]);
//                    fld_count++;
//                    item_done = true;
//                    continue;
//                }
                if (line_fields[0] == "(QTY)") {
                    tmp_stock_item->setQuantity(line_fields[1]);
                    fld_count++;
                }
                if (line_fields[0] == "(NOM)") {
                    tmp_stock_item->setNomen(tmp_line.substr(6));
                    fld_count++;
                }
                if (line_fields[0] == "(MPO)") {
                    tmp_stock_item->setMpo(line_fields[1]);
                    fld_count++;
                }
            } while (fld_count < fld_count_req);
        }
        lines_idx = tmp_stock_item->getNsn_idx();

//    lines_idx--;
//    tmp_line = all_inv_lines->Item(lines_idx);
//    line_fields = wxSplit(tmp_line, ' ');
//
//    if (line_fields[0]=="(QTY)") {
//      tmp_stock_item->setQuantity(line_fields[1]);
//      lines_idx--;
//      tmp_line = all_inv_lines->Item(lines_idx);
//      line_fields = wxSplit(tmp_line, ' ');
//    }
//
//    if (line_fields[0]=="(NOM)") {
//      tmp_stock_item->setNomen(tmp_line.substr(6));
//      lines_idx--;
//      tmp_line = all_inv_lines->Item(lines_idx);
//      line_fields = wxSplit(tmp_line, ' ');
//    }
//
//    lines_idx--;
//    tmp_line = all_inv_lines->Item(lines_idx);
//
//    jj++;
    }
    jj++;
}

InvStockItem *InventoryDocument::nsn_item(size_t which_item) {
    InvStockItem *tmp_nsn_item;
    tmp_nsn_item = &nsn_list.Item(which_item);
    return tmp_nsn_item;

}

bool InventoryDocument::is_not_used(wxString wrk_str) {
    if (wrk_str.IsEmpty()) {
        return TRUE;
    }
    if (wrk_str.Find("FE") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("(CHARG)") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("(UOM)") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("(CIIC)") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("SLOC:") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("REMARK :") != wxNOT_FOUND) {
        return TRUE;
    }
//    if (wrk_str.Find("rial / Equip") != wxNOT_FOUND) {
//        return TRUE;
//    }
    if (wrk_str.Find("ORIED QTY :") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("Filler_5") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("DISCREPANCIES") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("Signature") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("DODAAC") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("INDICATED ABOVE") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.Find("UIC") != wxNOT_FOUND) {
        return TRUE;
    }
    if (wrk_str.StartsWith("Inv Doc")) {
        return TRUE;
    }
    if (wrk_str.StartsWith("Date ")) {
        return TRUE;
    }
    if (wrk_str.StartsWith("(Listing")) {
        return TRUE;
    }
    if (wrk_str.StartsWith("(LGOBE)")) {
        return TRUE;
    }
    if (wrk_str.StartsWith("Date Pre")) {
        return TRUE;
    }
    if (wrk_str.StartsWith("Page ")) {
        return TRUE;
    }
    if (wrk_str.StartsWith("UIC:")) {
        return TRUE;
    }
    if (wrk_str.StartsWith("\f")) {
        return TRUE;
    }
    return FALSE;
}




