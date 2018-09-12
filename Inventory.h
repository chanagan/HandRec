//
// Created by Chris Hanagan on 9/8/18.
//

#ifndef HANDREC_INVENTORY_H
#define HANDREC_INVENTORY_H

#include <wx/wx.h>

class Inventory {
    wxString CurrentDocPath;
    size_t num_of_lines;
    wxString first_line;
    wxString last_line;
    wxString inv_date;
    wxString inv_num;

    wxArrayString *all_inv_lines;
public:
    void LoadInventory(wxString curr_path);

    size_t line_count() {return num_of_lines;};
    wxString  inv_line(size_t which_line) {return all_inv_lines->Item( which_line);};
    wxString inv_doc_date() { return inv_date;};
    wxString inv_doc_num() { return inv_num;};


    bool is_not_used(wxString  wrk_str);
};



#endif //HANDREC_INVENTORY_H
