#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;

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
            switch(LOWORD(wParam))
            {

            }
        }
        return TRUE;
    }
    return FALSE;
}


void ListDir()
{

}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    WIN32_FIND_DATA _fdata;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    LARGE_INTEGER filesize;

    hInst=hInstance;
    InitCommonControls();

    hFind = FindFirstFile("D:\\GitHub\\KKJ",&_fdata);
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


    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
