/***************************************************************
 * Name:      wx_passwordmanagerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Lukas Zorn (lukas.zorn@protonmail.com)
 * Created:   2023-05-11
 * Copyright: Lukas Zorn ()
 * License: MIT License
 **************************************************************/

#ifndef WX_PASSWORDMANAGERMAIN_H
#define WX_PASSWORDMANAGERMAIN_H

//(*Headers(wx_passwordmanagerFrame)
#include <wx/button.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class wx_passwordmanagerFrame: public wxFrame
{
    public:

        wx_passwordmanagerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wx_passwordmanagerFrame();

        //(*Declarations(wx_passwordmanagerFrame)
        wxButton* BtnCreateDb;
        wxButton* Btn_LoginCancel;
        wxButton* Btn_LoginOk;
        wxFilePickerCtrl* FilePickerLoaddB;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrlLoginPassword;
        wxTextCtrl* TextCtrlLoginUser;
        //*)


    protected:

        //(*Identifiers(wx_passwordmanagerFrame)
        static const long ID_PANEL1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_BUTTON3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

    private:

        //(*Handlers(wx_passwordmanagerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnBtn_LoginCancelClick(wxCommandEvent& event);
        void OnBtn_LoginOkClick(wxCommandEvent& event);
        void OnTextCtrlLoginPasswordTextEnter(wxCommandEvent& event);
        void OnFilePickerLoaddBFileChanged(wxFileDirPickerEvent& event);
        void OnBtnCreateDbClick(wxCommandEvent& event);
        //*)

        //(*Declarations(wx_passwordmanagerFrame)
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WX_PASSWORDMANAGERMAIN_H
