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
    EVT_LIST_ITEM_SELECTED(ID_LISTVIEWShowAllEntrys, wx_passwordlistFrame::OnSelectedListViewItem)
    EVT_BUTTON(ID_BUTTON3, wx_passwordlistFrame::OnBtnShowPwClick)
    //*)
END_EVENT_TABLE()
int m_selectedPasswordIndex;

wx_passwordlistFrame::wx_passwordlistFrame(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
    :passwordManager() // Instanz der PasswordManager-Klasse erstellen

{
    //(Initialize(wx_passwordlistFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(690, 420));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    ListViewShowAllEntrys = new wxListView(Panel1, ID_LISTVIEWShowAllEntrys, wxPoint(0,0), wxSize(690, 300), wxLC_LIST, wxDefaultValidator, _T("ID_LISTVIEWShowAllEntrys"));
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

    ListViewShowAllEntrys = new wxListView(Panel1, ID_LISTVIEWShowAllEntrys, wxPoint(0, 0), wxSize(690, 300), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEWShowAllEntrys"));


    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordlistFrame::OnBtnCreatePwClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordlistFrame::OnBtnEditPwClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordlistFrame::OnBtnShowPwClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordlistFrame::OnBtnDeletePwClick);
    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&wx_passwordlistFrame::OnBtnCloseClick);

    // Event-Verbindung in wx_passwordlistFrame
    Connect(ID_LISTVIEWShowAllEntrys, wxEVT_LIST_ITEM_SELECTED, wxListEventHandler(wx_passwordlistFrame::OnSelectedListViewItem));

    //*)


    // Erstellen der Spalten in der ListView
    ListViewShowAllEntrys->InsertColumn(0, "Title");
    ListViewShowAllEntrys->InsertColumn(1, "Username");
    ListViewShowAllEntrys->InsertColumn(2, "URL");
    ListViewShowAllEntrys->InsertColumn(3, "Note");
    ListViewShowAllEntrys->InsertColumn(4, "Password");

    // Dateipfad der loginfile abrufen
    std::string loginfile = passwordManager.getLoginFile();

    // Datei öffnen und Daten lesen
    std::ifstream file(loginfile);
    if (!file.is_open())
    {
        wxMessageBox("Failed to open login file!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // Daten aus der Datei lesen
    std::unordered_map<std::string, PasswordManager::PasswordInfo> passwords;

    std::string line;

// Erste zwei Zeilen überspringen
std::getline(file, line);
std::getline(file, line);

while (std::getline(file, line))
{
    // Aufteilung der Zeile anhand des Trennzeichen-Musters "|"
    std::stringstream ss(line);
    std::string title, username, url, note, password;
    std::getline(ss, title, '|');
    std::getline(ss, username, '|');
    std::getline(ss, url, '|');
    std::getline(ss, note, '|');
    std::getline(ss, password, '|');

    passwords[title] = PasswordManager::PasswordInfo(title, username, url, note, password);
}

    file.close();

    // ListView mit den Daten befüllen
    InitializeListView(passwords);


}

// Choosen Item :

void wx_passwordlistFrame::OnSelectedListViewItem(wxListEvent& event)
{
    int selectedIndex = event.GetIndex(); // Index des ausgewählten ListItems

    // Überprüfe, ob der Index gültig ist
    if (selectedIndex >= 0 && selectedIndex < ListViewShowAllEntrys->GetItemCount())
    {
        m_selectedPasswordIndex = selectedIndex; // Speichere den ausgewählten Index
        BtnShowPw->Enable(); // Aktiviere den "Show Password" Button
    }
}
void wx_passwordlistFrame::InitializeListView(const std::unordered_map<std::string, PasswordManager::PasswordInfo>& passwords)
{
    // Löschen Sie alle vorhandenen Einträge im ListView
    ListViewShowAllEntrys->DeleteAllItems();

    // Durchlaufen Sie die PasswordInfo-Einträge in der PasswordManager-Klasse
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
        ListViewShowAllEntrys->SetItem(itemIndex, 0, title);
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
    //wx_showPasswordDialog* dialog = new wx_showPasswordDialog(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    //dialog->ShowModal();
    //dialog->Destroy();
    // Überprüfe, ob ein Passwort ausgewählt wurde
    if (m_selectedPasswordIndex >= 0 && m_selectedPasswordIndex < ListViewShowAllEntrys->GetItemCount())
    {
        // Hole alle Informationen des Passworts aus dem ListView
        wxString title = ListViewShowAllEntrys->GetItemText(m_selectedPasswordIndex, 0);
        wxString username = ListViewShowAllEntrys->GetItemText(m_selectedPasswordIndex, 1);
        wxString url = ListViewShowAllEntrys->GetItemText(m_selectedPasswordIndex, 2);
        wxString note = ListViewShowAllEntrys->GetItemText(m_selectedPasswordIndex, 3);
        wxString password = ListViewShowAllEntrys->GetItemText(m_selectedPasswordIndex, 4);

        // Erstelle den Text für die MessageBox
        wxString message = "Titel: " + title + "\n";
        message += "Benutzername: " + username + "\n";
        message += "URL: " + url + "\n";
        message += "Notiz: " + note + "\n";
        message += "Passwort: " + password;

        // Zeige die MessageBox mit allen Informationen an
        wxMessageBox(message, "Passwort anzeigen", wxOK | wxICON_INFORMATION);
    }
}

void wx_passwordlistFrame::OnBtnDeletePwClick(wxCommandEvent& event)
{
    wx_deletePasswordDialog* dialog = new wx_deletePasswordDialog(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    dialog->ShowModal();
    dialog->Destroy();
}
