#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondpage.h"
#include "thirdpage.h"
#include <QMessageBox>
#include "errorenter.h"


MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
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
    query->exec("CREATE TABLE user(login TEXT, password TEXT);");
//    query->exec("INSERT INTO user(login, password) VALUES ('Anna','qwe123');");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_entor_clicked()
{
    QString login =ui->login->text();
    QString pass =ui->password->text();
    if (login=="Anna"&& pass=="qwe123")
    {
        close();
        SecondPage window1;
        window1.setModal(true);
        window1.exec();
    }
    else {
        QMessageBox::information(this,tr("Ошибка"),tr("Неверный логин или пароль"));
        return;
    }
}


void MainWindow::on_gest_clicked()
{
    close();
    ThirdPage win;
    win.setModal(true);
    win.exec();
}


void MainWindow::on_pushButton_clicked()
{
    close();
    ErrorEnter e;
    e.setModal(true);
    e.exec();
}

