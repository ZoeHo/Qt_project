#ifndef SCENEVIEW_H
#define SCENEVIEW_H
#include <QWidget>
#include <Qgraphicsview>
#include <QGraphicsSceneMouseEvent>
#include "usecaseObject.h"
#include "classObject.h"
#include "selectArea.h"
#include "association.h"
#include "generalization.h"
#include "composition.h"

class mode;

class sceneView : public QGraphicsScene
{
public: 
	sceneView(QWidget *parent);
	~sceneView();
	umlObject *slob,*elob;
	QList< QGraphicsItem * > selected;

	void setmode(int num, mode*);
	enum modeName{classMode=1,usecaseMode,selectMode,associationMode,generalizationMode,compositionMode};

	//void selectaGroup();
	void setText(QString text);

	mode *currentMode;
    
	void defaultmousePressEvent(QGraphicsSceneMouseEvent *mEvent);
	void defaultmouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
public:
	void mousePressEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent);

private:
	QPointF startPos;
	QPointF endPos;
	QPointF movPos;
	QString dialogText;
};

#endif //SCENEVIEW_H