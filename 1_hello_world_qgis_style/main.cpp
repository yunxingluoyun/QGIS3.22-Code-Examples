#define _USE_MATH_DEFINES
#include <cmath>
#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgssinglesymbolrenderer.h>
#include <qgssymbol.h>
#include <qgsvectorlayer.h>
#include <qgsmapcanvas.h>
//
// Qt Includes
//
#include <QString>
#include <QApplication>
#include <QWidget>

int main(int argc, char** argv)
{
    // Start the Application
    QgsApplication app(argc, argv, true);

    QString myPluginsDir = "C:/OSGeo4W/apps/qgis-ltr/plugins";
    QString myLayerPath = "E:/shapefile/water.shp";
    QString myLayerBaseName = "water";
    QString myProviderName = "ogr";
    // Instantiate Provider Registry
    QgsProviderRegistry::instance(myPluginsDir);
    //qputenv("GDAL_DATA", "C:/OSGeo4W/share/gdal");
    // create a maplayer instance
    QgsVectorLayer* mypLayer =
        new QgsVectorLayer(myLayerPath, myLayerBaseName, myProviderName);
    QgsFeatureRenderer* mypRenderer = QgsFeatureRenderer::defaultRenderer(mypLayer->geometryType());
    //QgsSingleSymbolRenderer* mypRenderer = new QgsSingleSymbolRenderer(symbol_layers);
    QList <QgsMapLayer*> myLayerSet;
    mypLayer->setRenderer(mypRenderer);
    if (mypLayer->isValid())
    {
        qDebug("Layer is valid");
    }
    else
    {
        qDebug("Layer is NOT valid");
    }

    // Add the Vector Layer to the Layer Registry
    QgsProject::instance()->addMapLayer(mypLayer);
    // Add the Layer to the Layer Set
    myLayerSet.append(mypLayer);

    // Create the Map Canvas
    QgsMapCanvas* mypMapCanvas = new QgsMapCanvas();
    mypMapCanvas->setExtent(mypLayer->extent());
    mypMapCanvas->enableAntiAliasing(true);
    mypMapCanvas->setCanvasColor(QColor(255, 255, 255));
    mypMapCanvas->freeze(false);
    // Set the Map Canvas Layer Set
    mypMapCanvas->setLayers(myLayerSet);
    mypMapCanvas->setVisible(true);
    mypMapCanvas->refresh();

    // Start the Application Event Loop
    return app.exec();
}