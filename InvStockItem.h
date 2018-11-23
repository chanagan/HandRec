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
  int data_first_line;
  int data_line_count;

  wxString lin_;
  wxString mpo;
  wxString nomen;
  wxString quantity;
  wxString nsn;

 public:
  bool isHasSerNums() const {
    return hasSerNums;
  }

  void setHasSerNums(bool hasSerNums) {
    InvStockItem::hasSerNums = hasSerNums;
  }

  int getData_first_line() const {
    return data_first_line;
  }
  void setData_first_line(int data_first_line) {
    InvStockItem::data_first_line = data_first_line;
  }
  int getData_line_count() const {
    return data_line_count;
  }
  void setData_line_count(int data_line_count) {
    InvStockItem::data_line_count = data_line_count;
  }

  const wxString &getLin() const {
    return lin_;
  }

  void setLin(const wxString &lin) {
    InvStockItem::lin_ = lin;
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

  InvStockItem(wxString nsn_in, size_t lin_idx);

  wxString getNsn() { return nsn; };
  wxString getString();

};

#endif //HANDREC_INVSTOCKITEM_H
