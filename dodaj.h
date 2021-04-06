#ifndef DODAJ_H
#define DODAJ_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSqlTableModel>

namespace Ui {
class dodaj;
}

class dodaj : public QDialog
{
    Q_OBJECT

public:
    explicit dodaj(QWidget *parent = nullptr);
    ~dodaj();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dodaj *ui;
};

#endif // DODAJ_H
