#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dodaj.h"
#include "izmjena.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/roba/obaveze.db");
    if (!db.open()) {
        ui->status->setText("Baza nije povezana");
    }
    else  ui->status->setText("Baza je povezana");
    }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calendarWidget_selectionChanged()
{
     ui->listWidget->clear();
     qDebug()<<ui->calendarWidget->selectedDate();
     QString datum, radnja;
     QDate d=(ui->calendarWidget->selectedDate());
     datum=d.toString();

     QSqlQuery qry;
     qry.prepare("select radnja from podsjetnik where datum='"+datum+"';");
     qDebug()<<qry.exec()<<endl;

     while (qry.next()) {
             radnja = qry.value(0).toString();
             qDebug() << radnja;
         }
     if(radnja.isNull()) radnja="za ovaj datum nema događaja!";
     QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
     item->setText("datum: "+datum+"\n: "+radnja);


}

void MainWindow::on_actiondodaj_triggered()
{
    dodaj d;
    d.setModal(true);
    d.exec();
}

void MainWindow::on_actionizmjena__triggered()
{
    QString datum;
    QDate d=(ui->calendarWidget->selectedDate());
    datum=d.toString();
    izmjena i(datum);
    i.exec();
}

void MainWindow::on_actionBrisanje_triggered()
{
    QString datum;
    QDate d=(ui->calendarWidget->selectedDate());
    datum=d.toString();

    QMessageBox msgBox;

    QSqlQuery qry;
    qry.prepare("DELETE FROM podsjetnik WHERE datum='"+datum+"'");

    msgBox.setText("Brisanje događaja.");
    msgBox.setInformativeText("Da li ste sigurni da želite obrisati događaj?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
        if(ret==QMessageBox::Yes)
                {
                    QMessageBox::information(this,"", "Slog obrisan!");
                    qry.exec();
                 }
}
