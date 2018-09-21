//
// Created by Chris Hanagan on 9/8/18.
//
#include <wx/textfile.h>
#include <wx/arrstr.h>

#include "InventoryDocument.h"
#include "InvStockItem.h"

void InventoryDocument::LoadInventory(wxString curr_path) {
    CurrentDocPath = curr_path;
    size_t line_idx = 0;

    InvStockItem *invStockItem;

    wxTextFile file(CurrentDocPath);
    wxArrayString line_fields;
    file.Open();
    wxString lStr;
    all_inv_lines = new wxArrayString;
//    size_t fileNums;
//    fileNums = file.GetLineCount();

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
//            size_t this_item = wrk_idx;
//            list.Add(&this_item);

//            invStockItem-> nsn = string_idx;
// TODO add the array for storing the stock items
        }

        all_inv_lines->Add(lStr);
        //        (*MainEditBox) << lStr << "\n";
//
//        lstr_splt = wxSplit(lStr, ' ');
//        strlen = lstr_splt.Count();
//
//        if (lstr_splt.Item(0).Cmp("FE:")) {
//            continue;
//        }
//        for (tok_idx = 0; tok_idx < strlen; tok_idx++) {
//            wrkstr = lstr_splt.Item(tok_idx);
        line_idx++;
//
    }
    file.Close();
    num_of_lines = (int) all_inv_lines->GetCount();

}

void InventoryDocument::FindStockItems() {
//    for (int i = 0; i < num_of_lines; i ++) {
//        lStr.Printf("%s\n", all_inv_lines->inv_line((size_t) i));
//        (*MainEditBox) << lStr;

//            line_idx = stockItem->SetFirst(i);

//            i = (int) line_idx;

//    }

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

