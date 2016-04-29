#ifndef CAMERADIALOG_H
#define CAMERADIALOG_H

#include <QDialog>

namespace Ui {
class CameraDialog;
}

class CameraDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CameraDialog(QWidget *parent = 0);
    ~CameraDialog();

    void setX(float n);
    void setY(float n);
    void setZ(float n);
    void setDX(float n);
    void setDY(float n);
    void setDZ(float n);
    void setD(float n);
    void setIW(float n);
    void setIH(float n);
    void setNX(int n);
    void setNY(int n);

    float getX();
    float getY();
    float getZ();
    float getDX();
    float getDY();
    float getDZ();
    float getD();
    float getIW();
    float getIH();
    int getNX();
    int getNY();
private:
    Ui::CameraDialog *ui;
};

#endif // CAMERADIALOG_H
