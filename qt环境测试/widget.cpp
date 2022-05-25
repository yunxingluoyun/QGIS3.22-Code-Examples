#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent):
	QWidget(parent), ui(new Ui::Widget)
{
	//实现了窗体上的组件的创建、属性设置、信号与槽的关联。
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}