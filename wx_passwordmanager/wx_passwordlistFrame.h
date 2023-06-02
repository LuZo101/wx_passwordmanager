#ifndef WX_PASSWORDLISTFRAME_H
#define WX_PASSWORDLISTFRAME_H

#include "wx_pch.h"
#include "passwordManager.hpp"
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/button.h>

class wx_passwordlistFrame : public wxFrame
{
public:
    PasswordManager passwordManager;
    wx_passwordlistFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(495, 393));

private:
    void InitializeListView(const std::unordered_map<std::string, PasswordManager::PasswordInfo>& passwords);

    void OnClose(wxCloseEvent& event);
    void OnPanel1Paint(wxPaintEvent& event);
    void OnBtnCreatePwClick(wxCommandEvent& event);
    void OnListView1BeginDrag(wxListEvent& event);
    void OnBtnEditPwClick(wxCommandEvent& event);
    void OnBtnShowPwClick(wxCommandEvent& event);
    void OnBtnDeletePwClick(wxCommandEvent& event);
    void OnBtnCloseClick(wxCommandEvent& event);
    void OnSelectedListViewItem(wxListEvent& event);

    wxListView* ListViewShowAllEntrys;
    wxPanel* Panel1;
    wxButton* BtnCreatePw;
    wxButton* BtnEditPw;
    wxButton* BtnShowPw;
    wxButton* BtnDeletePw;
    wxButton* BtnClose;

    static const long ID_LISTVIEWShowAllEntrys;
    static const long ID_PANEL1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_BUTTON5;

    DECLARE_EVENT_TABLE()
};

#endif // WX_PASSWORDLISTFRAME_H
