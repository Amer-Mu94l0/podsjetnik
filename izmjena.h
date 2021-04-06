#ifndef IZMJENA_H
#define IZMJENA_H

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
class izmjena;
}

class izmjena : public QDialog
{
    Q_OBJECT

public:
    explicit izmjena(QString iz,QWidget *parent = nullptr);
    ~izmjena();

private slots:
    void on_pushButton_clicked();

private:
    Ui::izmjena *ui;
};

#endif // IZMJENA_H
