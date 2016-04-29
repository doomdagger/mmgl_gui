#include "ambientlightdialog.h"
#include "ui_ambientlightdialog.h"

AmbientLightDialog::AmbientLightDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AmbientLightDialog)
{
    ui->setupUi(this);
}

AmbientLightDialog::~AmbientLightDialog()
{
    delete ui;
}

float AmbientLightDialog::getR() {
    return ui->r->text().toFloat();
}

float AmbientLightDialog::getG() {
    return ui->g->text().toFloat();
}

float AmbientLightDialog::getB() {
    return ui->b->text().toFloat();
}
