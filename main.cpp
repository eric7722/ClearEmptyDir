#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include <Commdlg.h>
#include <Shlobj.h>


HINSTANCE hInst;

void ListDir(HWND hWnd);

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

            ListDir(hwndDlg);
        }
        return TRUE;
    }
    return FALSE;
}


void ListDir(HWND hWnd)
{
    char _path[MAX_PATH];
    BROWSEINFO bi = {0};
    bi.hwndOwner = hWnd;
    bi.lpszTitle = "Select folder";
    LPITEMIDLIST pIIL = SHBrowseForFolder(&bi);

    if(pIIL)
    {
        SHGetPathFromIDList(pIIL, _path );
        MessageBox(NULL,_path,"NAME",MB_ICONWARNING | MB_DEFBUTTON2);
    }
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    hInst=hInstance;
    InitCommonControls();

    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
