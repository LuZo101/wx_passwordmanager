#ifndef WX_DELETEPASSWORDDIALOG_H
#define WX_DELETEPASSWORDDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(wx_deletePasswordDialog)
	#include <wx/button.h>
	#include <wx/dialog.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	//*)
#endif
//(*Headers(wx_deletePasswordDialog)
//*)

class wx_deletePasswordDialog: public wxDialog
{
	public:

		wx_deletePasswordDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wx_deletePasswordDialog();

		//(*Declarations(wx_deletePasswordDialog)
		wxButton* BtnNo;
		wxButton* BtnYes;
		wxPanel* Panel1;
		//*)

	protected:

		//(*Identifiers(wx_deletePasswordDialog)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(wx_deletePasswordDialog)
		void OnBtnNoClick(wxCommandEvent& event);
		void OnBtnYesClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
