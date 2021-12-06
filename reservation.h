#ifndef materiels_H
#define materiels_H
#include <QString>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QDate>
#include <QTime>
class reservation
{
public:
    reservation();
    reservation(int,QString,int,QString,float);
    int get_id();
    int get_time();
    int get_date();
    QString get_type();
    float get_prix();
    void set_id(int);
    void set_time(int);
    void set_date(int);
    void set_type(QString);
    void set_prix(float);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id);
      QStringList lister();
      QSqlQueryModel* trier_type();
//QSqlQueryModel * Materiels::Find_Materiels();
void on_Rechercher_textChanged(const QString &arg1);

       QSqlQueryModel* recherche(QString search);

void notification_modifierReservation();
void notification_supprimerReservation();
void notification_ajoutReservation();
private:
    int id;
    QString dat;
    int time;
    QString type;
    float prix;


};

#endif // materiels_H
