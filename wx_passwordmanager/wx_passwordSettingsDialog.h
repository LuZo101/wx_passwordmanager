#ifndef WX_PASSWORDSETTINGSDIALOG_H
#define WX_PASSWORDSETTINGSDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(wx_passwordSettingsDialog)
	#include <wx/button.h>
	#include <wx/checkbox.h>
	#include <wx/dialog.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	#include <wx/textctrl.h>
	//*)
#endif
//(*Headers(wx_passwordSettingsDialog)
//*)

class wx_passwordSettingsDialog: public wxDialog
{
	public:

		wx_passwordSettingsDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);

		virtual ~wx_passwordSettingsDialog();

		//(*Declarations(wx_passwordSettingsDialog)
		wxButton* BtnCancel;
		wxButton* BtnGeneratePW;
		wxButton* BtnSave;
		wxCheckBox* CheckBox123;
		wxCheckBox* CheckBoxABC;
		wxCheckBox* CheckBoxSPEZ;
		wxPanel* Panel1;
		wxTextCtrl* TextCtrlPassword;
		wxTextCtrl* TextCtrlPwLength;
		//*)

	protected:

		//(*Identifiers(wx_passwordSettingsDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(wx_passwordSettingsDialog)
		void OnButton5Click(wxCommandEvent& event);
		void OnCheckBox2Click(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnBtnCancelClick(wxCommandEvent& event);
		void OnBtnGeneratePWClick(wxCommandEvent& event);
		void OnBtnSaveClick(wxCommandEvent& event);
		void OnTextCtrlPwLengthText(wxCommandEvent& event);
		void OnCheckBoxABCClick(wxCommandEvent& event);
		void OnCheckBox123Click(wxCommandEvent& event);
		void OnCheckBoxSPEZClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
