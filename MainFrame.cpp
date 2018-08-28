//
// Created by Chris Hanagan on 8/26/18.
//
#include <wx/textfile.h>
#include "MainFrame.h"


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame((wxFrame *) NULL, -1, title, pos, size) {
    CreateStatusBar(2);
    MainMenu = new wxMenuBar();
    wxMenu *FileMenu = new wxMenu();

    FileMenu->Append(MENU_New, wxT("&New"),
                     wxT("Create a new file"));
    FileMenu->Append(MENU_Open, wxT("&Open"),
                     wxT("Open an existing File"));
    FileMenu->Append(MENU_Quit, wxT("&Close"),
                     wxT("Close the current document"));
    FileMenu->Append(MENU_Save, wxT("&Save"),
                     wxT("Save the current document"));
    FileMenu->Append(MENU_SaveAs, wxT("Save &As"),
                     wxT("Save the current document under a new file name"));
    FileMenu->Append(MENU_Quit, wxT("&Quit"),
                     wxT("Quit the editor"));

    MainMenu->Append(FileMenu, wxT("File"));
    SetMenuBar(MainMenu);

    MainEditBox = new wxTextCtrl(this, TEXT_Main, "",
                                 wxDefaultPosition, wxDefaultSize,
                                 wxTE_MULTILINE | wxTE_RICH,
                                 wxDefaultValidator, wxTextCtrlNameStr);
//    Maximize();
}

void MainFrame::NewFile(wxCommandEvent & WXUNUSED(event)){

}

void MainFrame::OpenFile(wxCommandEvent &event) {
    wxFileDialog *OpenDialog = new wxFileDialog(
            this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
            _("Text files (*.txt)|*.txt|"
              "C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx|"
              "C Source files (*.c)|*.c|"
              "C header files (*.h)|*.h"),
            wxFD_OPEN, wxDefaultPosition);

    if (OpenDialog->ShowModal() == wxID_OK)
    {
        CurrentDocPath = OpenDialog->GetPath();
        SetTitle(wxString("Edit - " ) << OpenDialog->GetFilename());
        wxTextFile file(CurrentDocPath);
        file.Open();
        wxString lStr;
        size_t fileNums;
        fileNums = file.GetLineCount();
        lStr.Printf(wxT("Number of lines: %d\n"), (int)file.GetLineCount());
        (*MainEditBox) << lStr;
        lStr.Printf(wxT("First line: >%s<\n"), file.GetFirstLine().c_str());
        (*MainEditBox) << lStr;
        lStr.Printf(wxT("Last Line: >%s<\n\n"), file.GetLastLine().c_str());
        (*MainEditBox) << lStr;

        for (lStr = file.GetFirstLine(); !file.Eof() ; lStr = file.GetNextLine()) {
            if (lStr.IsEmpty()) {
                continue;
            }
            (*MainEditBox) << lStr << "\n";
        }
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

void MainFrame::Quit(wxCommandEvent& WXUNUSED(event)) {
    Close(TRUE);
}