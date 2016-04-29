#ifndef TRIANGLEDIALOG_H
#define TRIANGLEDIALOG_H

#include <QDialog>

namespace Ui {
class TriangleDialog;
}

class TriangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TriangleDialog(QWidget *parent = 0);
    ~TriangleDialog();

    float getX1();
    float getX2();
    float getX3();
    float getY1();
    float getY2();
    float getY3();
    float getZ1();
    float getZ2();
    float getZ3();

private:
    Ui::TriangleDialog *ui;
};

#endif // TRIANGLEDIALOG_H
