#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    recreateScene();
    graphicsScene = new QGraphicsScene(this);
    scene->render();
    reloadScene();
    ui->graphicsView->setScene(graphicsScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Scene_triggered()
{
    recreateScene();
    scene->render();
    reloadScene();
}

void MainWindow::reloadScene() {
    const mmgl::RenderResult &result = scene->handle();
    QImage image(scene->camera().width(), scene->camera().height(), QImage::Format_RGB32);
    for (int i = 0; i < scene->camera().height(); ++i) {
        for (int j = 0; j < scene->camera().width(); ++j) {
            QRgb rgb = qRgb(static_cast<int>(result[i][j].x() * 255),
                            static_cast<int>(result[i][j].y() * 255),
                            static_cast<int>(result[i][j].z() * 255));
            image.setPixel(j, i, rgb);
        }
    }
    if (graphicsScene->items().length() != 0) {
        QGraphicsItem *_item = graphicsScene->items().at(0); graphicsScene->removeItem(_item); delete _item;
    }

    QPixmap pixmap = QPixmap::fromImage(image);
    graphicsScene->addPixmap(pixmap);
    graphicsScene->setSceneRect(pixmap.rect());
}

void MainWindow::recreateScene() {
    if (scene) {
        delete scene;
    }
    scene = new mmgl::Scene();
    scene->config().pixel_sampling_num(1).shadow_sampling_num(1);
}

void MainWindow::recreateScene(const std::string &file) {
    if (scene) {
        delete scene;
    }
    scene = new mmgl::Scene(file);
    scene->config().pixel_sampling_num(1).shadow_sampling_num(1);
}

void MainWindow::on_actionNew_Scene_From_File_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open Scene File"),
                QDir::currentPath(),
                tr("Scene files (*.txt)"));
    if (filename.isNull()) {
        return;
    }
    recreateScene(filename.toStdString());
    scene->render();
    reloadScene();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    mmgl::Point temp = scene->camera().eye();
    float r = std::sqrt(temp.x() * temp.x() + temp.y() * temp.y() + temp.z() * temp.z());
    float theta = std::atan(std::sqrt(temp.x() * temp.x() + temp.z() * temp.z()) / temp.y());
    float phi = std::atan(temp.z() / temp.x());

    if (event->key() == Qt::Key_W) {
        std::cout << "up" << std::endl;
        theta -= 3 * 3.1415926 / 180;
    } else if (event->key() == Qt::Key_S) {
        theta += 3 * 3.1415926 / 180;
    } else if (event->key() == Qt::Key_A) {
        phi += 3 * 3.1415926 / 180;
    } else if (event->key() == Qt::Key_D) {
        phi -= 3 * 3.1415926 / 180;
    } else if (event->key() == Qt::Key_Z) {
        r += 2;
    } else if (event->key() == Qt::Key_X) {
        r -= 2;
    }
    scene->camera().at(mmgl::Point(r*std::sin(theta)*std::cos(phi), r*std::cos(theta), r*std::sin(theta)*std::sin(phi)));
    scene->render();
    reloadScene();
}

void MainWindow::on_actionNew_Sphere_triggered()
{
    SphereDialog one(this);
    if (one.exec()) {
        addSphere(one.getX(), one.getY(), one.getZ(), one.getRadius());
    }
}

void MainWindow::addSphere(float x, float y, float z, float radius) {
    scene->sphere(x, y, z, radius);
    scene->render();
    reloadScene();
}

void MainWindow::on_actionNew_Point_Light_triggered()
{
    PointLightDialog one(this);
    if (one.exec()) {
        scene->pointLight(one.getX(), one.getY(), one.getZ(), one.getR(), one.getG(), one.getB());
        scene->render();
        reloadScene();
    }
}

void MainWindow::on_actionCamera_Configuration_triggered()
{
    CameraDialog one(this);
    one.setX(scene->camera().eye().x());
    one.setY(scene->camera().eye().y());
    one.setZ(scene->camera().eye().z());

    one.setNX(scene->camera().width());
    one.setNY(scene->camera().height());

    if (one.exec()) {
        scene->camera().config(one.getX(), one.getY(), one.getZ(), one.getD(), one.getDX(), one.getDY(), one.getDZ(), one.getNX(), one.getNY(), one.getIW(), one.getIH());
        scene->render();
        reloadScene();
    }
}

void MainWindow::on_actionNew_Ambient_Light_triggered()
{
    AmbientLightDialog one(this);
    if (one.exec()) {
        scene->ambientLight(one.getR(), one.getG(), one.getB());
        scene->render();
        reloadScene();
    }
}

void MainWindow::on_actionNew_Triangle_triggered()
{
    TriangleDialog one(this);
    if (one.exec()) {
        scene->triangle(one.getX1(), one.getY1(), one.getZ1(), one.getX2(), one.getY2(), one.getZ2(), one.getX3(), one.getY3(), one.getZ3());
        scene->render();
        reloadScene();
    }
}

void MainWindow::on_actionSave_Scene_Image_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                            tr("Save Scene File"),
                                            QDir::currentPath(),
                                            tr("All files (*.*)"));
    if (filename.isNull()) {
        return;
    }

    scene->save(filename.toStdString());
}
