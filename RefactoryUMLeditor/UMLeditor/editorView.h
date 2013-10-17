#ifndef EDITORVIEW_H
#define EDITORVIEW_H

#include <QtGui/QMainWindow>
#include "ui_umleditor.h"
#include "usecaseObject.h"
#include "sceneView.h"
#include "mode.h"

#include "createClassMode.h"
#include "createUsecaseMode.h"
#include "createSelectMode.h"
#include "createAssociationMode.h"
#include "createGeneralizationMode.h"
#include "createCompositionMode.h"

class editorView : public QMainWindow
{
	Q_OBJECT

public:
	editorView(QApplication *app ,QWidget *parent = 0, Qt::WFlags flags = 0 );
	~editorView();
	sceneView *mscene;
	QList <QGraphicsItemGroup * > grouproot;
	//QGraphicsItemGroup *grouproot;
	mode *currentMode;

protected slots:
	void classClicked();
	void usecaseClicked();
	void selectClicked();
	void associationClicked();
	void generalizationClicked(); 
	void compositionClicked();

	void rename();
	void grouping();
	void ungroup();

private:
	Ui::UMLeditorClass ui;

	void setBottom(QWidget *);
	void setFileMenu(QWidget *, QApplication *);
	void setGraphicsView(QWidget *);

	void setmode(int);

	enum modeName{classMode=1,usecaseMode,selectMode,associationMode,generalizationMode,compositionMode};
};

#endif // EDITORVIEW_H
