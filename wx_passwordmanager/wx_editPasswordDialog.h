#ifndef WX_EDITPASSWORDDIALOG_H
#define WX_EDITPASSWORDDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(wx_editPasswordDialog)
	#include <wx/button.h>
	#include <wx/dialog.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	//*)
#endif
//(*Headers(wx_editPasswordDialog)
//*)

class wx_editPasswordDialog: public wxDialog
{
	public:

		wx_editPasswordDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wx_editPasswordDialog();

		//(*Declarations(wx_editPasswordDialog)
		wxButton* BtnCancel;
		wxButton* BtnGeneratePW;
		wxButton* BtnPasswordSettings;
		wxButton* BtnSave;
		wxPanel* Panel1;
		wxStaticText* StaticTextNote;
		wxStaticText* StaticTextPassword;
		wxStaticText* StaticTextTitel;
		wxStaticText* StaticTextURL;
		wxStaticText* StaticTextUsername;
		wxTextCtrl* TextCtrlNote;
		wxTextCtrl* TextCtrlPassword;
		wxTextCtrl* TextCtrlTitel;
		wxTextCtrl* TextCtrlURL;
		wxTextCtrl* TextCtrlUsername;
		//*)

	protected:

		//(*Identifiers(wx_editPasswordDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(wx_editPasswordDialog)
		void OnInit(wxInitDialogEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnBtnGeneratePWClick(wxCommandEvent& event);
		void OnBtnPasswordSettingsClick(wxCommandEvent& event);
		void OnBtnCancelClick(wxCommandEvent& event);
		void OnBtnSaveClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
