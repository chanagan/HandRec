//
// Created by Chris Hanagan on 8/25/18.
//

#ifndef FIRST_WX_APP_MAIN_H
#define FIRST_WX_APP_MAIN_H

#include <wx/wx.h>

class MainApp : public wxApp {

public:
    virtual bool OnInit();
};
DECLARE_APP(MainApp)

#endif //FIRST_WX_APP_MAIN_H
