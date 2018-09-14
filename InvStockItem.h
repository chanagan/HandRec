//
// Created by Chris Hanagan on 9/14/18.
//

#ifndef HANDREC_INVSTOCKITEM_H
#define HANDREC_INVSTOCKITEM_H

#include <wx/wx.h>
#include "Inventory.h"

class InvStockItem {
    Inventory* inventory;
    wxString line_in;
    wxString lin;
    wxString mpo;
    wxString nomen;
    wxString quantity;
    wxString niin;
public:

    explicit InvStockItem(Inventory*  );
    size_t SetFirst(size_t);

};



#endif //HANDREC_INVSTOCKITEM_H
