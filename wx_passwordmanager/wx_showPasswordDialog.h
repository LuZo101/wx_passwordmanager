#ifndef WX_SHOWPASSWORDDIALOG_H
#define WX_SHOWPASSWORDDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(wx_showPasswordDialog)
	#include <wx/button.h>
	#include <wx/dialog.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	//*)
#endif
//(*Headers(wx_showPasswordDialog)
//*)

class wx_showPasswordDialog: public wxDialog
{
	public:

		wx_showPasswordDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wx_showPasswordDialog();

		//(*Declarations(wx_showPasswordDialog)
		wxButton* BtnClose;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrlNote;
		wxTextCtrl* TextCtrlPassword;
		wxTextCtrl* TextCtrlTitle;
		wxTextCtrl* TextCtrlUsername;
		//*)

	protected:

		//(*Identifiers(wx_showPasswordDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(wx_showPasswordDialog)
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnBtnCloseClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
