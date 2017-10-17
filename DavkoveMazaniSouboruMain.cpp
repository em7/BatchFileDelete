/***************************************************************
 * Name:      DavkoveMazaniSouboruMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "DavkoveMazaniSouboruMain.h"

#include "FilesToDelete.h"

//(*InternalHeaders(DavkoveMazaniSouboruFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

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

//(*IdInit(DavkoveMazaniSouboruFrame)
const long DavkoveMazaniSouboruFrame::ID_STATICTEXT_LABELS_HEADER = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_BUTTON_LOAD = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_TEXTCTRL_FILES = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_PANEL_FILES = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_STATICTEXT1 = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_BUTTON_OPEN = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_STATICTEXT_FILES_TO_BE_DELETED = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_CHECKLISTBOX_FILES_TO_DELETE = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_BUTTON_DELETE = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_PANEL_DIRECTORY = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_SPLITTERWINDOW_MAIN = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_PANEL_OUTER_BORDER = wxNewId();
//*)

BEGIN_EVENT_TABLE(DavkoveMazaniSouboruFrame,wxFrame)
    //(*EventTable(DavkoveMazaniSouboruFrame)
    //*)
END_EVENT_TABLE()


DavkoveMazaniSouboruFrame::DavkoveMazaniSouboruFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(DavkoveMazaniSouboruFrame)
    wxBoxSizer* MainSizer;
    wxBoxSizer* bs_LoadButton;
    wxBoxSizer* bs_AboveSplitterWinSizer;
    wxBoxSizer* bs_DeleteButton;
    wxBoxSizer* BoxSizer2;
    wxStaticBoxSizer* sbs_Directory;
    wxStaticBoxSizer* sbs_Files;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    MainSizer = new wxBoxSizer(wxHORIZONTAL);
    pnl_OuterBorder = new wxPanel(this, ID_PANEL_OUTER_BORDER, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_OUTER_BORDER"));
    bs_AboveSplitterWinSizer = new wxBoxSizer(wxHORIZONTAL);
    sw_MainSplitter = new wxSplitterWindow(pnl_OuterBorder, ID_SPLITTERWINDOW_MAIN, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE, _T("ID_SPLITTERWINDOW_MAIN"));
    sw_MainSplitter->SetMinimumPaneSize(250);
    sw_MainSplitter->SetSashGravity(0.5);
    pnl_Files = new wxPanel(sw_MainSplitter, ID_PANEL_FILES, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_FILES"));
    sbs_Files = new wxStaticBoxSizer(wxVERTICAL, pnl_Files, _("1. Files"));
    st_LabelHeader = new wxStaticText(pnl_Files, ID_STATICTEXT_LABELS_HEADER, _("Set the files you need to delete.\n\nIf you already have a list of files to be deleted, you can load it here.\nThe file to load should be a plain text file (.txt) with\none file name per line."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_LABELS_HEADER"));
    sbs_Files->Add(st_LabelHeader, 0, wxALL|wxEXPAND, 5);
    bs_LoadButton = new wxBoxSizer(wxHORIZONTAL);
    btn_Load = new wxButton(pnl_Files, ID_BUTTON_LOAD, _("&Load"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_LOAD"));
    bs_LoadButton->Add(btn_Load, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sbs_Files->Add(bs_LoadButton, 0, wxALL|wxEXPAND, 5);
    txt_Files = new wxTextCtrl(pnl_Files, ID_TEXTCTRL_FILES, _("a.ace\na.ace\na.ace\na.ace\na.ace\na.ace\na.ace"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_DONTWRAP, wxDefaultValidator, _T("ID_TEXTCTRL_FILES"));
    sbs_Files->Add(txt_Files, 1, wxALL|wxEXPAND, 5);
    pnl_Files->SetSizer(sbs_Files);
    sbs_Files->Fit(pnl_Files);
    sbs_Files->SetSizeHints(pnl_Files);
    pnl_Directory = new wxPanel(sw_MainSplitter, ID_PANEL_DIRECTORY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_DIRECTORY"));
    sbs_Directory = new wxStaticBoxSizer(wxVERTICAL, pnl_Directory, _("2. Directory"));
    StaticText1 = new wxStaticText(pnl_Directory, ID_STATICTEXT1, _("Open the directory where you want to delete the files from."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    sbs_Directory->Add(StaticText1, 0, wxALL|wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    btn_Open = new wxButton(pnl_Directory, ID_BUTTON_OPEN, _("&Open"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_OPEN"));
    BoxSizer2->Add(btn_Open, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sbs_Directory->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    txt_FilesToBeDeleted = new wxStaticText(pnl_Directory, ID_STATICTEXT_FILES_TO_BE_DELETED, _("Check files to be deleted:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FILES_TO_BE_DELETED"));
    sbs_Directory->Add(txt_FilesToBeDeleted, 0, wxALL|wxEXPAND, 5);
    clb_FilesToDelete = new wxCheckListBox(pnl_Directory, ID_CHECKLISTBOX_FILES_TO_DELETE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX_FILES_TO_DELETE"));
    clb_FilesToDelete->Append(_("a"));
    clb_FilesToDelete->Append(_("b"));
    clb_FilesToDelete->Check(clb_FilesToDelete->Append(_("c")));
    clb_FilesToDelete->Append(_("d"));
    clb_FilesToDelete->Append(_("e"));
    clb_FilesToDelete->Append(wxEmptyString);
    clb_FilesToDelete->Append(_("a"));
    clb_FilesToDelete->Append(_("ab"));
    clb_FilesToDelete->Append(_("abc"));
    clb_FilesToDelete->Append(_("abcd"));
    clb_FilesToDelete->Append(_("abcde"));
    clb_FilesToDelete->Append(_("abcdef"));
    sbs_Directory->Add(clb_FilesToDelete, 1, wxALL|wxEXPAND, 5);
    bs_DeleteButton = new wxBoxSizer(wxVERTICAL);
    btn_Delete = new wxButton(pnl_Directory, ID_BUTTON_DELETE, _("&Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DELETE"));
    bs_DeleteButton->Add(btn_Delete, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT, 5);
    sbs_Directory->Add(bs_DeleteButton, 0, wxALL|wxEXPAND, 5);
    pnl_Directory->SetSizer(sbs_Directory);
    sbs_Directory->Fit(pnl_Directory);
    sbs_Directory->SetSizeHints(pnl_Directory);
    sw_MainSplitter->SplitVertically(pnl_Files, pnl_Directory);
    bs_AboveSplitterWinSizer->Add(sw_MainSplitter, 1, wxALL|wxEXPAND, 5);
    pnl_OuterBorder->SetSizer(bs_AboveSplitterWinSizer);
    bs_AboveSplitterWinSizer->Fit(pnl_OuterBorder);
    bs_AboveSplitterWinSizer->SetSizeHints(pnl_OuterBorder);
    MainSizer->Add(pnl_OuterBorder, 1, wxALL|wxEXPAND, 0);
    SetSizer(MainSizer);
    MainSizer->Fit(this);
    MainSizer->SetSizeHints(this);

    Connect(ID_BUTTON_LOAD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DavkoveMazaniSouboruFrame::btn_Load_OnClick);
    Connect(ID_BUTTON_OPEN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DavkoveMazaniSouboruFrame::btn_Open_OnClick);
    Connect(ID_BUTTON_DELETE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DavkoveMazaniSouboruFrame::btn_Delete_OnClick);
    //*)
}

DavkoveMazaniSouboruFrame::~DavkoveMazaniSouboruFrame()
{
    //(*Destroy(DavkoveMazaniSouboruFrame)
    //*)

    free(folderFilesFull);
}

void DavkoveMazaniSouboruFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void DavkoveMazaniSouboruFrame::btn_Load_OnClick(wxCommandEvent& event)
{
    wxFileDialog openDlg(this, wxT("Otevřít soubor s názvy pro smazání"), wxEmptyString,
                         wxEmptyString, wxT("Textový soubor (*.txt)|*.txt|Všechny soubory (*.*)|*.*"),
                         wxFD_FILE_MUST_EXIST);

    if (wxID_OK == openDlg.ShowModal())
    {
        wxString* content = FilesToDelete::LoadFile(openDlg.GetPath());

        if (nullptr != content)
        {
            txt_Files->SetValue(*content);
            free(content);
        }
    }
}

void DavkoveMazaniSouboruFrame::btn_Open_OnClick(wxCommandEvent& event)
{
    wxDirDialog openDlg(this, wxT("Složka, ze které smazat vybrané soubory"), wxEmptyString, wxDD_DIR_MUST_EXIST);

    if (wxID_OK == openDlg.ShowModal())
    {
        wxString dirName = openDlg.GetPath();
        clb_FilesToDelete->Clear();

        free(folderFilesFull);
        folderFilesFull = FilesToDelete::EnumAllFiles(dirName);
        if (! (nullptr == folderFilesFull || folderFilesFull->GetCount() < 1))
        {
            for(wxString& fullFileName : *folderFilesFull)
            {
                wxString* name = FilesToDelete::GetFileName(fullFileName);
                if (nullptr != name)
                {
                    clb_FilesToDelete->Append(*name);
                }

                free(name);
            }
        }
    }
}

void DavkoveMazaniSouboruFrame::btn_Delete_OnClick(wxCommandEvent& event)
{
    wxMessageDialog msgDlg(this, wxT("Hello World"));
    msgDlg.ShowModal();
}
