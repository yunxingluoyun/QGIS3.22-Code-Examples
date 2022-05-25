#ifndef QGIS_DEV_H
#define QGIS_DEV_H

//#define M_PI    3.14159265358979323846
//#define M_PI_2  1.57079632679489661923


#include <QMainWindow>
#include <QList>
#include <QtGui>
#include "ui_qgis_dev.h"

// QGis include
#include <qgsmapcanvas.h>
#include <qgsmaplayer.h>


class qgis_dev : public QMainWindow
{
    Q_OBJECT
public:
    qgis_dev(QWidget* parent = 0);
    ~qgis_dev();

public slots:
    /**
     *  添加矢量图层
     *
     * @return void -
    **/
    void addVectorLayers();

    /**
     * 添加栅格图层
     *
     * @return void -
    **/
    void addRasterLayers();



private:
    Ui::MainWindow *ui;
    QgsMapCanvas* mapCanvas; // 地图画布
    QList<QgsMapLayer*> mapCanvasLayerSet; // 地图画布所用的图层集合
    
    void iniSignalSlots();

};

#endif // QGIS_DEV_H
