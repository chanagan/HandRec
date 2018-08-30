#include "main.h"
#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
                EVT_MENU(MENU_New, MainFrame::NewFile)
                EVT_MENU(MENU_Open, MainFrame::OpenFile)
                EVT_MENU(MENU_Quit, MainFrame::CloseFile)
                EVT_MENU(MENU_Save, MainFrame::SaveFile)
                EVT_MENU(MENU_SaveAs, MainFrame::SaveFileAs)
                EVT_MENU(MENU_Quit, MainFrame::Quit)
END_EVENT_TABLE()

IMPLEMENT_APP(MainApp)

bool MainApp::OnInit() {
    MainFrame *MainWin = new MainFrame(_("Hand Receipt Holder"),
                                       wxDefaultPosition, wxSize(900, 600));
    MainWin->Show(true);
    SetTopWindow(MainWin);

    return true;

}

