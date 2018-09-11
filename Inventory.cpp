//
// Created by Chris Hanagan on 9/8/18.
//
#include <wx/textfile.h>
#include <wx/arrstr.h>

#include "Inventory.h"

void Inventory::LoadInventory(wxString curr_path) {
    CurrentDocPath = curr_path;

    wxTextFile file(CurrentDocPath);
    wxArrayString line_fields;
    file.Open();
    wxString lStr;
    inv_lines = new wxArrayString;
//    size_t fileNums;
//    fileNums = file.GetLineCount();

    num_of_lines = (int) file.GetLineCount();

//    lStr.Printf(wxT("Number of lines: %d\n"), (int) file.GetLineCount());
//    (*MainEditBox) << lStr;
//    lStr.Printf(wxT("First line: >%s<\n"), file.GetFirstLine().c_str());
//    (*MainEditBox) << lStr;
//    lStr.Printf(wxT("Last Line: >%s<\n\n"), file.GetLastLine().c_str());
//    (*MainEditBox) << lStr;
//
    for (lStr = file.GetFirstLine(); !file.Eof(); lStr = file.GetNextLine()) {
        if (is_not_used(lStr)) {
            continue;
        }

        line_fields = wxSplit(lStr, ' ');
        if (line_fields[0] == "(CurrentDate)") {
            inv_date = line_fields[1];
            continue;
        }
        if (line_fields[0] == "(Inv") {
            inv_doc_num = line_fields[3];
            continue;
        }
        inv_lines->Add(lStr);
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
//
    }

//    }
    file.Close();
    num_of_lines = (int) inv_lines->GetCount();

}

bool Inventory::is_not_used(wxString wrk_str) {
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