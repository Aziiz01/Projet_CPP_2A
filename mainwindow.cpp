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
    Materiels M2;
    ui->setupUi(this);
    ui->tab_Materiels->setModel(M1.afficher());
    ui->comboBox->addItems(M2.lister());
    ui->le_code ->setValidator(new QIntValidator(0, 9999999, this));
    ui->la_quantite ->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_fournisseur ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
    ui->l_intitule ->setValidator(new QRegExpValidator(QRegExp("[A-Za-z- _]+"), this ));
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

       ui->le_code->clear();
       ui->le_fournisseur->clear();
       ui->l_intitule->clear();
       ui->la_quantite->clear();
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                   QObject::tr("ajout non effectue\n"
                               "click cancel te exit."), QMessageBox::Cancel);
    ui->le_code->clear();
    ui->le_fournisseur->clear();
    ui->l_intitule->clear();
    ui->la_quantite->clear();

}

void MainWindow::on_ButtonSupprimer_clicked()
{
    Materiels M2;
    M2.setcode_mat(ui->comboBox->currentText().toInt());
    bool test=M2.supprimer(M2.getcode_mat());
    QMessageBox msgBox;

    if(test)
    {
        ui->comboBox->addItems(M1.lister());
        ui->tab_Materiels->setModel(M1.afficher());
       ui->comboBox->clear();
        ui->tab_Materiels->setModel(M2.afficher());
        msgBox.setText("suppression avec succes");
        ui->tab_Materiels->setModel(M1.afficher())    ;
        ui->comboBox->clear();
    }
    else
    msgBox.setText("echec de suppression");
    msgBox.exec();
}



void MainWindow::on_Button_Modification_clicked()
{
    int code_mat = ui->le_code->text().toInt();
    QString fournisseur= ui->le_fournisseur->text();
     QString intitule_mat= ui->l_intitule->text();
     int quantite_mat = ui->la_quantite->text().toInt();

    Materiels c(intitule_mat, fournisseur, code_mat, quantite_mat);
    bool test=c.modifier(code_mat);
    if(test)
    {

        ui->tab_Materiels->setModel(c.afficher());//refresh

               QMessageBox::information(nullptr, QObject::tr("effectué"),
                    QObject::tr(" Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
               ui->le_code->clear();
               ui->le_fournisseur->clear();
               ui->l_intitule->clear();
               ui->la_quantite->clear();
   }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                    QObject::tr("non modifié !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_code->clear();
        ui->le_fournisseur->clear();
        ui->l_intitule->clear();
        ui->la_quantite->clear();



    }

}



void MainWindow::on_trier_clicked()
{
     ui->tab_Materiels->setModel(M1.trier_alphapetique());
}


void MainWindow::on_recherche_editingFinished()
{
    QString intitule_mat= ui->recherche->text();


     ui->tab_Materiels->setModel(M1.rechercher( intitule_mat));

         bool test=M1.rechercher( intitule_mat);

         if(test)
         {


             ui->tab_Materiels->setModel(M1.rechercher(intitule_mat));

         }

}

void MainWindow::on_pb_statistique_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

