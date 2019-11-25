#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Personnel.h"
#include"personneldialog.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabpersonnel->setModel(tmppersonnel.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
  Personnel p(id,nom,prenom);
  bool test=p.ajouter();
  if(test)
{ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Personnel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id->text().toInt();
bool test=tmppersonnel.supprimer(id);
if(test)
{ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                QObject::tr("Personnel supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_clicked()
{
/* personneldialog ;
 personneldialog->setModal(true);
 personneldialog->exec();*/

    personneldialog=new personnelDialog(this);
    personneldialog->show();
}
