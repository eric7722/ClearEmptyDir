#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include <Commdlg.h>



HINSTANCE hInst;

void ListDir();

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
        {

        }
        return TRUE;

        case WM_CLOSE:
        {
          EndDialog(hwndDlg, 0);
        }
        return TRUE;

        case WM_COMMAND:
        {

            ListDir();
        }
        return TRUE;
    }
    return FALSE;
}


void ListDir()
{
    WIN32_FIND_DATA _fdata;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    OPENFILENAME of_name;

    GetOpenFileName(&of_name);
    hFind = FindFirstFile("D:\\GitHub\\KKJ\\*",&_fdata);

    if (INVALID_HANDLE_VALUE == hFind)
    {
     //   DisplayErrorBox(TEXT("FindFirstFile"));
        //return dwError;
    }

    do
   {
      if (_fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
      {
         //_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
         MessageBox(NULL,_fdata.cFileName,"NAME",MB_ICONWARNING | MB_DEFBUTTON2);
      }
      else
      {
         MessageBox(NULL,_fdata.cFileName,"NAME",MB_ICONWARNING | MB_DEFBUTTON2);
      }
   }
   while (FindNextFile(hFind, &_fdata) != 0);
   FindClose(hFind);

}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    hInst=hInstance;
    InitCommonControls();





    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
