#include "cameradialog.h"
#include "ui_cameradialog.h"

CameraDialog::CameraDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraDialog)
{
    ui->setupUi(this);
}

CameraDialog::~CameraDialog()
{
    delete ui;
}

void CameraDialog::setX(float n) {
    ui->x->setValue(n);
}

void CameraDialog::setY(float n) {
    ui->y->setValue(n);
}

void CameraDialog::setZ(float n) {
    ui->z->setValue(n);
}

void CameraDialog::setDX(float n) {
    ui->dx->setValue(n);
}

void CameraDialog::setDY(float n) {
    ui->dy->setValue(n);
}

void CameraDialog::setDZ(float n) {
    ui->dz->setValue(n);
}

void CameraDialog::setD(float n) {
    ui->d->setValue(n);
}

void CameraDialog::setIW(float n) {
    ui->iw->setValue(n);
}

void CameraDialog::setIH(float n) {
    ui->ih->setValue(n);
}

void CameraDialog::setNX(int n) {
    ui->nx->setValue(n);
}

void CameraDialog::setNY(int n) {
    ui->ny->setValue(n);
}

float CameraDialog::getX() {
    return ui->x->text().toFloat();
}

float CameraDialog::getY() {
    return ui->y->text().toFloat();
}

float CameraDialog::getZ() {
    return ui->z->text().toFloat();
}

float CameraDialog::getDX() {
    return ui->dx->text().toFloat();
}

float CameraDialog::getDY() {
    return ui->dy->text().toFloat();
}

float CameraDialog::getDZ() {
    return ui->dz->text().toFloat();
}

float CameraDialog::getD() {
    return ui->d->text().toFloat();
}

float CameraDialog::getIW() {
    return ui->iw->text().toFloat();
}

float CameraDialog::getIH() {
    return ui->ih->text().toFloat();
}

int CameraDialog::getNX() {
    return ui->nx->text().toInt();
}

int CameraDialog::getNY() {
    return ui->nx->text().toInt();
}
