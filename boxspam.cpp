#include "boxspam.h"
#include "ui_boxspam.h"

boxSpam::boxSpam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::boxSpam)
{
    ui->setupUi(this);
}

boxSpam::~boxSpam()
{
    delete ui;
}
