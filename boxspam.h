#ifndef BOXSPAM_H
#define BOXSPAM_H

#include <QDialog>

namespace Ui {
class boxSpam;
}

class boxSpam : public QDialog
{
    Q_OBJECT

public:
    explicit boxSpam(QWidget *parent = nullptr);
    ~boxSpam();

private:
    Ui::boxSpam *ui;
};

#endif // BOXSPAM_H
