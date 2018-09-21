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
    CreateStatusBar(2);
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
    MenuFile->Append(MENU_Quit, wxT("&Quit"),
                     wxT("Quit the editor"));

    MainMenu->Append(MenuFile, wxT("File"));
    SetMenuBar(MainMenu);

    MainEditBox = new wxTextCtrl(this, TEXT_Main, "",
                                 wxDefaultPosition, wxDefaultSize,
                                 wxTE_MULTILINE | wxTE_RICH,
                                 wxDefaultValidator, wxTextCtrlNameStr);
//    Maximize();
}

void MainFrame::NewFile(wxCommandEvent & WXUNUSED(event)) {

}

void MainFrame::OpenFile(wxCommandEvent &event) {
    InventoryDocument *inventory = new InventoryDocument();
    wxString lStr;
    int number_lines;
//    InvStockItem * stockItem;

    wxFileDialog *OpenDialog = new wxFileDialog(
            this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
            _("Text files (*.txt)|*.txt|"
              "C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx|"
              "C Source files (*.c)|*.c|"
              "C header files (*.h)|*.h"),
            wxFD_OPEN, wxDefaultPosition);

    if (OpenDialog->ShowModal() == wxID_OK) {

        wxArrayString lstr_splt;
        wxString wrkstr;
        size_t strlen;
        size_t line_idx;
        int num_lines;

        CurrentDocPath = OpenDialog->GetPath();
        SetTitle(wxString("Edit - ") << OpenDialog->GetFilename());

        inventory->LoadInventory(CurrentDocPath);
        num_lines = (int) inventory->line_count();

        lStr.Printf(wxT("Document Number: %s\n"), inventory->inv_doc_num());
        (*MainEditBox) << lStr;
        lStr.Printf(wxT("Document Date: %s\n"), inventory->inv_doc_date());
        (*MainEditBox) << lStr;
        lStr.Printf(wxT("Number of lines: %d\n\n"), num_lines);
        (*MainEditBox) << lStr;

//        stockItem = new InvStockItem(inventory);
        for (int i = 0; i < num_lines; i ++) {
            lStr.Printf("%s\n", inventory->inv_line((size_t) i));
            (*MainEditBox) << lStr;

//            line_idx = stockItem->SetFirst(i);

//            i = (int) line_idx;

        }
// TODO invdoc => list of stock_items - not stock_items list of matnr indexes
//        wxTextFile file(CurrentDocPath);
//        file.Open();
//        size_t fileNums;
//        fileNums = file.GetLineCount();
//        lStr.Printf(wxT("Number of lines: %d\n"), (int) file.GetLineCount());
//        (*MainEditBox) << lStr;
//        lStr.Printf(wxT("First line: >%s<\n"), file.GetFirstLine().c_str());
//        (*MainEditBox) << lStr;
//        lStr.Printf(wxT("Last Line: >%s<\n\n"), file.GetLastLine().c_str());
//        (*MainEditBox) << lStr;
//
//        for (lStr = file.GetFirstLine(); !file.Eof(); lStr = file.GetNextLine()) {
//            if (lStr.IsEmpty()) {
//                continue;
//            }
//            (*MainEditBox) << lStr << "\n";
//
//            lstr_splt = wxSplit(lStr, ' ');
//            strlen = lstr_splt.Count();
//
//            if (lstr_splt.Item(0).Cmp("FE:")) {
//                continue;
//            }
//            for (line_idx = 0; line_idx < strlen; line_idx++) {
//                wrkstr = lstr_splt.Item(line_idx);
//
//            }
//
//        }
//        MainEditBox->LoadFile(CurrentDocPath);

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