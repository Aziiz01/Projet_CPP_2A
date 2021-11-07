#include "gestion_bus.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Gestion_bus::Gestion_bus()
{
        nom ="" ;
        prenom ="" ;
        age =0;

}
Gestion_bus::Gestion_bus(QString nom,QString prenom, int age)
{

    this->nom=nom;
    this->prenom=prenom;
    this->age=age;

}
bool Gestion_bus ::  ajouter()
 {

}
QSqlQueryModel * Gestion_bus ::  afficher()
 {

}
bool Gestion_bus :: supprimer(int)
{

}
