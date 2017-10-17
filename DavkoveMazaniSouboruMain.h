/***************************************************************
 * Name:      DavkoveMazaniSouboruMain.h
 * Purpose:   Defines Application Frame
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:   WTFPL
 **************************************************************/

#ifndef DAVKOVEMAZANISOUBORUMAIN_H
#define DAVKOVEMAZANISOUBORUMAIN_H

#ifndef WX_PRECOMP
//(*Headers(DavkoveMazaniSouboruFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/splitter.h>
#include <wx/panel.h>
#include <wx/hyperlink.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)
#endif

#include "wx_pch.h"
#include "FilesToDelete.h"

class DavkoveMazaniSouboruFrame: public wxFrame
{
    public:

        DavkoveMazaniSouboruFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~DavkoveMazaniSouboruFrame();

    private:

        wxArrayString* m_folderFilesFull; /**< Full paths to the files in the folder */

        void LoadFilesToDelete(const wxString& fileName); /**< Loads the file with files to be deleted, updates checked files in directory */
        void LoadFilesInDirectory(const wxString& dirName); /**< Loads the files in the directory, sets their checked status, sets m_folderFilesFull */
        void UpdateFolderFilesCheck(); /**< Updates the checked/unchecked status of files depending on file list */
        wxArrayString ParseFilesToDelete(); /**< Parses the content of txt_Files and returns array of lines */
        void CheckFilesInDirectory(wxArrayString& filesToDelete); /**< Checks FilesInDirectory if their name is in filesToDelete, unchecks those which are not. */
        bool DeleteFiles(); /**< Deletes the checked files. If success, returns true. */

        //(*Handlers(DavkoveMazaniSouboruFrame)
        void OnQuit(wxCommandEvent& event);
        void btn_Load_OnClick(wxCommandEvent& event);
        void btn_Open_OnClick(wxCommandEvent& event);
        void btn_Delete_OnClick(wxCommandEvent& event);
        void txt_Files_OnText(wxCommandEvent& event);
        //*)
        void txt_Files_OnKillFocus(wxFocusEvent& evt);

        //(*Identifiers(DavkoveMazaniSouboruFrame)
        static const long ID_STATICTEXT_LABELS_HEADER;
        static const long ID_BUTTON_LOAD;
        static const long ID_TEXTCTRL_FILES;
        static const long ID_PANEL_FILES;
        static const long ID_STATICTEXT_OPEN_DIRECTORY;
        static const long ID_BUTTON_OPEN;
        static const long ID_STATICTEXT_FILES_TO_BE_DELETED;
        static const long ID_CHECKLISTBOX_FILES_IN_DIRECTORY;
        static const long ID_PANEL_DIRECTORY;
        static const long ID_SPLITTERWINDOW_MAIN;
        static const long ID_STATICTEXT_WEB;
        static const long ID_HYPERLINKCTRL_WEB;
        static const long ID_BUTTON_DELETE;
        static const long ID_PANEL_OUTER_BORDER;
        //*)

        //(*Declarations(DavkoveMazaniSouboruFrame)
        wxStaticText* st_OpenDirectory;
        wxTextCtrl* txt_Files;
        wxPanel* pnl_Directory;
        wxHyperlinkCtrl* hc_Web;
        wxSplitterWindow* sw_MainSplitter;
        wxPanel* pnl_OuterBorder;
        wxCheckListBox* clb_FilesInDirectory;
        wxButton* btn_Open;
        wxButton* btn_Load;
        wxStaticText* txt_FilesToBeDeleted;
        wxButton* btn_Delete;
        wxPanel* pnl_Files;
        wxStaticText* st_Web;
        wxStaticText* st_LabelHeader;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DAVKOVEMAZANISOUBORUMAIN_H
