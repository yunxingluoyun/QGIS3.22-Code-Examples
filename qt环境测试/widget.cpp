#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget* parent):
	QWidget(parent), ui(new Ui::Widget)
{
	//ʵ���˴����ϵ�����Ĵ������������á��ź���۵Ĺ�����
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}