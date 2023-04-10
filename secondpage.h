#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QDialog>
#include <QModelIndex>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class SecondPage;
}

class SecondPage : public QDialog
{
    Q_OBJECT

public:
    explicit SecondPage(QWidget *parent = nullptr);
    ~SecondPage();

private slots:
    void on_exit_clicked();

    void on_pushButton_clicked();

private:
    Ui::SecondPage *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // SECONDPAGE_H
