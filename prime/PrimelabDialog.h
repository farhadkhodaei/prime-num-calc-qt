#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class PrimelabDialog;
}

class PrimelabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrimelabDialog(QWidget *parent = 0);
    ~PrimelabDialog();
public slots: void TimerEvent();

private:
    Ui::PrimelabDialog *ui;
    int progressrvalue;
    int canceled;
#define MAX_NUMBER_OF_PRIMES 10000000
    int primes[MAX_NUMBER_OF_PRIMES];
private slots:
    void primecheck_func(void);
    void cancel_func(void);
};

#endif // DIALOG_H
