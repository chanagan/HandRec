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

    hasSerNums = false;
    data_first_line = 0;
    data_line_count = 0;
}

wxString InvStockItem::getString() {
    wxString tmpString;
//    tmpString.Printf("%d: %s\n", nsn_idx, nsn.mb_str());
//    tmpString.Printf(wxT("%d: %s"), (int) nsn_idx, nsn);
    tmpString.Printf(wxT("%d: lin_: %s - mpo: %s - nsn: %s - qty: %s - dta: %d - nomen: %s"),
                     (int) nsn_idx, lin_, mpo, nsn, quantity, hasSerNums, nomen);
    tmpString.Printf(wxT("nsn: %s - qty: %s - dta: %d - nomen: %s - dta line / count %d / %d"),
                     nsn, quantity, hasSerNums, nomen, data_first_line, data_line_count);


    return tmpString;
}
