//#define _USE_MATH_DEFINES
//#include <cmath>
#include <QApplication>
#include "widget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    //创建一个窗口，作为输入框的父窗口
    Widget w;
    // 显示窗口
    w.show();
    return app.exec();
}
