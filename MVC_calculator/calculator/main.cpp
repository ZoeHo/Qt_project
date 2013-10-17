#include "model.h"
#include "view.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);		//Qt�����l��

	calculatorModel *model = new calculatorModel();
	calculatorView *view = new calculatorView(model);
	view->setFixedSize(220,280);
	view->show();

	return app.exec();			//�B�z�ƥ�j��(main loop)
}
