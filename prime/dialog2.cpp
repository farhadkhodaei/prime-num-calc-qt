#include "dialog2.h"
#include "ui_dialog2.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTimer>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(newFunc()));
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerEvent()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(cancl()));
    timer->start(1);
    ui->label_3->hide();
    ui->pushButton_2->hide();
    canceled=0;
    ui->progressBar->setValue(0);
    prvalue=0;
    ui->progressBar->setValue(prvalue);

}

Dialog2::~Dialog2()
{
    delete ui;
}
void Dialog2::newFunc()
{
    int m, i,i1, i2, ip1, ip2;

    QString ch, st, svm, svm2, ii, ii2, filenm;
    int j,k;

    ii=ui->textEditFrom->toPlainText();
    ii2=ui->textEditTo->toPlainText();
    i1=ii.toInt();
    i2=ii2.toInt();
    i=i1-1;
    if (i<1)i=1;


    filenm = QFileDialog::getSaveFileName(this, tr("Save File"),
                                          "primary.txt",
                                          tr("Text Files (*.txt)"));
    QFile file(filenm);
    if (!filenm.isEmpty()){
        canceled=0;
        QString sv;

        ui->label_3->setText("Running...");
        ui->label_3->show();
        ui->pushButton_2->show();
        qApp->processEvents();


        file.open(QIODevice::WriteOnly);
        m=0;ip1=0;ip2=0;

        do{
            i++;
            k=2;
            for(j=2;j<(i/2)+1;j++)
            {
                if((((int)(i/j))*j)==i)k++;
            }
            ip1=(i-i1)*100/(i2-i1);
            if(ip1>ip2){
                ip2=ip1;
                prvalue=ip1;
                qApp->processEvents();
                if (canceled==1)break;

            }
            if(k!=2)continue;
            m++;
           sv.sprintf("%20d         %20d\n",m,i);
           file.write(sv.toUtf8(),50);

        }while(i<i2);
        file.close();
        if(canceled==0)ui->label_3->setText("Finished.");
        else ui->label_3->setText("Canceled.");
        ui->progressBar->setValue(prvalue);

    }
}
void Dialog2::TimerEvent()
{
   ui->progressBar->setValue(prvalue);
}
void Dialog2::cancl()
{
    canceled = 1;
}

