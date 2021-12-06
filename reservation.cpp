#include "reservation.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDate>
#include <QTime>
#include <qcustomplot.h>
reservation::reservation()
{

}
/*int dat;
int time;
QString type;
float prix;*/
reservation::reservation(int id,QString dat,int time,QString type,float prix)
{
 this->id=id;
    this->dat=dat;
    this->time=time;
    this->prix=prix;
    this->type=type;

}
int reservation::get_id(){return id;}
/*int reservation::get_time(){return time;}
int reservation::get_date(){return dat;}
QString reservation::get_type(){return type;}
float reservation::get_prix(){return prix;}*/
void reservation::set_id(int id){this->id=id;}/*
void reservation::set_time(int time){this ->time=time;}
void reservation::set_date(int dat){this->dat=dat;}
void reservation::set_type(QString type){this->type=type;}
void reservation::set_prix(float prix){this->prix=prix;}*/
bool reservation::ajouter()
{
    QSqlQuery query;
QString pr= QString::number(prix);
         query.prepare("INSERT INTO reservation (id,time,dat,type,prix) "
                       "VALUES (:id,:time,:dat,:type,:prix)");
         query.bindValue(":id", id);
         query.bindValue(":time", time);
         query.bindValue(":dat", dat);
         query.bindValue(":type", type);
         query.bindValue(":prix", pr);
         return query.exec();


}

QStringList reservation::lister(){
QSqlQuery q;
q.prepare("select id from reservation");
q.exec();
QStringList l;
while(q.next()){
l<<q.value(0).toString();
}
return l;
}

bool reservation::supprimer(int id)
{
    QSqlQuery query;
QString id_string= QString::number(id);
         query.prepare(" Delete from RESERVATION where id=:id");
         query.bindValue(0, id);

         return query.exec();

}
QSqlQueryModel* reservation::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT* FROM RESERVATION");
         return model;
}


bool reservation :: modifier(int id)
{
     QSqlQuery query;


QString pr= QString::number(prix);
        QString res= QString::number(id);
        query.prepare("UPDATE RESERVATION SET time=:time,dat=:dat,type=:type,prix=:prix WHERE id=:id");
        query.bindValue(":id", id);
        query.bindValue(":time", time);
        query.bindValue(":dat", dat);
        query.bindValue(":type", type);
        query.bindValue(":prix", pr);



           return    query.exec();

}

QSqlQueryModel* reservation::trier_type()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  RESERVATION ORDER BY type  ");
    q->exec();
    model->setQuery(*q);
    return model;

}



QSqlQueryModel * reservation::recherche(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from RESERVATION where id like '%"+search+"%' ";
    qDebug()<<qry;
    model->setQuery(qry);
    return model;
}



void reservation::notification_ajoutReservation()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Reservations ","Nouvelle Reservation ajoutée ",QSystemTrayIcon::Information,150);
}





void reservation::notification_supprimerReservation(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Reservations ","MReservation Supprimée",QSystemTrayIcon::Information,150);
}



void reservation::notification_modifierReservation(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Reservation ","Une Reservation est modifiée",QSystemTrayIcon::Information,150);

}

