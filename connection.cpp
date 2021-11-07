#include "connection.h"
#include "materiels.h"
#include <QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("rimeh");//inserer nom de l'utilisateur
db.setPassword("rimeh08");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

