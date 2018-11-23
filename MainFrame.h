//
// Created by Chris Hanagan on 8/26/18.
//

#ifndef FIRST_WX_APP_MAINFRAME_H
#define FIRST_WX_APP_MAINFRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame {
 public:
  MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

//    wxButton *HelloWorld;
  wxBoxSizer *sizer;
  wxGridSizer *gs;

  wxTextCtrl *MainEditBox;
  wxMenuBar *MainMenu;
  wxString CurrentDocPath;

  void Quit(wxCommandEvent &event);

  void NewFile(wxCommandEvent &event);

  void OpenFile(wxCommandEvent &event);

  void SaveFile(wxCommandEvent &event);

  void SaveFileAs(wxCommandEvent &event);

  void CloseFile(wxCommandEvent &event);

//    void OnExit(wxCommandEvent &event);

 DECLARE_EVENT_TABLE()
};

enum {
  TEXT_Main = wxID_HIGHEST + 1,
  MENU_New,
  MENU_Open,
  MENU_Save,
  MENU_SaveAs,
  MENU_Quit
};

#endif //FIRST_WX_APP_MAINFRAME_H
