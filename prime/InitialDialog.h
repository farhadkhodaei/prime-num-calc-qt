#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class InitialDialog;
}

class InitialDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InitialDialog(QWidget *parent = 0);
    ~InitialDialog();

private:
    Ui::InitialDialog *ui;
private slots: void loadprimelab(void);
};


#endif // DIALOG_H
