//
// Created by Chris Hanagan on 9/14/18.
//

#include <wx/wx.h>
#include "InvStockItem.h"
#include "Inventory.h"

InvStockItem::InvStockItem(Inventory *inv_lines) {
    inventory = inv_lines;

}

size_t InvStockItem::SetFirst(size_t line_idx) {
    wxArrayString line_parts;
    wxString string_idx, temp_string;
    size_t wrk_idx = line_idx;
    size_t strlen, lines_used;
    int loop_idx = 0;
    lines_used = 0;

    line_in = inventory->inv_line(wrk_idx);

    line_parts = wxSplit(line_in, ' ');
    strlen = line_parts.Count();

    if (line_parts[0] == "(LIN)") {
        temp_string = line_parts[1];
        lines_used ++;
    }

    string_idx = "none";
    do {
        line_parts = wxSplit(inventory->inv_line(wrk_idx++), ' ');
        string_idx = line_parts[0];
        if (string_idx == "(LIN)") {
            lin = string_idx;
        }
        if (string_idx == "(MPO") {
            mpo = string_idx;
        }
        if (string_idx == "(NOM)") {
            nomen = string_idx;
        }
        if (string_idx == "(MATNR)") {
            niin = string_idx;
        }
        if (string_idx == "(QTY)") {
            quantity = string_idx;
        }
        lines_used ++;
    } while (string_idx != "(LIN)");

//    wrk_idx += lines_used;
//
//            if (line_parts.Item(0).Cmp("FE:")) {
//                continue;
//            }



    return wrk_idx;
}
