/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:   WTFPL
 **************************************************************/

#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

#include <wx/wxprec.h>
#include <wx/gbsizer.h>
#include <wx/msgdlg.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/splitter.h>
#include <wx/hyperlink.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <wx/app.h>
#include <wx/arrstr.h>
#include <wx/filename.h>
#include <wx/dir.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifdef WX_PRECOMP

#endif // WX_PRECOMP

#endif // WX_PCH_H_INCLUDED
