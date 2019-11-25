#include "Personnel.h"
#include <QDebug>
Personnel::Personnel()
{
id=0;
nom="";
prenom="";
}
Personnel::Personnel(int id,QString nom,QString prenom)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
}
QString Personnel::get_nom(){return  nom;}
QString Personnel::get_prenom(){return prenom;}
int Personnel::get_id(){return  id;}

bool Personnel::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Personnel (ID, NOM, PRENOM) "
                    "VALUES (:id, :nom, :prenom)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);

return    query.exec();
}

QSqlQueryModel * Personnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Personnel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

bool Personnel::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Personnel where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

