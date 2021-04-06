#include "izmjena.h"
#include "ui_izmjena.h"

izmjena::izmjena(QString iz,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::izmjena)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/roba/obaveze.db");
    if (!db.open()) {

        ui->status->setText("Baza nije povezana");
    }
    else  ui->status->setText("Baza je povezana");

    QSqlQuery qry;
    QDate d;
    qry.prepare("SELECT * FROM podsjetnik WHERE datum='"+iz+"';");
    if(qry.exec())
         {
           while(qry.next())
             {
                 ui->lineEdit_2->setText(qry.value(0).toString());
                 d=QDate::fromString(qry.value(1).toString());
                 ui->calendarWidget->setSelectedDate(d);
                 ui->lineEdit->setText(qry.value(2).toString());

            }
             qry.first();
             ui->upit->setText("Upit se može izvršiti :)");
    }
       else
          {
            ui->upit->setText("Upit se ne može izvršiti!");
    }

}

izmjena::~izmjena()
{
    delete ui;
}

void izmjena::on_pushButton_clicked()
{
    QString d, o, id;
    QDate dat;
    dat=ui->calendarWidget->selectedDate();
    d=dat.toString();
    o=ui->lineEdit->text();
    id=ui->lineEdit_2->text();
    QSqlQuery qry;
    qry.prepare("UPDATE podsjetnik SET datum='"+d+"', radnja='"+o+"' WHERE ID='"+id+"';");
    QMessageBox msgBox;
    msgBox.setText("Izmjena događaja.");
    msgBox.setInformativeText("Da li ste sigurni da želite izmjeniti događaja?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
        if(ret==QMessageBox::Yes)
                {
                if(qry.exec())
                    {
                        QMessageBox::information(this,"", "Slog izmjenjen!");
                        izmjena::close();
                    }
               else
                  {
                    QMessageBox::information(this,"", "Upit se ne može izvršiti!");
                }
                }
}
