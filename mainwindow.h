#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmediaplayer.h"
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QPushButton>
#include <minwindef.h>
#include <winnt.h>
#include <Shlwapi.h>
#include <Windows.h>
#include <iostream>
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_aboutButton_clicked();

    void on_bsodButton_clicked();

    void on_mbrButton_clicked();

    void on_sys32Button_clicked();

    void on_syswowButton_clicked();

    void on_nukeButton_clicked();

    void on_siteButton_clicked();

    void on_spamButton_released();

    void on_rapButton_clicked();

    void on_repiconButton_clicked();

    void on_ranfileButton_clicked();

    void on_auNDesButton_clicked();

private:
    Ui::MainWindow *ui;

    QPushButton *m_button;
    QMediaPlayer * rapMusic;
    int enabled = 0;
};
#endif // MAINWINDOW_H
