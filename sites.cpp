#include <iostream>
#include <windows.h>
#include <shellapi.h>

using namespace std;



void sites() {
    int random = rand() % 11;
    switch(random) {
        case 0:
            ShellExecute(NULL, L"open", L"https://www.shaadi.com/", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 1:
            ShellExecute(NULL, L"open", L"https://kristiklal.com", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 2:
            ShellExecute(NULL, L"open", L"https://nhentai.net", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 3:
            ShellExecute(NULL, L"open", L"https://animedao.to", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 4:
            ShellExecute(NULL, L"open", L"https://www.google.com/search?q=how+to+make+love+with+calculus+UWU&rlz=1C1ONGR_enUS1002US1002&oq=how+to+make+love+with+calculus+UWU&aqs=chrome..69i57.4838j0j1&sourceid=chrome&ie=UTF-8", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 5:
            ShellExecute(NULL, L"open", L"https://www.foxnews.com/", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 6:
            ShellExecute(NULL, L"open", L"https://gaycenter.org/", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 7:
            ShellExecute(NULL, L"open", L"https://www.aajtak.in/", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 8:
            ShellExecute(NULL, L"open", L"https://cafedelites.com/chicken-tikka-masala/", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 9:
            ShellExecute(NULL, L"open", L"https://www.wikihow.com/Get-a-Girlfriend-Fast", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 10:
            ShellExecute(NULL, L"open", L"https://www.google.com/search?q=tekken+hot+girl&rlz=1C1ONGR_enUS1002US1002&oq=tekken+hot+girl&aqs=chrome..69i57.2647j0j1&sourceid=chrome&ie=UTF-8", NULL, NULL, SW_SHOWNORMAL);
            break;
    }

}
