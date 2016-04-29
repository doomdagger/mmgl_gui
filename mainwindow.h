#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QKeyEvent>
#include <cmath>
#include "spheredialog.h"
#include "pointlightdialog.h"
#include "cameradialog.h"
#include "ambientlightdialog.h"
#include "triangledialog.h"

#include <mmgl/mmgl.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addSphere(float x, float y, float z, float radius);

private slots:
    void on_actionNew_Scene_triggered();

    void on_actionNew_Scene_From_File_triggered();

    void on_actionNew_Sphere_triggered();

    void on_actionNew_Point_Light_triggered();

    void on_actionCamera_Configuration_triggered();

    void on_actionNew_Ambient_Light_triggered();

    void on_actionNew_Triangle_triggered();

    void on_actionSave_Scene_Image_triggered();

private:
    void reloadScene();
    void recreateScene();
    void recreateScene(const std::string &);

    void keyPressEvent(QKeyEvent *);

    Ui::MainWindow *ui;
    mmgl::Scene *scene;
    QGraphicsScene *graphicsScene;

};

#endif // MAINWINDOW_H
