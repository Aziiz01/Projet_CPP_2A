#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiels.h"
#include <QIntValidator>
#include <QApplication>
#include <QMessageBox>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_code ->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_Materiels->setModel(M1.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_Ajouter_clicked()
{
    QString intitule_mat =ui->l_intitule->text();
    QString fournisseur =ui->le_fournisseur->text();
    int code_mat =ui->le_code->text().toInt();
    int quantite_mat =ui->la_quantite->text().toInt();
    Materiels M(intitule_mat,fournisseur,code_mat,quantite_mat);
    bool test=M.ajouter();


    if(test)
    {
        ui->tab_Materiels->setModel(M1.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("ajout effectue\n"
                               "click cancel te exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                   QObject::tr("ajout non effectue\n"
                               "click cancel te exit."), QMessageBox::Cancel);

}

void MainWindow::on_ButtonSupprimer_clicked()
{
    Materiels M2; M2.setcode_mat(ui->le_code_sup->text().toInt());
    bool test=M2.supprimer(M2.getcode_mat());
    QMessageBox msgBox;

    if(test)
    {
        ui->tab_Materiels->setModel(M1.afficher());
        msgBox.setText("suppression avec succes");
    }
    else
    msgBox.setText("echec de suppression");
    msgBox.exec();

}

void MainWindow::on_Button_Modification_clicked()
{
    int code_mat = ui->le_code_2->text().toInt();
    QString fournisseur= ui->le_fournisseur_2->text();
     QString intitule_mat= ui->l_intitule_2->text();
     int quantite_mat = ui->la_quantite_2->text().toInt();

    Materiels c(intitule_mat, fournisseur, code_mat, quantite_mat);
    bool test=c.modifier(code_mat);
    if(test)
    {

        ui->tab_Materiels->setModel(c.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("effectué"),
                    QObject::tr(" Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
               ui->le_code_2->clear();
               ui->le_fournisseur_2->clear();
               ui->l_intitule_2->clear();
               ui->la_quantite_2->clear();
   }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                    QObject::tr("non modifié !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_code_2->clear();
        ui->le_fournisseur_2->clear();
        ui->l_intitule_2->clear();
        ui->la_quantite_2->clear();



    }

}
