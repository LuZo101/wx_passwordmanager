#ifndef WX_CREATEPASSWORDDIALOG_H
#define WX_CREATEPASSWORDDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(wx_createPasswordDialog)
	#include <wx/button.h>
	#include <wx/dialog.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	#include <wx/stattext.h>
	#include <wx/textctrl.h>
	//*)
#endif
//(*Headers(wx_createPasswordDialog)
//*)

class wx_createPasswordDialog: public wxDialog
{
	public:

		wx_createPasswordDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wx_createPasswordDialog();

		//(*Declarations(wx_createPasswordDialog)
		wxButton* BtnCancel;
		wxButton* BtnGeneratePw;
		wxButton* BtnPasswordSettings;
		wxButton* BtnSave;
		wxPanel* Panel1;
		wxStaticText* StaticTextNote;
		wxStaticText* StaticTextPassword;
		wxStaticText* StaticTextTitle;
		wxStaticText* StaticTextURL;
		wxStaticText* StaticTextUsername;
		wxTextCtrl* TextCtrlNote;
		wxTextCtrl* TextCtrlPassword;
		wxTextCtrl* TextCtrlTitle;
		wxTextCtrl* TextCtrlURL;
		wxTextCtrl* TextCtrlUsername;
		//*)

	protected:

		//(*Identifiers(wx_createPasswordDialog)
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
		static const long ID_BUTTON2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(wx_createPasswordDialog)
		void OnInit(wxInitDialogEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnBtnGeneratePwClick(wxCommandEvent& event);
		void OnBtnSaveClick(wxCommandEvent& event);
		void OnBtnCancelClick(wxCommandEvent& event);
		void OnBtnPasswordSettingsClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
