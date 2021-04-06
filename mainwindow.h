#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
#include "ui_mainwindow.h"
#include "dodaj.h"
#include "izmjena.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calendarWidget_selectionChanged();

    void on_actiondodaj_triggered();

    void on_actionizmjena_triggered();

    void on_actionizmjena__triggered();

    void on_actionBrisanje_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
