#ifndef SPHEREDIALOG_H
#define SPHEREDIALOG_H

#include <QDialog>
#include <mmgl/surface/sphere.h>



namespace Ui {
class SphereDialog;
}

class MainWindow;

class SphereDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SphereDialog(QWidget *parent = 0);
    ~SphereDialog();

    float getX();
    float getY();
    float getZ();
    float getRadius();
private:
    Ui::SphereDialog *ui;
};

#endif // SPHEREDIALOG_H
