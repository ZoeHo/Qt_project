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


class sceneView : public QGraphicsScene
{
public: 
	sceneView(QWidget *parent);
	~sceneView();
	usecaseObject *mob;
	classObject *cob;
	umlObject *slob,*elob;
	//QGraphicsLineItem *assoc;
	association *assoc;
	generalization *general;
	composition *compos;
	QGraphicsItem *item;
	QList< QGraphicsItem * > selected;

	void setn(int num);
	int modeNum;

	void selectaGroup();
	void setText(QString text);

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