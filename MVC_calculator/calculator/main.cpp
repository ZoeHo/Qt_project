#include "model.h"
#include "view.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);		//Qt元件初始化

	calculatorModel *model = new calculatorModel();
	calculatorView *view = new calculatorView(model);
	view->setFixedSize(220,280);
	view->show();

	return app.exec();			//處理事件迴圈(main loop)
}
