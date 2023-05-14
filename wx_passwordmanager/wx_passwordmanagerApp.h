/***************************************************************
 * Name:      wx_passwordmanagerApp.h
 * Purpose:   Defines Application Class
 * Author:    Lukas Zorn (lukas.zorn@protonmail.com)
 * Created:   2023-05-11
 * Copyright: Lukas Zorn ()
 * License:
 **************************************************************/

#ifndef WX_PASSWORDMANAGERAPP_H
#define WX_PASSWORDMANAGERAPP_H

#include <wx/app.h>

class wx_passwordmanagerApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WX_PASSWORDMANAGERAPP_H
