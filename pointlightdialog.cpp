#include "pointlightdialog.h"
#include "ui_pointlightdialog.h"

PointLightDialog::PointLightDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PointLightDialog)
{
    ui->setupUi(this);
}

PointLightDialog::~PointLightDialog()
{
    delete ui;
}

float PointLightDialog::getX() {
    return ui->x->text().toFloat();
}

float PointLightDialog::getY() {
    return ui->y->text().toFloat();
}

float PointLightDialog::getZ() {
    return ui->z->text().toFloat();
}

float PointLightDialog::getR() {
    return ui->r->text().toFloat();
}

float PointLightDialog::getG() {
    return ui->g->text().toFloat();
}

float PointLightDialog::getB() {
    return ui->b->text().toFloat();
}
