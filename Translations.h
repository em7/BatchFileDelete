/***************************************************************
 * Name:      Translations.h
 * Purpose:   Translation const strings for whole application
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

namespace T
{

// GCC somehow states that following constants are unused.

#ifdef STRINGS_ENGLISH
const wchar_t* const Open_file_with_names_to_delete = L"Open file containing the names of files to delete";
const wchar_t* const Text_file_Open_Dialog_filter = L"Text files (*.txt)|*.txt|All files (*.*)|*.*";
const wchar_t* const Folder_to_delete_selected_files_from = L"Folder which selected files should be deleted from";
const wchar_t* const Do_you_really_want_to_delete_files_It_is_irreversible = L"Do you really want to delete selected files?\nThis action is irreversible.";
const wchar_t* const Delete_msg_box = L"Delete";
const wchar_t* const Cancel_deletion = L"Cancel deletion";
const wchar_t* const Could_not_delete_some_files = L"Could not delete some of the files.";
const wchar_t* const Selected_files_successfully_deleted = L"Selected files were successfully deleted.";
const wchar_t* const n1_Files = L"1. Files";
const wchar_t* const Set_files_you_need_to_delete = L"Write names of the files you need to delete.\n\nIf you already have a list of files to be deleted, you can load it here.\nThe file to load should be a plain text file (.txt) with\none file name per line.";
const wchar_t* const Load = L"&Load";
const wchar_t* const n2_Directory = L"2. Directory";
const wchar_t* const Open_directory_you_want_delete_files_from = L"Open the directory where you want to delete the files from.";
const wchar_t* const Open = L"&Open";
const wchar_t* const Check_files_to_be_deleted = L"Check the files to be deleted:";
const wchar_t* const Delete = L"&Delete";
#endif //STRINGS_ENGLISH

#ifdef STRINGS_CZECH
const wchar_t* const Open_file_with_names_to_delete = L"Otevřít soubor s názvy souborů pro smazání";
const wchar_t* const Text_file_Open_Dialog_filter = L"Textové soubory (*.txt)|*.txt|Všechny soubory (*.*)|*.*";
const wchar_t* const Folder_to_delete_selected_files_from = L"Složka, ze které smazat vybrané soubory";
const wchar_t* const Do_you_really_want_to_delete_files_It_is_irreversible = L"Opravdu chceš smazat vybrané soubory?\nTuto akci nelze vzít zpět.";
const wchar_t* const Delete_msg_box = L"Smazat";
const wchar_t* const Cancel_deletion = L"Zrušit akci";
const wchar_t* const Could_not_delete_some_files = L"Nepodařilo se smazat některé soubory.";
const wchar_t* const Selected_files_successfully_deleted = L"Vybrané soubory byly úspěšně smazány.";
const wchar_t* const n1_Files = L"1. Soubory";
const wchar_t* const Set_files_you_need_to_delete = L"Napiš názvy souborů, které chceš smazat.\n\nPokud již seznam souborů ke smazání máš, můžeš ho načíst.\nSoubor pro načtení musí být čistě textový soubor (.txt)\nobsahující jeden název na řádek.";
const wchar_t* const Load = L"&Načíst";
const wchar_t* const n2_Directory = L"2. Složka";
const wchar_t* const Open_directory_you_want_delete_files_from = L"Otevři složku, ze které chceš smazat soubory.";
const wchar_t* const Open = L"&Otevřít";
const wchar_t* const Check_files_to_be_deleted = L"Zaškrtni názvy souborů, které chceš smazat:";
const wchar_t* const Delete = L"&Smazat";
#endif //STRINGS_ENGLISH
}
