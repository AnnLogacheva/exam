#include "secondpage.h"
#include "ui_secondpage.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QString>
#include <QList>
#include <iostream>
#include <QModelIndex>
#include "mainwindow.h"

SecondPage::SecondPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondPage)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./exDB.db");
    if(db.open()){
        qDebug("open");
    }
    else {
        qDebug("no open");
    }
    query = new QSqlQuery(db);
    //query->exec("CREATE TABLE film(The_name_of_the_movie TEXT, Duration_of_the_film TEXT);");
    model = new QSqlTableModel(this,db);
    model->setTable("gest");
    model->select();
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(model);
    QTableView *table = new QTableView();
    table->horizontalHeader()->setStretchLastSection(true);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
//    query->prepare("INSERT INTO film(The_name_of_the_movie, Duration_of_the_film) "
//              "VALUES (:site, :log);");
//    query->bindValue(":site", "Трио");
//    query->bindValue(":log", "3 часа 55 минут");
//    query->exec();
//  query->exec("INSERT INTO film(Название фильма, Продолжительность) VALUES ('','');");
//  query->exec("INSERT INTO cinima (Название фильма, Продолжительность) VALUES ('','');");
//  query->exec("INSERT INTO cinima (Название фильма, Продолжительность) VALUES ('','');");
}

SecondPage::~SecondPage()
{
    delete ui;
}

void SecondPage::on_exit_clicked()
{
    close();
    MainWindow w;
    w.setModal(true);
    w.exec();

}


void SecondPage::on_pushButton_clicked()
{
    model->setTable("film");
    model->select();
}

