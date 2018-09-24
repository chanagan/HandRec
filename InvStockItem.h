//
// Created by Chris Hanagan on 9/14/18.
//

#ifndef HANDREC_INVSTOCKITEM_H
#define HANDREC_INVSTOCKITEM_H

#include <wx/wx.h>
#include "InventoryDocument.h"


class InvStockItem {
    size_t nsn_idx;     // index of this nsn in the document
    bool hasSerNums;
    wxString line_in;
    wxString lin;
    wxString mpo;
    wxString nomen;
    wxString quantity;
    wxString nsn;

public:

    InvStockItem(wxString nsn_in, size_t lin_idx);

    size_t SetItem(size_t);
    wxString getNsn() { return nsn;};
    wxString getString();

};


#endif //HANDREC_INVSTOCKITEM_H
