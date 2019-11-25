#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Personnel.h"
#include <QMainWindow>
#include"personneldialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Personnel tmppersonnel;
    personnelDialog *personneldialog;
};

#endif // MAINWINDOW_H
