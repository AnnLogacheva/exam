#include "thirdpage.h"
#include "ui_thirdpage.h"
#include "mainwindow.h"

ThirdPage::ThirdPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdPage)
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
    //query->exec("CREATE TABLE gest(The_name_of_the_movie TEXT, Session_time TEXT, Place_in_the_hall TXT);");
    model = new QSqlTableModel(this,db);
    model->setTable("film");
    model->select();
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(model);
    QTableView *table = new QTableView();
    table->horizontalHeader()->setStretchLastSection(true);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
//    query->prepare("INSERT INTO gest(The_name_of_the_movie, Session_time, Place_in_the_hall) "
//              "VALUES (:site, :log, :pass);");
//    query->bindValue(":site", "Трио");
//    query->bindValue(":log", "11:00");
//    query->bindValue(":pass","7 ряд, 6 место");
//    query->exec();
}

ThirdPage::~ThirdPage()
{
    delete ui;
}

void ThirdPage::on_close_clicked()
{
    close();
    MainWindow w;
    w.setModal(true);
    w.exec();
}

