#include "qgis_dev.h"
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

// QGis include
#include <qgsvectorlayer.h>
#include <qgsrasterlayer.h>

qgis_dev::qgis_dev(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mapCanvas = new QgsMapCanvas();
    this->setCentralWidget(mapCanvas);

    mapCanvas->enableAntiAliasing(true);
    mapCanvas->setCanvasColor(QColor(255, 255, 255));
    mapCanvas->setVisible(true);
    iniSignalSlots();

    ////// connections
    //QObject::connect(ui->actionAdd_Vector, SIGNAL(triggered()), this, SLOT(addVectorLayers()));
    //QObject::connect(ui->actionAdd_Raster, SIGNAL(triggered()), this, SLOT(addRasterLayers()));
}

qgis_dev::~qgis_dev()
{
    delete ui;
}

void qgis_dev::addVectorLayers()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("open vector"), "", "*.shp");
    QStringList temp = filename.split(QDir::separator());
    QString basename = temp.at(temp.size() - 1);
    //QgsVectorLayer* vecLayer = new QgsVectorLayer(filename, basename, "ogr", false);
    QgsVectorLayer* vecLayer = new QgsVectorLayer(filename, basename, "ogr");
    if (!vecLayer->isValid())
    {
        QMessageBox::critical(this, "error", "layer is invalid");
        return;
    }
    QgsProject::instance()->addMapLayer(vecLayer);
    mapCanvasLayerSet.append(vecLayer);
    mapCanvas->setExtent(vecLayer->extent());
    mapCanvas->setLayers(mapCanvasLayerSet);//
    mapCanvas->setVisible(true);
    mapCanvas->freeze(false);
    mapCanvas->refresh();

}

void qgis_dev::addRasterLayers()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("open vector"), "", "*.tif");
    QStringList temp = filename.split(QDir::separator());
    QString basename = temp.at(temp.size() - 1);
    QgsRasterLayer* rasterLayer = new QgsRasterLayer(filename, basename, "gdal");
    if (!rasterLayer->isValid())
    {
        QMessageBox::critical(this, "error", "layer is invalid");
        return;
    }

    QgsProject::instance()->addMapLayer(rasterLayer);
    mapCanvasLayerSet.append(rasterLayer);
    mapCanvas->setExtent(rasterLayer->extent());
    //mapCanvas->setLayerSet(mapCanvasLayerSet);
    mapCanvas->setLayers(mapCanvasLayerSet);
    mapCanvas->setVisible(true);
    mapCanvas->freeze(false);
    mapCanvas->refresh();
}

void qgis_dev::iniSignalSlots()
{
    connect(ui->actionAdd_Vector, SIGNAL(triggered()), this, SLOT(addVectorLayers()));
    connect(ui->actionAdd_Raster, SIGNAL(triggered()), this, SLOT(addRasterLayers()));
}