//
// Created by Chris Hanagan on 8/26/18.
//
#include <wx/textfile.h>
#include <wx/arrstr.h>
#include "MainFrame.h"
#include "InventoryDocument.h"
//#include "InvStockItem.h"

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame((wxFrame *) NULL, -1, title, pos, size) {
  MainMenu = new wxMenuBar();
  wxMenu *MenuFile = new wxMenu();

  MenuFile->Append(MENU_New, wxT("&New"),
                   wxT("Create a new file"));
  MenuFile->Append(MENU_Open, wxT("&Open"),
                   wxT("Open an existing File"));
  MenuFile->Append(MENU_Quit, wxT("&Close"),
                   wxT("Close the current document"));
  MenuFile->Append(MENU_Save, wxT("&Save"),
                   wxT("Save the current document"));
  MenuFile->Append(MENU_SaveAs, wxT("Save &As"),
                   wxT("Save the current document under a new file name"));

    MenuFile->AppendSeparator();
  MenuFile->Append(wxID_EXIT, wxT("&Quit"),
                   wxT("Quit the editor"));

  MainMenu->Append(MenuFile, wxT("File"));

  wxMenu *Menu = new wxMenu();
  Menu->Append(MENU_INV_Open, _("Load"), _("Load a menu file"));
  MainMenu->Append(Menu, _("Inventory"));

  SetMenuBar(MainMenu);

  sizer = new wxBoxSizer(wxHORIZONTAL);
  gs = new wxGridSizer(4,1,3,3);
  gs->Add(new wxButton(this, -1, wxT("One")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("Two")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("Three")), 0, wxEXPAND);
  gs->Add(new wxButton(this, -1, wxT("Four")), 0, wxEXPAND);

  sizer->Add(gs, 0, wxEXPAND);

  MainEditBox = new wxTextCtrl(this, TEXT_Main, "",
                               wxDefaultPosition, wxDefaultSize,
                               wxTE_MULTILINE | wxTE_RICH,
                               wxDefaultValidator, wxTextCtrlNameStr);
  sizer->Add(MainEditBox, 1, wxEXPAND | wxTOP | wxBOTTOM);
  SetSizer(sizer);
  SetMinSize(wxSize(270, 220));

  CreateStatusBar(2);
  SetStatusText(_("Here we are"), 1);

  Bind(wxEVT_MENU, &MainFrame::Quit, this, wxID_EXIT);
  Bind(wxEVT_MENU, &MainFrame::OpenFile, this, MENU_INV_Open);
//    Maximize();
}

void MainFrame::NewFile(wxCommandEvent & WXUNUSED(event)) {

}

void MainFrame::OpenFile(wxCommandEvent &event) {
  InventoryDocument *inventory = new InventoryDocument();
  InvStockItem *tmp_nsn_item;
  wxString lStr;
  int number_lines;
  bool got_file = false;
//    InvStockItem * stockItem;
  wxArrayString lstr_splt;
  wxString wrkstr;
  size_t strlen;
  size_t line_idx;
  int num_lines;
  int num_nsn;

  wxFileDialog *OpenDialog = new wxFileDialog(
      this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
      _("Text files (*.txt)|*.txt|"
        "C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx|"
        "C Source files (*.c)|*.c|"
        "C header files (*.h)|*.h"),
      wxFD_OPEN, wxDefaultPosition);

  if (OpenDialog->ShowModal()==wxID_OK) {

    CurrentDocPath = OpenDialog->GetPath();
    SetTitle(wxString("Edit - ") << OpenDialog->GetFilename());
    got_file = true;
  }
  if (got_file) {

    // load the inventory document
    inventory->LoadInventory(CurrentDocPath);

    num_lines = (int) inventory->line_count();
    num_nsn = (int) inventory->nsn_count();

    lStr.Printf(wxT("Document Number: %s\n"), inventory->inv_doc_num());
    SetStatusText(lStr, 0);
    (*MainEditBox) << lStr;

    lStr.Printf(wxT("Document Date: %s\n"), inventory->inv_doc_date());
    SetStatusText(lStr, 1);
    (*MainEditBox) << lStr;

    lStr.Printf(wxT("Number of lines: %d\n\n"), num_lines);
    (*MainEditBox) << lStr;
    lStr.Printf(wxT("Number of NSN Items: %d\n\n"), num_nsn);
    (*MainEditBox) << lStr;


    // display each line
    if (false) {
      for (int i = 0; i < num_lines; i++) {
        lStr.Printf("%s\n", inventory->inv_line((size_t) i));
        (*MainEditBox) << lStr;
      }

    }

    // display each nsn item
    for (int i = 0; i < num_nsn; i++) {
      tmp_nsn_item = inventory->nsn_item((size_t) i);
      lStr.Printf(wxT("%d: %s\n"), i, tmp_nsn_item->getString());
//            lStr.format("%d: %s\n", i, tmp_nsn_item->getString());
      (*MainEditBox) << lStr;
    }
// TODO invdoc => list of stock_items - not stock_items list of matnr indexes
  }

}

void MainFrame::CloseFile(wxCommandEvent &event) {
  MainEditBox->Clear();
}

void MainFrame::SaveFile(wxCommandEvent &event) {
}

void MainFrame::SaveFileAs(wxCommandEvent &event) {

}

void MainFrame::Quit(wxCommandEvent & WXUNUSED(event)) {
  Close(TRUE);
}