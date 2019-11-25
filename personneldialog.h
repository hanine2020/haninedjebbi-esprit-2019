#ifndef PERSONNELDIALOG_H
#define PERSONNELDIALOG_H

#include <QDialog>

namespace Ui {
class personnelDialog;
}

class personnelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit personnelDialog(QWidget *parent = nullptr);
    ~personnelDialog();

//private slots:
   // void on_pushButton_clicked();

private:
    Ui::personnelDialog *ui;
};

#endif // PERSONNELDIALOG_H
