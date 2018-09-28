//
// Created by Chris Hanagan on 9/8/18.
//

#ifndef HANDREC_INVENTORY_H
#define HANDREC_INVENTORY_H

#include <wx/wx.h>
#include "InvStockItem.h"

class InvStockItem;

WX_DECLARE_OBJARRAY(InvStockItem, ArrayOfMatnr);

class InventoryDocument {
    wxString CurrentDocPath;
    size_t num_of_lines;
    wxString inv_date;
    wxString inv_num;

    wxArrayString *all_inv_lines;

    ArrayOfMatnr nsn_list;
    void LoadInventoryDocument();
    void LoadInventoryStock();
    void LoadInventorySerials();

    void LoadStockItem(size_t item_num);

public:
    void LoadInventory(wxString curr_path);

    size_t line_count() {return num_of_lines;};
    size_t nsn_count() { return nsn_list.GetCount();};

    wxString  inv_line(size_t which_line) {return all_inv_lines->Item( which_line);};

    InvStockItem* nsn_item(size_t which_item);

//    InvStockItem  nsn_item(size_t which_item) { return (InvStockItem ) nsn_list.Item(which_item);};

    wxString inv_doc_date() { return inv_date;};
    wxString inv_doc_num() { return inv_num;};


    bool is_not_used(wxString  wrk_str);
};



#endif //HANDREC_INVENTORY_H
