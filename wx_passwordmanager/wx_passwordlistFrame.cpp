#include "wx_pch.h"
#include "wx_passwordlistFrame.h"
#include "wx_createPasswordDialog.h"
#include "wx_editPasswordDialog.h"
#include "wx_deletePasswordDialog.h"
#include "wx_showPasswordDialog.h"
#include "passwordManager.hpp"
#ifndef WX_PRECOMP
//(*InternalHeadersPCH(wx_passwordlistFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#endif
//(*InternalHeaders(wx_passwordlistFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(wx_passwordlistFrame)
const long wx_passwordlistFrame::ID_LISTVIEWShowAllEntrys = wxNewId();
const long wx_passwordlistFrame::ID_PANEL1 = wxNewId();
const long wx_passwordlistFrame::ID_BUTTON1 = wxNewId();
const long wx_passwordlistFrame::ID_BUTTON2 = wxNewId();
const long wx_passwordlistFrame::ID_BUTTON3 = wxNewId();
const long wx_passwordlistFrame::ID_BUTTON4 = wxNewId();
const long wx_passwordlistFrame::ID_BUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wx_passwordlistFrame,wxFrame)
    //(*EventTable(wx_passwordlistFrame)
    //*)
END_EVENT_TABLE()

wx_passwordlistFrame::wx_passwordlistFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
    // To Do konstruktor
    //: wxFrame(parent, id, "Password List", pos, size, wxDEFAULT_FRAME_STYLE)
{
    //(*Initialize(wx_passwordlistFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(495,393));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    ListViewShowAllEntrys = new wxListView(Panel1, ID_LISTVIEWShowAllEntrys, wxPoint(0,0), wxSize(368,352), wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEWShowAllEntrys"));
    BoxSizer1->Add(Panel1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BtnCreatePw = new wxButton(this, ID_BUTTON1, _("create"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(BtnCreatePw, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnEditPw = new wxButton(this, ID_BUTTON2, _("edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(BtnEditPw, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnShowPw = new wxButton(this, ID_BUTTON3, _("show"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(BtnShowPw, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnDeletePw = new wxButton(this, ID_BUTTON4, _("delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer2->Add(BtnDeletePw, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BtnClose = new wxButton(this, ID_BUTTON5, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer2->Add(BtnClose, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    ListViewShowAllEntrys = new wxListView(Panel1, ID_LISTVIEWShowAllEntrys, wxPoint(0, 0), wxSize(368, 352), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEWShowAllEntrys"));


    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordlistFrame::OnBtnCreatePwClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordlistFrame::OnBtnEditPwClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordlistFrame::OnBtnShowPwClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordlistFrame::OnBtnDeletePwClick);
    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&wx_passwordlistFrame::OnBtnCloseClick);
    //*)

    PasswordManager passwordManager;
    const std::unordered_map<std::string, PasswordManager::PasswordInfo>& passwords = passwordManager.getAllPasswords();

    // Initialisieren Sie die ListView mit den Passwörtern
    InitializeListView(passwords);

    // Erstellen der Spalten in der ListView
    ListViewShowAllEntrys->InsertColumn(0, "Title");
    ListViewShowAllEntrys->InsertColumn(1, "Username");
    ListViewShowAllEntrys->InsertColumn(2, "URL");
    ListViewShowAllEntrys->InsertColumn(3, "Note");
    ListViewShowAllEntrys->InsertColumn(4, "Password");
}

void wx_passwordlistFrame::InitializeListView(const std::unordered_map<std::string, PasswordManager::PasswordInfo>& passwords)
{
    // Löschen Sie alle vorhandenen Einträge im ListView
    ListViewShowAllEntrys->DeleteAllItems();

    // Durchlaufen Sie die PasswordInfo-Einträge in der std::unordered_map
    int index = 0;
    for (const auto& entry : passwords)
    {
        // Extrahieren Sie die benötigten Informationen aus dem PasswordInfo-Eintrag
        const std::string& title = entry.second.getTitle();
        const std::string& username = entry.second.getUsername();
        const std::string& url = entry.second.getURL();
        const std::string& note = entry.second.getNote();
        const std::string& password = entry.second.getPassword();

        // Fügen Sie eine neue Zeile in das ListView ein
        long itemIndex = ListViewShowAllEntrys->InsertItem(index, title);

        // Fügen Sie die erforderlichen Unterelemente (Spalten) in die Zeile ein
        ListViewShowAllEntrys->SetItem(itemIndex, 1, username);
        ListViewShowAllEntrys->SetItem(itemIndex, 2, url);
        ListViewShowAllEntrys->SetItem(itemIndex, 3, note);
        ListViewShowAllEntrys->SetItem(itemIndex, 4, password);

        index++;
    }
}

void wx_passwordlistFrame::OnClose(wxCloseEvent& event)
{
    Close();
}

void wx_passwordlistFrame::OnBtnCreatePwClick(wxCommandEvent& event)
{
    wx_createPasswordDialog* dialog = new wx_createPasswordDialog(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    dialog->ShowModal();
    // Optionally, you can perform additional actions with the dialog object
    // after the dialog is closed, such as retrieving user input or updating the UI.

    // Don't forget to clean up the memory allocated for the dialog object.
    dialog->Destroy();
}

void wx_passwordlistFrame::OnBtnEditPwClick(wxCommandEvent& event)
{
    wx_editPasswordDialog* dialog = new wx_editPasswordDialog(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    dialog->ShowModal();
    dialog->Destroy();
}

void wx_passwordlistFrame::OnBtnCloseClick(wxCommandEvent& event)
{
    Close();
}

void wx_passwordlistFrame::OnBtnShowPwClick(wxCommandEvent& event)
{
    wx_showPasswordDialog* dialog = new wx_showPasswordDialog(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    dialog->ShowModal();
    dialog->Destroy();
}

void wx_passwordlistFrame::OnBtnDeletePwClick(wxCommandEvent& event)
{
    wx_deletePasswordDialog* dialog = new wx_deletePasswordDialog(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    dialog->ShowModal();
    dialog->Destroy();
}
