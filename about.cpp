#include "about.h"
#include "ui_about.h"
#include <winDark.h>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:rgb(35, 35, 35)");
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    if(winDark::isDarkTheme())
        winDark::setDark_Titlebar(reinterpret_cast<HWND>(winId()));
}

about::~about()
{
    delete ui;
}

void about::on_pushButton_clicked()
{
    about::close();
}

