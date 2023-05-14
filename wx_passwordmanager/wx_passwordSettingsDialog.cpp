#include "wx_pch.h"
#include "wx_passwordSettingsDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(wx_passwordSettingsDialog)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(wx_passwordSettingsDialog)
//*)

//(*IdInit(wx_passwordSettingsDialog)
const long wx_passwordSettingsDialog::ID_TEXTCTRL1 = wxNewId();
const long wx_passwordSettingsDialog::ID_CHECKBOX1 = wxNewId();
const long wx_passwordSettingsDialog::ID_CHECKBOX3 = wxNewId();
const long wx_passwordSettingsDialog::ID_CHECKBOX2 = wxNewId();
const long wx_passwordSettingsDialog::ID_TEXTCTRL2 = wxNewId();
const long wx_passwordSettingsDialog::ID_BUTTON5 = wxNewId();
const long wx_passwordSettingsDialog::ID_BUTTON6 = wxNewId();
const long wx_passwordSettingsDialog::ID_BUTTON1 = wxNewId();
const long wx_passwordSettingsDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wx_passwordSettingsDialog,wxDialog)
	//(*EventTable(wx_passwordSettingsDialog)
	//*)
END_EVENT_TABLE()

wx_passwordSettingsDialog::wx_passwordSettingsDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(wx_passwordSettingsDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Password Settings"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	TextCtrlPassword = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Password"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(TextCtrlPassword, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 4, 0, 0);
	CheckBoxSPEZ = new wxCheckBox(Panel1, ID_CHECKBOX1, _("@\?!"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBoxSPEZ->SetValue(false);
	FlexGridSizer2->Add(CheckBoxSPEZ, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBox123 = new wxCheckBox(Panel1, ID_CHECKBOX3, _("123"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	CheckBox123->SetValue(false);
	FlexGridSizer2->Add(CheckBox123, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckBoxABC = new wxCheckBox(Panel1, ID_CHECKBOX2, _("ABC"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckBoxABC->SetValue(false);
	FlexGridSizer2->Add(CheckBoxABC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlPwLength = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Length"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer2->Add(TextCtrlPwLength, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer2, 0, wxALL|wxEXPAND, 0);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BtnSave = new wxButton(Panel1, ID_BUTTON5, _("save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer2->Add(BtnSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BtnGeneratePW = new wxButton(Panel1, ID_BUTTON6, _("generate"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	BoxSizer2->Add(BtnGeneratePW, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BtnCancel = new wxButton(Panel1, ID_BUTTON1, _("cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(BtnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 0);
	Panel1->SetSizer(StaticBoxSizer1);
	StaticBoxSizer1->Fit(Panel1);
	StaticBoxSizer1->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wx_passwordSettingsDialog::OnCheckBoxSPEZClick);
	Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wx_passwordSettingsDialog::OnCheckBox123Click);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&wx_passwordSettingsDialog::OnCheckBoxABCClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordSettingsDialog::OnBtnSaveClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordSettingsDialog::OnBtnGeneratePWClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordSettingsDialog::OnBtnCancelClick);
	//*)
}

wx_passwordSettingsDialog::~wx_passwordSettingsDialog()
{
	//(*Destroy(wx_passwordSettingsDialog)
	//*)
}



void wx_passwordSettingsDialog::OnBtnCancelClick(wxCommandEvent& event)
{
    Close();
}

void wx_passwordSettingsDialog::OnBtnGeneratePWClick(wxCommandEvent& event)
{
}

void wx_passwordSettingsDialog::OnBtnSaveClick(wxCommandEvent& event)
{
}


void wx_passwordSettingsDialog::OnCheckBoxABCClick(wxCommandEvent& event)
{
}

void wx_passwordSettingsDialog::OnCheckBox123Click(wxCommandEvent& event)
{
}

void wx_passwordSettingsDialog::OnCheckBoxSPEZClick(wxCommandEvent& event)
{
}
