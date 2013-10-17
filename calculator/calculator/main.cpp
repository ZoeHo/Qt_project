#include "calculator.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);		//Qt元件初始化
	calculator calc;
	calc.setFixedSize(220,280);

	calc.show();
	return app.exec();			//處理事件迴圈(main loop)
}
