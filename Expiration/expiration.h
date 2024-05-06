#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_expiration.h"

class Expiration : public QMainWindow
{
    Q_OBJECT

public:
    Expiration(QWidget *parent = nullptr);
    ~Expiration();

private:
    Ui::ExpirationClass ui;
    void ResetCheckedButtons();

private slots:
    void dateChange(QDate newDate);
    void SetExpirationDate();
};
