//
// Created by Chris Hanagan on 9/14/18.
//

#ifndef HANDREC_INVSTOCKITEM_H
#define HANDREC_INVSTOCKITEM_H

#include <wx/wx.h>
#include "InventoryDocument.h"

WX_DECLARE_OBJARRAY(size_t, ArrayOfMatnr);


class InvStockItem {
    size_t nsn_idx;     // index of this nsn in the document
    InventoryDocument* inventory;
    wxString line_in;
    wxString lin;
    wxString mpo;
    wxString nomen;
    wxString quantity;
    wxString nsn;
    ArrayOfMatnr list;

public:

     InvStockItem(wxString  nsn_in, size_t lin_idx) ;
    size_t SetFirst(size_t);
    void SetNSN(wxString input);

};



#endif //HANDREC_INVSTOCKITEM_H
