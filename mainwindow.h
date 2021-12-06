#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "reservation.h"
#include <QStringList>
#include <QMap>
#include <QSet>
#include <QtWidgets/QMessageBox>
#include <QPixmap>
#include <QFont>
#include <QColor>
#include <QStringList>
#include <QMap>
#include <QSet>
#include <QCommandLineParser>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_Ajouter_clicked();

     //void on_Button_commander_clicked();

    void on_ButtonSupprimer_clicked();

    void on_Button_Modification_clicked();

    void on_trier_clicked();


           // void on_recherche_editingFinished();

          //int verifierCompte();
void on_pushButton_clicked();
void on_Rechercher_textChanged(const QString &arg1);
void on_stat_clicked();
void on_rechercher_2_textChanged(const QString &arg1);

void on_comboBox_activated(const QString &arg1);

void on_le_time_userTimeChanged(const QTime &time);

void on_chat_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    reservation R1;



};


#endif // MAINWINDOW_H
