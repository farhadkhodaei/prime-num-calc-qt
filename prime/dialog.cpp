#include "dialog.h"
#include "dialog2.h"
#include "ui_dialog.h"
#include "ui_dialog2.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(newFunc()));
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::newFunc()
{
    Dialog2* d=new Dialog2(this);
    this->hide();
    d->exec();
    this->show();
}
