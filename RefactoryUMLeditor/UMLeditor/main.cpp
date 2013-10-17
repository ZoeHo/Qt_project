#include "editorView.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	editorView *view = new editorView(&app);
	view->setFixedSize(1000,600);

	view->show();

	return app.exec();
}
