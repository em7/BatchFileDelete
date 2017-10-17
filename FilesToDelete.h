/***************************************************************
 * Name:      FilesToDelete.cpp
 * Purpose:   Header for functions for working with file
 *            containing the files to be deleted.
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:   WTFPL
 **************************************************************/


#ifndef FILESTODELETE_H_INCLUDED
#define FILESTODELETE_H_INCLUDED

#include "wx_pch.h"

#include <wx/arrstr.h>

namespace FilesToDelete
{
    /** \brief Loads the file determined by the fileName
     *
     * \param fileName Name of the file to be read
     * \return The content of the file or nullptr if reading the file fails
     */
    wxString* LoadFile(const wxString& fileName);

    /** \brief Enumerates all files in directory
     *
     * \param dirName Name of the directory to enumerate files in
     * \return Array containing all files or nullptr if enumerating fails
     */
    wxArrayString* EnumAllFiles(const wxString& dirName);

    /** \brief Gets just the name of the file from full path
     *
     *  File must exist.
     *
     * \param fullPath Full, absolute path to the file
     * \return Just file name with extension or nullptr if fails
     */
    wxString* GetFileName(const wxString& fullPath);
}


#endif // FILESTODELETE_H_INCLUDED
