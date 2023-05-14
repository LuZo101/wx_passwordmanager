/***************************************************************
 * Name:      wx_passwordmanagerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Lukas Zorn (lukas.zorn@protonmail.com)
 * Created:   2023-05-11
 * Copyright: Lukas Zorn ()
 * License: MIT License

 **************************************************************/

#include "wx_pch.h"
#include "wx_passwordmanagerMain.h"
#include <wx/msgdlg.h>
#include "wx_passwordlistFrame.h"
#include "wx_editPasswordDialog.h"
#include "passwordManager.hpp"

//(*InternalHeaders(wx_passwordmanagerFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wx_passwordmanagerFrame)
const long wx_passwordmanagerFrame::ID_PANEL1 = wxNewId();
const long wx_passwordmanagerFrame::ID_STATICTEXT1 = wxNewId();
const long wx_passwordmanagerFrame::ID_TEXTCTRL1 = wxNewId();
const long wx_passwordmanagerFrame::ID_STATICTEXT2 = wxNewId();
const long wx_passwordmanagerFrame::ID_TEXTCTRL2 = wxNewId();
const long wx_passwordmanagerFrame::ID_BUTTON1 = wxNewId();
const long wx_passwordmanagerFrame::ID_BUTTON2 = wxNewId();
const long wx_passwordmanagerFrame::ID_STATICTEXT3 = wxNewId();
const long wx_passwordmanagerFrame::ID_STATICTEXT4 = wxNewId();
const long wx_passwordmanagerFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long wx_passwordmanagerFrame::ID_BUTTON3 = wxNewId();
const long wx_passwordmanagerFrame::idMenuQuit = wxNewId();
const long wx_passwordmanagerFrame::idMenuAbout = wxNewId();
const long wx_passwordmanagerFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wx_passwordmanagerFrame,wxFrame)
    //(*EventTable(wx_passwordmanagerFrame)
    //*)
END_EVENT_TABLE()

wx_passwordmanagerFrame::wx_passwordmanagerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wx_passwordmanagerFrame)
    wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetMaxSize(wxSize(-1,-1));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetMaxSize(wxSize(-1,-1));
    BoxSizer1->Add(Panel1, 0, wxALL|wxEXPAND, 0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Login"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Username"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLoginUser = new wxTextCtrl(this, ID_TEXTCTRL1, _("test"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(TextCtrlLoginUser, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Passwort"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLoginPassword = new wxTextCtrl(this, ID_TEXTCTRL2, _("test"), wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrlLoginPassword, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Btn_LoginOk = new wxButton(this, ID_BUTTON1, _("Login"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(Btn_LoginOk, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Btn_LoginCancel = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer1->Add(Btn_LoginCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer1, 0, wxALL|wxEXPAND, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Select DB"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer2->Add(StaticText3, 1, wxALL|wxEXPAND, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("New DB + User"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticText4, 1, wxALL|wxEXPAND, 5);
    FilePickerLoaddB = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    FlexGridSizer2->Add(FilePickerLoaddB, 1, wxALL|wxEXPAND, 5);
    BtnCreateDb = new wxButton(this, ID_BUTTON3, _("Create DB"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer2->Add(BtnCreateDb, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(FlexGridSizer2, 0, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&wx_passwordmanagerFrame::OnBtn_LoginOkClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordmanagerFrame::OnBtn_LoginOkClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordmanagerFrame::OnBtn_LoginCancelClick);
    Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&wx_passwordmanagerFrame::OnFilePickerLoaddBFileChanged);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wx_passwordmanagerFrame::OnBtnCreateDbClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wx_passwordmanagerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wx_passwordmanagerFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&wx_passwordmanagerFrame::OnClose);
    //*)
}

wx_passwordmanagerFrame::~wx_passwordmanagerFrame()
{

}

void wx_passwordmanagerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wx_passwordmanagerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wx_passwordmanagerFrame::OnClose(wxCloseEvent& event)
{
    event.Skip(TRUE);
}

void wx_passwordmanagerFrame::OnBtn_LoginCancelClick(wxCommandEvent& event)
{
    Close();
}

void wx_passwordmanagerFrame::OnBtn_LoginOkClick(wxCommandEvent& event)
{
    // Get the entered username from the text input field
    std::string enteredUsername = TextCtrlLoginUser->GetValue().ToStdString();

    // Get the entered password from the text input field
    std::string enteredPassword = TextCtrlLoginPassword->GetValue().ToStdString();

    // Get the login file path
    std::string loginfile = PasswordManager::getLoginFile();

    // Read the first two lines from the login file
    std::ifstream file(loginfile);
    std::string storedUsername, storedPassword;
    if (file.is_open())
    {
        std::getline(file, storedUsername);
        std::getline(file, storedPassword);
        file.close();
    }
    else
    {
        wxMessageBox("Failed to open login file!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // Compare the entered username and password with the stored values
    if (enteredUsername == storedUsername && enteredPassword == storedPassword)
    {
        Close();

        // Username and password are correct
        // Take appropriate action, such as allowing access to the password manager
        // or displaying a success message
        // Example: Access granted
        //wxMessageBox("Login successful!", "Success", wxOK | wxICON_INFORMATION);
        wx_passwordlistFrame* newFrame = new wx_passwordlistFrame(nullptr);
        newFrame->Show();
    }
    else
    {
        // Username or password is incorrect
        // Take appropriate action, such as displaying an error message
        // Example: Access denied
        wxMessageBox("Incorrect username or password!", "Error", wxOK | wxICON_ERROR);
    }
}



void wx_passwordmanagerFrame::OnTextCtrlLoginPasswordTextEnter(wxCommandEvent& event)
{
    OnBtn_LoginOkClick(event);
}


void wx_passwordmanagerFrame::OnFilePickerLoaddBFileChanged(wxFileDirPickerEvent& event)
{
    wxString filename = event.GetPath();
    std::string loginfile = filename.ToStdString();
    PasswordManager::setLoginFile(loginfile);
}


void wx_passwordmanagerFrame::OnBtnCreateDbClick(wxCommandEvent& event)
{
    // Öffnen eines Dialogfensters zum Festlegen des Dateinamens
    wxString defaultFileName = "login";
    wxString wildcard = "Text files (*.txt)|*.txt";
    wxString defaultDir = wxEmptyString;
    wxString caption = "Create Login File";
    wxString defaultExtension = "txt";

    wxFileDialog saveFileDialog(this, caption, defaultDir, defaultFileName, wildcard, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_OK)
    {
        // Dateiname auswählen
        wxString filePath = saveFileDialog.GetPath();

        // Dateierweiterung überprüfen und aktualisieren
        wxString extension = saveFileDialog.GetFilterIndex() == 0 ? "txt" : "";
        wxString fileName = saveFileDialog.GetFilename();
        wxString newFileName = fileName;

        if (fileName.AfterLast('.').IsEmpty() && !extension.IsEmpty())
        {
            newFileName += "." + extension;
        }

        // Den aktualisierten Dateinamen an die PasswordManager-Klasse übergeben
        std::string loginFile = std::string(filePath.mb_str());
        PasswordManager::setLoginFile(loginFile);

        // Dialogfenster zum Eingeben von Benutzername und Passwort anzeigen
        wxTextEntryDialog usernameDialog(this, "Enter Username", "Username");
        wxTextEntryDialog passwordDialog1(this, "Enter Password", "Password", wxEmptyString, wxTextEntryDialogStyle | wxTE_PASSWORD);
        wxTextEntryDialog passwordDialog2(this, "Re-enter Password", "Password", wxEmptyString, wxTextEntryDialogStyle | wxTE_PASSWORD);

        if (usernameDialog.ShowModal() == wxID_OK && passwordDialog1.ShowModal() == wxID_OK && passwordDialog2.ShowModal() == wxID_OK)
        {
            // Benutzernamen und Passwort abrufen
            wxString username = usernameDialog.GetValue();
            wxString password1 = passwordDialog1.GetValue();
            wxString password2 = passwordDialog2.GetValue();

            // Überprüfen, ob die beiden eingegebenen Passwörter übereinstimmen
            if (password1 == password2)
            {
                // Passwörter stimmen überein
                // Benutzernamen und Passwort in die Datei schreiben
                std::ofstream file(newFileName.ToStdString(), std::ios::out | std::ios::app);
                if (!file)
                {
                    std::cerr << "Error opening file: " << newFileName.ToStdString() << std::endl;
                    return;
                }

                file << username.mb_str() << std::endl;
                file << password1.mb_str() << std::endl;

                file.close();

                // Den ausgewählten Dateinamen im FilePicker setzen
                FilePickerLoaddB->SetPath(newFileName);
            }
            else
            {
                // Passwörter stimmen nicht überein
                wxMessageBox("Passwords do not match!", "Error", wxOK | wxICON_ERROR);
            }
        }
    }
}
