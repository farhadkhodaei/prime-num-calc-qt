#include "PrimelabDialog.h"
#include "ui_PrimelabDialog.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTimer>

PrimelabDialog::PrimelabDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrimelabDialog)
{
    ui->setupUi(this);
    connect(ui->Execute,SIGNAL(clicked(bool)),this,SLOT(primecheck_func()));
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerEvent()));
    connect(ui->StopButton,SIGNAL(clicked(bool)),this,SLOT(cancel_func()));
    timer->start(1);
    ui->Status->hide();
    ui->StopButton->hide();
    canceled=0;
    ui->ProgressBar->setValue(0);
    progressrvalue=0;
    ui->ProgressBar->setValue(progressrvalue);

}

PrimelabDialog::~PrimelabDialog()
{
    delete ui;
}
void PrimelabDialog::primecheck_func()
{
    int row, counter, fromnum, tonum, progress, progressupdated;

    QString fromnum_str, tonum_str, filename;
    int dividedby,dividables;

    fromnum_str=ui->FromNumEntrance->toPlainText();
    tonum_str=ui->ToNumEntrance->toPlainText();
    fromnum=fromnum_str.toInt();
    tonum=tonum_str.toInt();
    counter=fromnum-1;
    if (counter<1)counter=1;


    filename = QFileDialog::getSaveFileName(this, tr("Save File"),
                                          "prime.txt",
                                          tr("Text Files (*.txt)"));
    QFile file(filename);
    if (!filename.isEmpty()){
        canceled=0;
        QString texttowrite;

        ui->Status->setText("Running...");
        ui->Status->show();
        ui->StopButton->show();
        qApp->processEvents();


        file.open(QIODevice::WriteOnly);
        row=0;progress=0;progressupdated=0;

        do{
            counter++;
            dividables=2;
            for(dividedby=2;dividedby<(counter/2)+1;dividedby++)
            {
                if((((int)(counter/dividedby))*dividedby)==counter)dividables++;
            }
            progress=(counter-fromnum)*100/(tonum-fromnum);
            if(progress>progressupdated){
                progressupdated=progress;
                progressrvalue=progress;
                qApp->processEvents();
                if (canceled==1)break;

            }
            if(dividables!=2)continue;
            row++;
           texttowrite.sprintf("%20d         %20d\n",row,counter);
           file.write(texttowrite.toUtf8(),50);

        }while(counter<tonum);
        file.close();
        if(canceled==0)ui->Status->setText("Finished.");
        else ui->Status->setText("Canceled.");
        ui->ProgressBar->setValue(progressrvalue);

    }
}
void PrimelabDialog::TimerEvent()
{
   ui->ProgressBar->setValue(progressrvalue);
}
void PrimelabDialog::cancel_func()
{
    canceled = 1;
}

