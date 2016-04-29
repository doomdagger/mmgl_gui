#ifndef AMBIENTLIGHTDIALOG_H
#define AMBIENTLIGHTDIALOG_H

#include <QDialog>

namespace Ui {
class AmbientLightDialog;
}

class AmbientLightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AmbientLightDialog(QWidget *parent = 0);
    ~AmbientLightDialog();

    float getR();
    float getG();
    float getB();

private:
    Ui::AmbientLightDialog *ui;
};

#endif // AMBIENTLIGHTDIALOG_H
