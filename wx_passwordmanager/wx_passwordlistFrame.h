#ifndef WX_PASSWORDLISTFRAME_H
#define WX_PASSWORDLISTFRAME_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(wx_passwordlistFrame)
	#include <wx/button.h>
	#include <wx/frame.h>
	#include <wx/listctrl.h>
	#include <wx/panel.h>
	#include <wx/sizer.h>
	//*)
#endif
//(*Headers(wx_passwordlistFrame)
//*)

class wx_passwordlistFrame: public wxFrame
{
	public:

		wx_passwordlistFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~wx_passwordlistFrame();

		//(*Declarations(wx_passwordlistFrame)
		wxButton* BtnCreatePw;
		wxButton* BtnDeletePw;
		wxButton* BtnEditPw;
		wxButton* BtnShowPw;
		wxListView* ListView1;
		wxPanel* Panel1;
		//*)

	protected:

		//(*Identifiers(wx_passwordlistFrame)
		static const long ID_LISTVIEW1;
		static const long ID_PANEL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		//*)

	private:

		//(*Handlers(wx_passwordlistFrame)
		void OnClose(wxCloseEvent& event);
		void OnPanel1Paint(wxPaintEvent& event);
		void OnBtnCreatePwClick(wxCommandEvent& event);
		void OnListView1BeginDrag(wxListEvent& event);
		void OnBtnEditPwClick(wxCommandEvent& event);
		void OnBtnShowPwClick(wxCommandEvent& event);
		void OnBtnDeletePwClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
