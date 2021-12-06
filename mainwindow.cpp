#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QIntValidator>
#include <QApplication>
#include <QMessageBox>
#include <QTableView>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QTextStream>
#include <QTextDocument>
#include <QSqlQuery>
#include <QtDebug>
#include <QVariant>
#include <QPainter>
#include <QString>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QRegExp>
#include <QApplication>
#include <QMessageBox>
#include <QTableView>
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    reservation R2;
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();
    QPieSeries *series = new QPieSeries();
        QSqlQuery q("select type,count(*) from reservation group by type");


         while(q.next())
         {series->append(q.value(0).toString()+": "+q.value(1).toString(),q.value(1).toInt());}
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques");
        chart->setBackgroundBrush(Qt::transparent);
        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->horizontalFrame);
        chartview->resize(400,300);

        chart->setAnimationOptions(QChart::AllAnimations);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        series->setLabelsVisible(true);


    ui->tab_Reservation->setModel(R1.afficher());
    ui->comboBox->addItems(R2.lister());

    ui->le_id ->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_Reservation->setModel(R1.afficher());


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_Ajouter_clicked()
{

    int id =ui->le_id->text().toInt();
    int time=ui->le_time->text().toInt();
    QString dat=ui->le_dat->text();
    QString type =ui->le_type->currentText();
    float prix =ui->le_pr->text().toFloat();


    reservation R(id,dat,time,type,prix);
    bool test=R.ajouter();


    if(test)
    {
        ui->tab_Reservation->setModel(R1.afficher());
R.notification_ajoutReservation();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("ajout effectue\n"
                               "click cancel te exit."), QMessageBox::Cancel);

       ui->le_id->clear();
       ui->le_time->clear();
       ui->le_pr->clear();
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                   QObject::tr("ajout non effectue\n"
                               "click cancel te exit."), QMessageBox::Cancel);
    ui->le_id->clear();
    ui->le_time->clear();
    ui->le_pr->clear();

}



void MainWindow::on_ButtonSupprimer_clicked()
{
    reservation R2;
    R2.set_id(ui->comboBox->currentText().toInt());
    bool test=R2.supprimer(R2.get_id());
    QMessageBox msgBox;

   R2.notification_supprimerReservation();

    if(test)
    {
        ui->comboBox->addItems(R1.lister());
        ui->tab_Reservation->setModel(R2.afficher());

        ui->tab_Reservation->setModel(R1.afficher())    ;
        msgBox.setText("suppression avec succes");
ui->comboBox->clear();

    }
    else

    msgBox.setText("echec de suppression");
    msgBox.exec();
}



void MainWindow::on_Button_Modification_clicked()
{

    int id =ui->le_id->text().toInt();
    int time=ui->le_time->text().toInt();
    QString dat=ui->le_dat->text();
    QString type =ui->le_type->currentText();
    float prix =ui->le_pr->text().toFloat();
    reservation c(id,dat,time,type,prix);
    bool test=c.modifier(id);
   c.notification_modifierReservation();
    if(test)
    {

        ui->tab_Reservation->setModel(c.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("effectué"),
                    QObject::tr(" Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
               ui->le_id->clear();
               ui->le_time->clear();
               ui->le_pr->clear();

   }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                    QObject::tr("non modifié !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_id->clear();
        ui->le_time->clear();
        ui->le_pr->clear();



    }

}



void MainWindow::on_trier_clicked()
{
     ui->tab_Reservation->setModel(R1.trier_type());
}









void MainWindow::on_pushButton_clicked()
{
    int i = 4000;


    QPdfWriter pdf("C:/Users/HP/Desktop/olympic-games.pdf");
    QPainter painter(&pdf);

    QSqlQuery query;
    query.prepare("select * from RESERVATION");
    painter.setPen(QPen(Qt::red));

    painter.drawText(100,3000,"id");
     painter.drawText(1300,3000,"time");
    painter.drawText(2100,3000,"date");
    painter.drawText(3200,3000,"type");
    painter.drawText(4300,3000,"prix");
    if (query.exec()){
    while (query.next())
     {
        painter.setPen(QPen(Qt::black));

     /*   QString quantite_mat=query.value(0).toString();
  painter.drawText(100,i,quantite_mat);
  QString  fournisseur=query.value(1).toString();
  painter.drawText(3200,i,);


    QString  code_mat=query.value(3).toString();
    painter.drawText(2100,i,code_mat);

    QString id_fournisseur=query.value(4).toString();
    painter.drawText(1300,i,id_fournisseur);
*/

    i = i +500;
    }
    }
  painter.end();

  QMessageBox::information(nullptr, QObject::tr("PDF "),
                                  QObject::tr("PDF Enregistré avec succes.\n" ), QMessageBox::AcceptRole);










}


void MainWindow::on_rechercher_2_textChanged(const QString &arg1)
{

            reservation R;
            ui->tab_Reservation->setModel(R.recherche(ui->rechercher_2->text()));



}


