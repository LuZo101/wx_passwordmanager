#include "wx_pch.h"
#include "wx_showPasswordDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(wx_showPasswordDialog)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(wx_showPasswordDialog)
//*)

//(*IdInit(wx_showPasswordDialog)
const long wx_showPasswordDialog::ID_STATICTEXT1 = wxNewId();
const long wx_showPasswordDialog::ID_TEXTCTRL1 = wxNewId();
const long wx_showPasswordDialog::ID_STATICTEXT2 = wxNewId();
const long wx_showPasswordDialog::ID_TEXTCTRL2 = wxNewId();
const long wx_showPasswordDialog::ID_STATICTEXT3 = wxNewId();
const long wx_showPasswordDialog::ID_TEXTCTRL3 = wxNewId();
const long wx_showPasswordDialog::ID_STATICTEXT4 = wxNewId();
const long wx_showPasswordDialog::ID_TEXTCTRL4 = wxNewId();
const long wx_showPasswordDialog::ID_STATICTEXT5 = wxNewId();
const long wx_showPasswordDialog::ID_TEXTCTRL5 = wxNewId();
const long wx_showPasswordDialog::ID_BUTTON1 = wxNewId();
const long wx_showPasswordDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wx_showPasswordDialog,wxDialog)
	//(*EventTable(wx_showPasswordDialog)
	//*)
END_EVENT_TABLE()

wx_showPasswordDialog::wx_showPasswordDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wx_showPasswordDialog)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Show Password"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Titel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlTitle = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Titel"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(TextCtrlTitle, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Username"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlUsername = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Username"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(TextCtrlUsername, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("URL"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("URL"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(TextCtrl3, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Note"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlNote = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("Note"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer1->Add(TextCtrlNote, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlPassword = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("Password"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	FlexGridSizer1->Add(TextCtrlPassword, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	BtnClose = new wxButton(Panel1, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(BtnClose, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(StaticBoxSizer1);
	StaticBoxSizer1->Fit(Panel1);
	StaticBoxSizer1->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_showPasswordDialog::OnBtnCloseClick);
	//*)
}

wx_showPasswordDialog::~wx_showPasswordDialog()
{
	//(*Destroy(wx_showPasswordDialog)
	//*)
}

void wx_showPasswordDialog::OnBtnCloseClick(wxCommandEvent& event)
{
    Close();
}
