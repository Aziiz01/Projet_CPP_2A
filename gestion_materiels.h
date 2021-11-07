#ifndef GESTION_BUS_H
#define GESTION_BUS_H
#include <QString>
#include <QSqlQueryModel>

class Gestion_bus
{
    QString nom;
    QString prenom;
    int age;
public:
    Gestion_bus();
    Gestion_bus(QString ,QString ,int);
    int get_age();
    QString get_Nom();
    QString get_prenom ;
    void set_Nom(QString x)  ;
    void set_prenom(QString y)  ;
    void set_age(int z)  ;

    bool ajouter() ;
         QSqlQueryModel *  afficher()  ;
         bool supprimer(int);

};

#endif // GESTION_BUS_H
