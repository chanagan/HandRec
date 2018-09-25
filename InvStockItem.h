//
// Created by Chris Hanagan on 9/14/18.
//

#ifndef HANDREC_INVSTOCKITEM_H
#define HANDREC_INVSTOCKITEM_H

#include <wx/wx.h>
#include "InventoryDocument.h"


class InvStockItem {
    size_t nsn_idx;
public:
    size_t getNsn_idx() const {
        return nsn_idx;
    }

private:
    // index of this nsn in the document
    bool hasSerNums;
    wxString line_in;
public:
    bool isHasSerNums() const {
        return hasSerNums;
    }

    void setHasSerNums(bool hasSerNums) {
        InvStockItem::hasSerNums = hasSerNums;
    }

    const wxString &getLin() const {
        return lin;
    }

    void setLin(const wxString &lin) {
        InvStockItem::lin = lin;
    }

    const wxString &getMpo() const {
        return mpo;
    }

    void setMpo(const wxString &mpo) {
        InvStockItem::mpo = mpo;
    }

    const wxString &getNomen() const {
        return nomen;
    }

    void setNomen(const wxString &nomen) {
        InvStockItem::nomen = nomen;
    }

    const wxString &getQuantity() const {
        return quantity;
    }

    void setQuantity(const wxString &quantity) {
        InvStockItem::quantity = quantity;
    }

private:
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
