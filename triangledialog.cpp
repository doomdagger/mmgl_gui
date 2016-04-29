#include "triangledialog.h"
#include "ui_triangledialog.h"

TriangleDialog::TriangleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TriangleDialog)
{
    ui->setupUi(this);
}

TriangleDialog::~TriangleDialog()
{
    delete ui;
}

float TriangleDialog::getX1() {
    return ui->x1->text().toFloat();
}

float TriangleDialog::getX2() {
    return ui->x2->text().toFloat();
}

float TriangleDialog::getX3() {
    return ui->x3->text().toFloat();
}

float TriangleDialog::getY1() {
    return ui->y1->text().toFloat();
}

float TriangleDialog::getY2() {
    return ui->y2->text().toFloat();
}

float TriangleDialog::getY3() {
    return ui->y3->text().toFloat();
}

float TriangleDialog::getZ1() {
    return ui->z1->text().toFloat();
}

float TriangleDialog::getZ2() {
    return ui->z2->text().toFloat();
}

float TriangleDialog::getZ3() {
    return ui->z3->text().toFloat();
}
