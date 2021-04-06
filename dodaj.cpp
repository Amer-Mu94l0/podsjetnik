#include "dodaj.h"
#include "ui_dodaj.h"

dodaj::dodaj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodaj)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/roba/obaveze.db");
    if (!db.open()) {
        ui->status->setText("Baza nije povezana");
    }
    else  ui->status->setText("Baza je povezana");

}

dodaj::~dodaj()
{
    delete ui;
}

void dodaj::on_pushButton_clicked()
{
    QString d,o;
    QDate dat=(ui->calendarWidget->selectedDate());
    d=dat.toString();
    o=ui->lineEdit->text();
    qDebug()<<d<<o;
    QSqlQuery qry;
    qry.prepare("insert into podsjetnik values(NULL,'"+d+"','"+o+"');");
    qDebug()<<qry.result()<<endl;
    qDebug()<<qry.exec()<<endl;
    dodaj::close();

}
