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
    size_t line_idx = 0;

    InvStockItem *invStockItem;

    wxTextFile file(CurrentDocPath);
    wxArrayString line_fields;
    file.Open();
    wxString lStr;
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
void InventoryDocument::LoadStockItem(size_t) {

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



