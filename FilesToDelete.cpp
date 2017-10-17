/***************************************************************
 * Name:      FilesToDelete.cpp
 * Purpose:   Functions for working with file containing the
 *            files to be deleted.
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:   WTFPL
 **************************************************************/

#include "FilesToDelete.h"

#include <wx/filename.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>

wxString* FilesToDelete::LoadFile(const wxString& fileName)
{
    wxFileName wFn(fileName);

    //if it's not a valid path on this platform, can't read the file
    //the same goes if it doesn't exist
    if (!(wFn.MakeAbsolute() && wFn.Exists() && wFn.IsFileReadable()))
    {
        return nullptr;
    }

    wxString *content = new wxString();
    wxFile in(wFn.GetFullPath());

    if (! in.ReadAll(content))
    {
        free(content);
        return nullptr;
    }

    return content;
}

