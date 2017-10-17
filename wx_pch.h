/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:
 **************************************************************/

#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

// basic wxWidgets headers
#include <wx/wxprec.h>
#include <wx/gbsizer.h>
#include <wx/msgdlg.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/splitter.h>

#include <wx/file.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifdef WX_PRECOMP

#endif // WX_PRECOMP

#endif // WX_PCH_H_INCLUDED
