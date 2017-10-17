/***************************************************************
 * Name:      DavkoveMazaniSouboruMain.h
 * Purpose:   Defines Application Frame
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:
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
#include <wx/button.h>
#include <wx/frame.h>
//*)
#endif

#include <wx/arrstr.h>

class DavkoveMazaniSouboruFrame: public wxFrame
{
    public:

        DavkoveMazaniSouboruFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~DavkoveMazaniSouboruFrame();

    private:

        wxArrayString* folderFilesFull; /**< Full paths to the files in the folder */

        //(*Handlers(DavkoveMazaniSouboruFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void btn_Load_OnClick(wxCommandEvent& event);
        void btn_Open_OnClick(wxCommandEvent& event);
        void btn_Delete_OnClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(DavkoveMazaniSouboruFrame)
        static const long ID_STATICTEXT_LABELS_HEADER;
        static const long ID_BUTTON_LOAD;
        static const long ID_TEXTCTRL_FILES;
        static const long ID_PANEL_FILES;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON_OPEN;
        static const long ID_STATICTEXT_FILES_TO_BE_DELETED;
        static const long ID_CHECKLISTBOX_FILES_TO_DELETE;
        static const long ID_BUTTON_DELETE;
        static const long ID_PANEL_DIRECTORY;
        static const long ID_SPLITTERWINDOW_MAIN;
        static const long ID_PANEL_OUTER_BORDER;
        //*)

        //(*Declarations(DavkoveMazaniSouboruFrame)
        wxTextCtrl* txt_Files;
        wxPanel* pnl_Directory;
        wxStaticText* StaticText1;
        wxSplitterWindow* sw_MainSplitter;
        wxPanel* pnl_OuterBorder;
        wxButton* btn_Open;
        wxButton* btn_Load;
        wxStaticText* txt_FilesToBeDeleted;
        wxCheckListBox* clb_FilesToDelete;
        wxButton* btn_Delete;
        wxPanel* pnl_Files;
        wxStaticText* st_LabelHeader;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DAVKOVEMAZANISOUBORUMAIN_H
