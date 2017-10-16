/***************************************************************
 * Name:      DavkoveMazaniSouboruApp.cpp
 * Purpose:   Code for Application Class
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "DavkoveMazaniSouboruApp.h"

//(*AppHeaders
#include "DavkoveMazaniSouboruMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(DavkoveMazaniSouboruApp);

bool DavkoveMazaniSouboruApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	DavkoveMazaniSouboruFrame* Frame = new DavkoveMazaniSouboruFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
