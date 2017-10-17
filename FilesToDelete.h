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

namespace FilesToDelete
{
    /** \brief Loads the file determined by the fileName
     *
     * \param fileName Name of the file to be read
     * \return The content of the file or nullptr if reading the file fails
     */
    wxString* LoadFile(const wxString& fileName);

}


#endif // FILESTODELETE_H_INCLUDED
