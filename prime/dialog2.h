#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
public slots: void TimerEvent();

private:
    Ui::Dialog2 *ui;
    int prvalue;
    int canceled;
private slots:
    void newFunc(void);
    void cancl(void);
};

#endif // DIALOG_H
