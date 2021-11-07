#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "materiels.h"

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

    void on_ButtonSupprimer_clicked();

    void on_Button_Modification_clicked();

private:
    Ui::MainWindow *ui;
    Materiels M1;
};

#endif // MAINWINDOW_H
