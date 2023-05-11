#include "wx_pch.h"
#include "wx_createPasswordDialog.h"
#include "wx_passwordSettingsDialog.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(wx_createPasswordDialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#endif
//(*InternalHeaders(wx_createPasswordDialog)
//*)

//(*IdInit(wx_createPasswordDialog)
const long wx_createPasswordDialog::ID_STATICTEXT1 = wxNewId();
const long wx_createPasswordDialog::ID_TEXTCTRL1 = wxNewId();
const long wx_createPasswordDialog::ID_STATICTEXT2 = wxNewId();
const long wx_createPasswordDialog::ID_TEXTCTRL2 = wxNewId();
const long wx_createPasswordDialog::ID_STATICTEXT3 = wxNewId();
const long wx_createPasswordDialog::ID_TEXTCTRL3 = wxNewId();
const long wx_createPasswordDialog::ID_STATICTEXT4 = wxNewId();
const long wx_createPasswordDialog::ID_TEXTCTRL4 = wxNewId();
const long wx_createPasswordDialog::ID_STATICTEXT5 = wxNewId();
const long wx_createPasswordDialog::ID_TEXTCTRL5 = wxNewId();
const long wx_createPasswordDialog::ID_BUTTON2 = wxNewId();
const long wx_createPasswordDialog::ID_BUTTON1 = wxNewId();
const long wx_createPasswordDialog::ID_BUTTON3 = wxNewId();
const long wx_createPasswordDialog::ID_BUTTON4 = wxNewId();
const long wx_createPasswordDialog::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wx_createPasswordDialog,wxDialog)
    //(*EventTable(wx_createPasswordDialog)
    //*)
END_EVENT_TABLE()

wx_createPasswordDialog::wx_createPasswordDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(wx_createPasswordDialog)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel1, _("Create a password"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    StaticTextTitle = new wxStaticText(Panel1, ID_STATICTEXT1, _("Titel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticTextTitle, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlTitle = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Title"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(TextCtrlTitle, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextUsername = new wxStaticText(Panel1, ID_STATICTEXT2, _("Username"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticTextUsername, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlUsername = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Username"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrlUsername, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextURL = new wxStaticText(Panel1, ID_STATICTEXT3, _("URL"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(StaticTextURL, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlURL = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("URL"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(TextCtrlURL, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextNote = new wxStaticText(Panel1, ID_STATICTEXT4, _("Note"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticTextNote, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlNote = new wxTextCtrl(Panel1, ID_TEXTCTRL4, _("Note"), wxDefaultPosition, wxSize(200,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer1->Add(TextCtrlNote, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticTextPassword = new wxStaticText(Panel1, ID_STATICTEXT5, _("Password"), wxDefaultPosition, wxSize(173,17), 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticTextPassword, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 4, 0, 0);
    TextCtrlPassword = new wxTextCtrl(Panel1, ID_TEXTCTRL5, _("Text"), wxDefaultPosition, wxSize(220,34), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    FlexGridSizer2->Add(TextCtrlPassword, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnGeneratePw = new wxButton(Panel1, ID_BUTTON2, _("gen"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer2->Add(BtnGeneratePw, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnPasswordSettings = new wxButton(Panel1, ID_BUTTON1, _("options"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(BtnPasswordSettings, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BtnSave = new wxButton(Panel1, ID_BUTTON3, _("save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(BtnSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnCancel = new wxButton(Panel1, ID_BUTTON4, _("cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer2->Add(BtnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 0);
    Panel1->SetSizer(StaticBoxSizer1);
    StaticBoxSizer1->Fit(Panel1);
    StaticBoxSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&wx_createPasswordDialog::OnTextCtrl1Text);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&wx_createPasswordDialog::OnTextCtrl3Text);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&wx_createPasswordDialog::OnTextCtrl4Text);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_createPasswordDialog::OnBtnGeneratePwClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_createPasswordDialog::OnBtnPasswordSettingsClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_createPasswordDialog::OnBtnSaveClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_createPasswordDialog::OnBtnCancelClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&wx_createPasswordDialog::OnInit);
    //*)
}

wx_createPasswordDialog::~wx_createPasswordDialog()
{
    //(*Destroy(wx_createPasswordDialog)
    //*)
}


void wx_createPasswordDialog::OnInit(wxInitDialogEvent& event)
{
}

void wx_createPasswordDialog::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void wx_createPasswordDialog::OnTextCtrl4Text(wxCommandEvent& event)
{
}

void wx_createPasswordDialog::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void wx_createPasswordDialog::OnBtnGeneratePwClick(wxCommandEvent& event)
{
}

void wx_createPasswordDialog::OnBtnSaveClick(wxCommandEvent& event)
{
}

void wx_createPasswordDialog::OnBtnCancelClick(wxCommandEvent& event)
{
    Close();
}

void wx_createPasswordDialog::OnBtnPasswordSettingsClick(wxCommandEvent& event)
{
    wx_passwordSettingsDialog* dialog = new wx_passwordSettingsDialog(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    dialog->ShowModal();
    dialog->Destroy();
}
