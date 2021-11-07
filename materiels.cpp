#include "materiels.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Materiels::Materiels()
{
  intitule_mat = " "; fournisseur = " ";
  code_mat = 0; quantite_mat = 0;
}
Materiels::Materiels(QString intitule_mat,QString fournisseur,int code_mat,int quantite_mat)
{
 this->intitule_mat=intitule_mat; this->fournisseur=fournisseur; this->code_mat=code_mat; this->quantite_mat=quantite_mat;
}
int Materiels::getcode_mat(){return code_mat;}
int Materiels::getquantite_mat(){return quantite_mat;}
QString Materiels::getintitule_mat(){return intitule_mat;}
QString Materiels::getfournisseur(){return fournisseur;}
void Materiels::setcode_mat(int code_mat){this->code_mat=code_mat;}
void Materiels::setquantite_mat(int quantite_mat){this->quantite_mat=quantite_mat;}
void Materiels::setintitule_mat(QString intitule_mat){this->intitule_mat=intitule_mat;}
void Materiels::setfournisseur(QString fournisseur){this->fournisseur=fournisseur;}
bool Materiels::ajouter()
{
    QSqlQuery query;
QString matricule_string= QString::number(code_mat);
         query.prepare("INSERT INTO Materiels (INTITULE_MAT, FOURNISSEUR, CODE_MAT, QUANTITE_MAT) "
                       "VALUES (:intitule_mat, :fournisseur, :code_mat, :quantite_mat)");
         query.bindValue(":intitule_mat", intitule_mat);
         query.bindValue(":fournisseur", fournisseur);
         query.bindValue(":code_mat", code_mat);
         query.bindValue(":quantite_mat", quantite_mat);
         return query.exec();


}
bool Materiels::supprimer(int code_mat)
{
    QSqlQuery query;
QString code_mat_string= QString::number(code_mat);
         query.prepare(" Delete from MATERIELS where code_mat =:code_mat");
         query.bindValue(0, code_mat);

         return query.exec();

}
QSqlQueryModel* Materiels::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT* FROM MATERIELS");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("intitule_mat"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("fournisseur"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("code_mat"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite_mat"));
         return model;
}


bool Materiels :: modifier(int code_mat)
{
     QSqlQuery query;



        QString res= QString::number(code_mat);
        query.prepare("UPDATE MATERIELS SET intitule_mat=:intitule_mat,fournisseur=:fournisseur,code_mat=:code_mat ,quantite_mat=:quantite_mat WHERE code_mat=:code_mat");
        query.bindValue(":code_mat", code_mat);
        query.bindValue(":intitule_mat", intitule_mat);
        query.bindValue(":fournisseur", fournisseur);
        query.bindValue(":quantite_mat", quantite_mat);



           return    query.exec();

}
