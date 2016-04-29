#include "spheredialog.h"
#include "ui_spheredialog.h"

SphereDialog::SphereDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SphereDialog)
{
    ui->setupUi(this);
}

SphereDialog::~SphereDialog()
{
    delete ui;
}

float SphereDialog::getX() {
    return ui->x->text().toFloat();
}

float SphereDialog::getY() {
    return ui->y->text().toFloat();
}

float SphereDialog::getZ() {
    return ui->z->text().toFloat();
}

float SphereDialog::getRadius() {
    return ui->radius->text().toFloat();
}
