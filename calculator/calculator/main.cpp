#include "calculator.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);		//Qt�����l��
	calculator calc;
	calc.setFixedSize(220,280);

	calc.show();
	return app.exec();			//�B�z�ƥ�j��(main loop)
}
