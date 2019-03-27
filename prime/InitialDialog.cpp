#include "InitialDialog.h"
#include "PrimelabDialog.h"
#include "ui_InitialDialog.h"
#include "ui_PrimelabDialog.h"

InitialDialog::InitialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitialDialog)
{
    ui->setupUi(this);
    connect(ui->PrimelabButton,SIGNAL(clicked(bool)),this,SLOT(loadprimelab()));
}

InitialDialog::~InitialDialog()
{
    delete ui;
}
void InitialDialog::loadprimelab()
{
    PrimelabDialog* d=new PrimelabDialog(this);
    this->hide();
    d->exec();
    this->show();
}
