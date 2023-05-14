#include "wx_pch.h"
#include "wx_deletePasswordDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(wx_deletePasswordDialog)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(wx_deletePasswordDialog)
//*)

//(*IdInit(wx_deletePasswordDialog)
const long wx_deletePasswordDialog::ID_BUTTON1 = wxNewId();
const long wx_deletePasswordDialog::ID_BUTTON2 = wxNewId();
const long wx_deletePasswordDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wx_deletePasswordDialog,wxDialog)
	//(*EventTable(wx_deletePasswordDialog)
	//*)
END_EVENT_TABLE()

wx_deletePasswordDialog::wx_deletePasswordDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wx_deletePasswordDialog)
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(328,165));
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("YOU REALLY WANT DELETE YOUR PASSWORD\?\?!"));
	BtnYes = new wxButton(Panel1, ID_BUTTON1, _("YES!"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticBoxSizer1->Add(BtnYes, 1, wxALL, 5);
	BtnNo = new wxButton(Panel1, ID_BUTTON2, _("NO!"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	StaticBoxSizer1->Add(BtnNo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(StaticBoxSizer1);
	StaticBoxSizer1->Fit(Panel1);
	StaticBoxSizer1->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_deletePasswordDialog::OnBtnYesClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_deletePasswordDialog::OnBtnNoClick);
	//*)
}

wx_deletePasswordDialog::~wx_deletePasswordDialog()
{
	//(*Destroy(wx_deletePasswordDialog)
	//*)
}


void wx_deletePasswordDialog::OnBtnNoClick(wxCommandEvent& event)
{
    Close();
}

void wx_deletePasswordDialog::OnBtnYesClick(wxCommandEvent& event)
{
    //delete selected PW

}
