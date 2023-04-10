#ifndef ERRORENTER_H
#define ERRORENTER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class ErrorEnter;
}

class ErrorEnter : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorEnter(QWidget *parent = nullptr);
    ~ErrorEnter();

private:
    Ui::ErrorEnter *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // ERRORENTER_H
