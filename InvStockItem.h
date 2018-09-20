//
// Created by Chris Hanagan on 9/14/18.
//

#ifndef HANDREC_INVSTOCKITEM_H
#define HANDREC_INVSTOCKITEM_H

#include <wx/wx.h>
#include "InventoryDocument.h"

WX_DECLARE_OBJARRAY(size_t, ArrayOfMatnr);


class InvStockItem {
    InventoryDocument* inventory;
    wxString line_in;
    wxString lin;
    wxString mpo;
    wxString nomen;
    wxString quantity;
    wxString niin;
    ArrayOfMatnr list;

public:

    explicit InvStockItem(InventoryDocument*  );
    size_t SetFirst(size_t);

};



#endif //HANDREC_INVSTOCKITEM_H
