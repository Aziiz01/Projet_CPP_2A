#ifndef materiels_H
#define materiels_H
#include <QString>
#include <QSqlQueryModel>
#include <QMainWindow>

class Materiels
{
public:
    Materiels();
    Materiels(QString,QString,int,int);
    int getcode_mat();
    int getquantite_mat();
    QString getintitule_mat();
    QString getfournisseur();
    void setcode_mat(int);
    void setquantite_mat(int);
    void setintitule_mat(QString);
    void setfournisseur(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int code_mat);
      QStringList lister();
      QSqlQueryModel* trier_alphapetique();

       QSqlQueryModel* rechercher(QString);

private:
    QString intitule_mat,fournisseur;
    int code_mat;
    int quantite_mat;


};

#endif // materiels_H
