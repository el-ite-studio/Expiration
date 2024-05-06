#include "expiration.h"

Expiration::Expiration(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.date->setDate(QDate::currentDate());
    connect(ui.PB21, SIGNAL(clicked()), this, SLOT(SetExpirationDate()));
    connect(ui.PB30, SIGNAL(clicked()), this, SLOT(SetExpirationDate()));
    connect(ui.PB45, SIGNAL(clicked()), this, SLOT(SetExpirationDate()));
    connect(ui.PB60, SIGNAL(clicked()), this, SLOT(SetExpirationDate()));
    connect(ui.PB90, SIGNAL(clicked()), this, SLOT(SetExpirationDate()));
    connect(ui.PB6M, SIGNAL(clicked()), this, SLOT(SetExpirationDate()));
    connect(ui.date, SIGNAL(dateChanged(QDate)), this, SLOT(dateChange(QDate)));
    ui.PB21->click();
}

Expiration::~Expiration()
{}

void Expiration::dateChange(QDate newDate) {
    if (ui.PB21->isChecked()) {
        ui.PB21->click();
    }
    else if (ui.PB30->isChecked()) {
        ui.PB30->click();
    }
    else if (ui.PB45->isChecked()) {
        ui.PB45->click();
    }
    else if (ui.PB60->isChecked()) {
        ui.PB60->click();
    }
    else if (ui.PB90->isChecked()) {
        ui.PB90->click();
    }
    else if (ui.PB6M->isChecked()) {
        ui.PB6M->click();
    }
}

void Expiration::ResetCheckedButtons() {
    ui.PB21->setChecked(false);
    ui.PB30->setChecked(false);
    ui.PB45->setChecked(false);
    ui.PB60->setChecked(false);
    ui.PB90->setChecked(false);
    ui.PB6M->setChecked(false);
}

void Expiration::SetExpirationDate() {
    QPushButton* button = (QPushButton*)sender();
    QDate expirationDate; 
    ResetCheckedButtons();
    button->setChecked(true);
    if (button->objectName() == "PB21") {
        expirationDate = ui.date->date().addDays(21);     
    }
    else if (button->objectName() == "PB30") {
        expirationDate = ui.date->date().addDays(30);
    }
    else if (button->objectName() == "PB45") {
        expirationDate = ui.date->date().addDays(45);
    }
    else if (button->objectName() == "PB60") {
        expirationDate = ui.date->date().addDays(60);
    }
    else if (button->objectName() == "PB90") {
        expirationDate = ui.date->date().addDays(90);
    }
    else if (button->objectName() == "PB6M") {
        expirationDate = ui.date->date().addMonths(6);
    }
    ui.expiration->setText(expirationDate.toString("dd.MM.yyyy"));
}
