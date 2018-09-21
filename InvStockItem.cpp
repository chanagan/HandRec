//
// Created by Chris Hanagan on 9/14/18.
//

#include <wx/wx.h>
#include <wx/listimpl.cpp>
#include "InvStockItem.h"
#include "InventoryDocument.h"

//#include <wx/arrimpl.cpp>
//WX_DEFINE_OBJARRAY(ArrayOfMatnr);



InvStockItem::InvStockItem(wxString in_nsn, size_t lin_idx) {
    nsn = in_nsn;
    nsn_idx = lin_idx;

}

size_t InvStockItem::SetFirst(size_t line_idx) {

    wxArrayString line_parts;
    wxString string_idx, temp_string;
//    size_t inpt_count = inventory->line_count();
    size_t wrk_idx = line_idx;
    size_t strlen, lines_used;
    int loop_idx = 0;
    lines_used = 0;

//    line_in = inventory->inv_line(wrk_idx);
//    item_list = new wxList<size_t>();


    line_parts = wxSplit(line_in, ' ');
    strlen = line_parts.Count();

    if (line_parts[0] == "(LIN)") {
        temp_string = line_parts[1];
        lines_used ++;
    }

    string_idx = "none";
//    do {
//        line_parts = wxSplit(inventory->inv_line(wrk_idx++), ' ');
//        string_idx = line_parts[0];
//        if (string_idx == "(LIN)") {
//            lin = string_idx;
//        }
//        if (string_idx == "(MPO") {
//            mpo = string_idx;
//        }
//        if (string_idx == "(NOM)") {
//            nomen = string_idx;
//        }
//        if (string_idx == "(MATNR)") {
//            size_t this_item = wrk_idx;
////            list.Add(&this_item);
//
//            nsn = string_idx;
//        }
//        if (string_idx == "(QTY)") {
//            quantity = string_idx;
//        }
//        lines_used ++;
//    } while (string_idx != "(LIN)" && wrk_idx < inpt_count);

//    wrk_idx += lines_used;
//
//            if (line_parts.Item(0).Cmp("FE:")) {
//                continue;
//            }



    return --wrk_idx;
}

void InvStockItem::SetNSN(wxString input) {
    nsn = input;

}
