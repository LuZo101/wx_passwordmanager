/***************************************************************
 * Name:      wx_passwordmanagerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Lukas Zorn (lukas.zorn@protonmail.com)
 * Created:   2023-05-11
 * Copyright: Lukas Zorn ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wx_passwordmanagerApp.h"

//(*AppHeaders
#include "wx_passwordmanagerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wx_passwordmanagerApp);

bool wx_passwordmanagerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wx_passwordmanagerFrame* Frame = new wx_passwordmanagerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
