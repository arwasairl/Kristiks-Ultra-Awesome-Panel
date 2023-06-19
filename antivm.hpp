#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdbool.h>

namespace DetectVM {
    bool IsVboxVM(){
        HANDLE handle = CreateFile(_T("\\\\.\\VBoxMiniRdrDN"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (handle != INVALID_HANDLE_VALUE){CloseHandle(handle); return true;}
        return false;
    }

    bool IsVMwareVM(){
        HKEY hKey = 0; DWORD dwType = REG_SZ; char buf[255] = {0}; DWORD dwBufSize = sizeof(buf);
        if( RegOpenKeyEx( HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\VMware, Inc.\\VMware Tools"), 0, KEY_QUERY_VALUE, &hKey ) == ERROR_SUCCESS ) {return true;}
        return false;
    }
}
