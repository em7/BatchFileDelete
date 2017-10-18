/***************************************************************
 * Name:      ProjectConstants.h
 * Purpose:   Project constants like name, version...
 * Author:    em7 ()
 * Created:   2017-10-16
 * Copyright: em7 ()
 * License:   WTFPL
 **************************************************************/

 /*
In order to keep the usage of this application as simple as possible
i.e. single and small exe file, wxLocale was not used.

Instead of this, following hard-coded constants are used.

During the build, you should define
STRINGS_ENGLISH for English build
STRINGS_CZECH for Czech build
*/

#ifndef PROJECTCONSTANTS_H_INCLUDED
#define PROJECTCONSTANTS_H_INCLUDED

namespace C
{

const wchar_t* const Version = L"v. 1.0.0";

#ifdef STRINGS_ENGLISH
const wchar_t* const Project_name = L"Batch File Delete";
#endif

#ifdef STRINGS_CZECH
const wchar_t* const Project_name = L"Dávkové mazání souborů";
#endif

}



#endif // PROJECTCONSTANTS_H_INCLUDED
