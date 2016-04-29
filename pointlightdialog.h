#ifndef POINTLIGHTDIALOG_H
#define POINTLIGHTDIALOG_H

#include <QDialog>

namespace Ui {
class PointLightDialog;
}

class PointLightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PointLightDialog(QWidget *parent = 0);
    ~PointLightDialog();

    float getX();
    float getY();
    float getZ();
    float getR();
    float getG();
    float getB();


private:
    Ui::PointLightDialog *ui;
};

#endif // POINTLIGHTDIALOG_H
