#include "personneldialog.h"
#include "ui_personneldialog.h"



personnelDialog::personnelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personnelDialog)
{
    ui->setupUi(this);
}

personnelDialog::~personnelDialog()
{
    delete ui;
}


