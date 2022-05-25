#define _USE_MATH_DEFINES
#include <cmath>
#include<QApplication>
#include<qgsapplication.h>
#include <qgsproviderregistry.h>
#include "qgis_dev.h"

int main(int argc, char* argv[])
{
    QgsApplication myApp(argc, argv, true);
    //QgsApplication::setPrefixPath("C:\\OSGeo4W\\apps\\qgis-ltr", true); // 注意：把这里的路径改成你电脑上Qgis的路径！！！
    QgsApplication::initQgis();
    QgsProviderRegistry::instance("C:/OSGeo4W/apps/qgis-ltr/plugins");
    qgis_dev* myQgis = new qgis_dev();
    myQgis->show();
    return myApp.exec();
}
