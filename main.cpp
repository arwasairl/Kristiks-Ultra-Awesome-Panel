#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QMediaPlayer>
#include <errhandlingapi.h>
#include <synchapi.h>
#include <winerror.h>
#include <windows.h>
#include <antivm.hpp>

int main(int argc, char *argv[])
{
    CreateMutexA(0, FALSE, "Local\\$myprogram$");
    if(GetLastError() == ERROR_ALREADY_EXISTS) {
        MessageBoxW(NULL, L"An instance of KrabPanel is already running. Please quit that instance before starting a new one.", L"Multiple Instances", MB_OK | MB_ICONWARNING);
        return -1;
    }

    if (DetectVM::IsVboxVM() == true) {
        MessageBoxW(NULL, L"The program has detected VirtualBox.", L"VM Detected!", MB_OK | MB_ICONINFORMATION);
    }
    else if (DetectVM::IsVMwareVM() == true) {
        MessageBoxW(NULL, L"The program has detected VMWare.", L"VM Detected!", MB_OK | MB_ICONINFORMATION);
    }
    else {
        MessageBoxW(NULL, L"It is HIGHLY RECOMMENDED that you run this program in a Virtual Machine. Not doing so will result in damage to your main system.", L"VM Recommended!", MB_OK | MB_ICONINFORMATION);
    }

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "KrabPanel_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();

    return a.exec();

}
