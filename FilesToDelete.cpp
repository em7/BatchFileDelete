/***************************************************************
 * Name:      FilesToDelete.cpp
 * Purpose:   Functions for working with the files to be deleted.
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:   WTFPL
 **************************************************************/

#include "FilesToDelete.h"

namespace FilesToDelete
{

wxString* LoadFile(const wxString& fileName)
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
        delete content;
        return nullptr;
    }

    return content;
}

wxArrayString* EnumAllFiles(const wxString& dirName)
{
    if (! wxDir::Exists(dirName))
    {
        return nullptr;
    }

    wxArrayString* files = new wxArrayString();
    wxDir::GetAllFiles(dirName, files, wxEmptyString, wxDIR_FILES);

    return files;
}

wxString* GetFileName(const wxString& fullPath)
{
    wxFileName wFn(fullPath);
    if (!(wFn.MakeAbsolute() && wFn.Exists() && wFn.IsFileReadable()))
    {
        return nullptr;
    }

    wxString* name = new wxString(wFn.GetFullName());
    return name;
}

const wxChar* GetEOL()
{
    return wxTextFile::GetEOL();
}

const wxString* FindMatchingFullPath(const wxString& fileName, const wxArrayString& allFullPaths)
{
    for (const wxString& fullPath : allFullPaths)
    {
        wxFileName fName(fullPath);
        if (fName.GetFullName() == fileName)
        {
            return &fullPath;
        }
    }

    return nullptr;
}

bool DeleteFile(const wxString& fullPath)
{
    if (! wxFileExists(fullPath))
    {
        return false;
    }

    if (! wxRemoveFile(fullPath))
    {
        return false;
    }

    return true;
}


} // namespace FilesToDelete
