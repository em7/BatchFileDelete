/***************************************************************
 * Name:      DavkoveMazaniSouboruMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:   WTFPL
 **************************************************************/

#include "DavkoveMazaniSouboruMain.h"

#include "Translations.h"
#include "ProjectConstants.h"

//(*InternalHeaders(DavkoveMazaniSouboruFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

/////////////////////////////////////////////////////////////////////
//                                                                 //
// INITIALIZATION                                                  //
//                                                                 //
/////////////////////////////////////////////////////////////////////

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
const long DavkoveMazaniSouboruFrame::ID_STATICTEXT_OPEN_DIRECTORY = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_BUTTON_OPEN = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_STATICTEXT_FILES_TO_BE_DELETED = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_CHECKLISTBOX_FILES_IN_DIRECTORY = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_PANEL_DIRECTORY = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_SPLITTERWINDOW_MAIN = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_STATICTEXT_WEB = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_HYPERLINKCTRL_WEB = wxNewId();
const long DavkoveMazaniSouboruFrame::ID_BUTTON_DELETE = wxNewId();
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
    wxBoxSizer* bs_BottomInner;
    wxBoxSizer* bs_BottomOuter;
    wxBoxSizer* bs_OpenButton;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU, _T("wxID_ANY"));
    SetClientSize(wxSize(800,550));
    SetMinSize(wxSize(800,550));
    MainSizer = new wxBoxSizer(wxHORIZONTAL);
    pnl_OuterBorder = new wxPanel(this, ID_PANEL_OUTER_BORDER, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_OUTER_BORDER"));
    bs_AboveSplitterWinSizer = new wxBoxSizer(wxVERTICAL);
    sw_MainSplitter = new wxSplitterWindow(pnl_OuterBorder, ID_SPLITTERWINDOW_MAIN, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE, _T("ID_SPLITTERWINDOW_MAIN"));
    sw_MainSplitter->SetMinSize(wxSize(250,250));
    sw_MainSplitter->SetMinimumPaneSize(250);
    sw_MainSplitter->SetSashGravity(0.5);
    pnl_Files = new wxPanel(sw_MainSplitter, ID_PANEL_FILES, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_FILES"));
    pnl_Files->SetMinSize(wxSize(250,550));
    sbs_Files = new wxStaticBoxSizer(wxVERTICAL, pnl_Files, _("1. Files"));
    st_LabelHeader = new wxStaticText(pnl_Files, ID_STATICTEXT_LABELS_HEADER, _("Set the files you need to delete.\n\nIf you already have a list of files to be deleted, you can load it here.\nThe file to load should be a plain text file (.txt) with\none file name per line."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_LABELS_HEADER"));
    sbs_Files->Add(st_LabelHeader, 0, wxALL|wxEXPAND, 5);
    bs_LoadButton = new wxBoxSizer(wxHORIZONTAL);
    btn_Load = new wxButton(pnl_Files, ID_BUTTON_LOAD, _("&Load"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_LOAD"));
    bs_LoadButton->Add(btn_Load, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sbs_Files->Add(bs_LoadButton, 0, wxALL|wxEXPAND, 5);
    txt_Files = new wxTextCtrl(pnl_Files, ID_TEXTCTRL_FILES, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_DONTWRAP, wxDefaultValidator, _T("ID_TEXTCTRL_FILES"));
    sbs_Files->Add(txt_Files, 1, wxALL|wxEXPAND, 5);
    pnl_Files->SetSizer(sbs_Files);
    sbs_Files->Fit(pnl_Files);
    sbs_Files->SetSizeHints(pnl_Files);
    pnl_Directory = new wxPanel(sw_MainSplitter, ID_PANEL_DIRECTORY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_DIRECTORY"));
    pnl_Directory->SetMinSize(wxSize(250,550));
    sbs_Directory = new wxStaticBoxSizer(wxVERTICAL, pnl_Directory, _("2. Directory"));
    st_OpenDirectory = new wxStaticText(pnl_Directory, ID_STATICTEXT_OPEN_DIRECTORY, _("Open the directory where you want to delete the files from."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_OPEN_DIRECTORY"));
    sbs_Directory->Add(st_OpenDirectory, 0, wxALL|wxEXPAND, 5);
    bs_OpenButton = new wxBoxSizer(wxHORIZONTAL);
    btn_Open = new wxButton(pnl_Directory, ID_BUTTON_OPEN, _("&Open"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_OPEN"));
    bs_OpenButton->Add(btn_Open, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    sbs_Directory->Add(bs_OpenButton, 0, wxALL|wxEXPAND, 5);
    txt_FilesToBeDeleted = new wxStaticText(pnl_Directory, ID_STATICTEXT_FILES_TO_BE_DELETED, _("Check files to be deleted:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_FILES_TO_BE_DELETED"));
    sbs_Directory->Add(txt_FilesToBeDeleted, 0, wxALL|wxEXPAND, 5);
    clb_FilesInDirectory = new wxCheckListBox(pnl_Directory, ID_CHECKLISTBOX_FILES_IN_DIRECTORY, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX_FILES_IN_DIRECTORY"));
    sbs_Directory->Add(clb_FilesInDirectory, 1, wxALL|wxEXPAND, 5);
    pnl_Directory->SetSizer(sbs_Directory);
    sbs_Directory->Fit(pnl_Directory);
    sbs_Directory->SetSizeHints(pnl_Directory);
    sw_MainSplitter->SplitVertically(pnl_Files, pnl_Directory);
    bs_AboveSplitterWinSizer->Add(sw_MainSplitter, 1, wxALL|wxEXPAND, 5);
    bs_BottomOuter = new wxBoxSizer(wxVERTICAL);
    bs_BottomInner = new wxBoxSizer(wxHORIZONTAL);
    st_Web = new wxStaticText(pnl_OuterBorder, ID_STATICTEXT_WEB, _("Web:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_WEB"));
    bs_BottomInner->Add(st_Web, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    hc_Web = new wxHyperlinkCtrl(pnl_OuterBorder, ID_HYPERLINKCTRL_WEB, _("https://github.com/em7/BatchFileDelete"), _("https://github.com/em7/BatchFileDelete/blob/master/README.md"), wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL_WEB"));
    bs_BottomInner->Add(hc_Web, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    btn_Delete = new wxButton(pnl_OuterBorder, ID_BUTTON_DELETE, _("&Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DELETE"));
    bs_BottomInner->Add(btn_Delete, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bs_BottomOuter->Add(bs_BottomInner, 1, wxALL|wxALIGN_RIGHT, 5);
    bs_AboveSplitterWinSizer->Add(bs_BottomOuter, 0, wxALL|wxEXPAND, 5);
    pnl_OuterBorder->SetSizer(bs_AboveSplitterWinSizer);
    bs_AboveSplitterWinSizer->Fit(pnl_OuterBorder);
    bs_AboveSplitterWinSizer->SetSizeHints(pnl_OuterBorder);
    MainSizer->Add(pnl_OuterBorder, 1, wxALL|wxEXPAND, 0);
    SetSizer(MainSizer);
    SetSizer(MainSizer);
    Layout();

    Connect(ID_BUTTON_LOAD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DavkoveMazaniSouboruFrame::btn_Load_OnClick);
    Connect(ID_TEXTCTRL_FILES,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DavkoveMazaniSouboruFrame::txt_Files_OnText);
    Connect(ID_BUTTON_OPEN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DavkoveMazaniSouboruFrame::btn_Open_OnClick);
    Connect(ID_BUTTON_DELETE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DavkoveMazaniSouboruFrame::btn_Delete_OnClick);
    //*)

    Connect(ID_TEXTCTRL_FILES,wxEVT_KILL_FOCUS,(wxObjectEventFunction)&DavkoveMazaniSouboruFrame::txt_Files_OnKillFocus);

    TranslateUI();
}

DavkoveMazaniSouboruFrame::~DavkoveMazaniSouboruFrame()
{
    //(*Destroy(DavkoveMazaniSouboruFrame)
    //*)

    free(m_folderFilesFull);
}

void DavkoveMazaniSouboruFrame::TranslateUI()
{
    SetTitle(wxString(C::Project_name) + " " + wxString(C::Version));
    sbs_Files->GetStaticBox()->SetLabel(T::n1_Files);
    st_LabelHeader->SetLabel(T::Set_files_you_need_to_delete);
    btn_Load->SetLabel(T::Load);
    sbs_Directory->GetStaticBox()->SetLabel(T::n2_Directory);
    st_OpenDirectory->SetLabel(T::Open_directory_you_want_delete_files_from);
    btn_Open->SetLabel(T::Open);
    txt_FilesToBeDeleted->SetLabel(T::Check_files_to_be_deleted);
    btn_Delete->SetLabel(T::Delete);
}


/////////////////////////////////////////////////////////////////////
//                                                                 //
// HANDLERS                                                        //
//                                                                 //
/////////////////////////////////////////////////////////////////////

void DavkoveMazaniSouboruFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void DavkoveMazaniSouboruFrame::btn_Load_OnClick(wxCommandEvent& event)
{
    wxFileDialog openDlg(this, T::Open_file_with_names_to_delete, wxEmptyString,
                         wxEmptyString, T::Text_file_Open_Dialog_filter,
                         wxFD_FILE_MUST_EXIST);

    if (wxID_OK == openDlg.ShowModal())
    {
        wxString filePath = openDlg.GetPath();
        LoadFilesToDelete(filePath);
    }
}

void DavkoveMazaniSouboruFrame::btn_Open_OnClick(wxCommandEvent& event)
{
    wxDirDialog openDlg(this, T::Folder_to_delete_selected_files_from, wxEmptyString, wxDD_DIR_MUST_EXIST);

    if (wxID_OK == openDlg.ShowModal())
    {
        wxString dirName = openDlg.GetPath();
        LoadFilesInDirectory(dirName);
    }
}

void DavkoveMazaniSouboruFrame::btn_Delete_OnClick(wxCommandEvent& event)
{
    wxMessageDialog msgDlg(this,
                           T::Do_you_really_want_to_delete_files_It_is_irreversible,
                           C::Project_name,
                           wxYES_NO|wxNO_DEFAULT);
    msgDlg.SetYesNoLabels(wxString(T::Delete_msg_box), wxString(T::Cancel_deletion));
    if (wxID_YES == msgDlg.ShowModal())
    {
        if (!DeleteFiles())
        {
            wxMessageDialog errDlg(this,
                                   T::Could_not_delete_some_files,
                                   C::Project_name,
                                   wxICON_ERROR);
            errDlg.ShowModal();
        }
        else
        {
            wxMessageDialog okDlg(this,
                                  T::Selected_files_successfully_deleted,
                                  C::Project_name,
                                  wxICON_INFORMATION);
            okDlg.ShowModal();
        }
    }
}

void DavkoveMazaniSouboruFrame::txt_Files_OnKillFocus(wxFocusEvent& evt)
{
//    wxMessageDialog msgDlg(this, wxT("Hello World"));
//    msgDlg.ShowModal();
    UpdateFolderFilesCheck();
}

void DavkoveMazaniSouboruFrame::txt_Files_OnText(wxCommandEvent& event)
{
    UpdateFolderFilesCheck();
}

/////////////////////////////////////////////////////////////////////
//                                                                 //
// HELPER FUNCTIONS                                                //
//                                                                 //
/////////////////////////////////////////////////////////////////////

void DavkoveMazaniSouboruFrame::LoadFilesToDelete(const wxString& fileName)
{
    wxString* content = FilesToDelete::LoadFile(fileName);
    if (nullptr != content)
    {
        txt_Files->SetValue(*content);
        free(content);
        UpdateFolderFilesCheck();
    }
}

void DavkoveMazaniSouboruFrame::LoadFilesInDirectory(const wxString& dirName)
{
    clb_FilesInDirectory->Clear();

    free(m_folderFilesFull);
    m_folderFilesFull = FilesToDelete::EnumAllFiles(dirName);
    if (! (nullptr == m_folderFilesFull || m_folderFilesFull->GetCount() < 1))
    {
        for(wxString& fullFileName : *m_folderFilesFull)
        {
            wxString* name = FilesToDelete::GetFileName(fullFileName);
            if (nullptr != name)
            {
                clb_FilesInDirectory->Append(*name);
            }

            free(name);
        }
        UpdateFolderFilesCheck();
    }
}


wxArrayString DavkoveMazaniSouboruFrame::ParseFilesToDelete()
{
    wxArrayString fileNames;
    int noOfLines = txt_Files->GetNumberOfLines();
    for (int i = 0; i < noOfLines; i++)
    {
        fileNames.Add(txt_Files->GetLineText(i));
    }
    return fileNames;
}

void DavkoveMazaniSouboruFrame::CheckFilesInDirectory(wxArrayString& filesToDelete)
{
    for (unsigned int i = 0; i < clb_FilesInDirectory->GetCount(); i ++)
    {
        wxString fileInDir = clb_FilesInDirectory->GetString(i);

        bool toDelete = false;
        for (wxString& fileToDel : filesToDelete)
        {
            if (fileToDel == fileInDir)
            {
                toDelete = true;
                break;
            }
        }

        clb_FilesInDirectory->Check(i, toDelete);
    }
}

void DavkoveMazaniSouboruFrame::UpdateFolderFilesCheck()
{
    wxArrayString filesToDel = ParseFilesToDelete();
    CheckFilesInDirectory(filesToDel);
}

bool DavkoveMazaniSouboruFrame::DeleteFiles()
{
    bool success = true;
    if (nullptr == m_folderFilesFull)
    {
        success = false; //no directory open, nothing to do
    }

    wxArrayInt checkedIdxs;
    if (success && 0 == clb_FilesInDirectory->GetCheckedItems(checkedIdxs))
    {
        success = false; //no checked files, nothing to do
    }

    if (success)
    {
        wxArrayString filePaths;
        for (unsigned int i = 0; i < checkedIdxs.GetCount(); i++)
        {
            unsigned int itemIdx = checkedIdxs.Item(i);
            wxString itemName = clb_FilesInDirectory->GetString(itemIdx);
            const wxString* fullName = FilesToDelete::FindMatchingFullPath(itemName, *m_folderFilesFull);

            std::cout << "Deleting file: " << fullName->c_str() << std::endl;
            if (! FilesToDelete::DeleteFile(*fullName))
            {
                std::cerr << "Deleting file '" << fullName->c_str() << "' failed." << std::endl;
                success = false;
            }
        }
    }


    return success;
}

