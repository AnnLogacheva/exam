#include "errorenter.h"
#include "ui_errorenter.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QString>
#include <QList>
#include <iostream>
#include <QModelIndex>

ErrorEnter::ErrorEnter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorEnter)
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
    //query->exec("CREATE TABLE f(The_name_of_the_movie TEXT, Duration_of_the_film TEXT);");
    model = new QSqlTableModel(this,db);
    model->setTable("user");
    model->select();
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table->setModel(model);
    QTableView *table = new QTableView();
    table->horizontalHeader()->setStretchLastSection(true);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
}

ErrorEnter::~ErrorEnter()
{
    delete ui;
}
