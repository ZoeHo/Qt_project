#include "createAssociationMode.h"
#include <QGraphicsSceneMouseEvent>
#include "sceneView.h"
class sceneView;

createAssociationMode::createAssociationMode(sceneView *canvas)
{
	scene = canvas;
}
createAssociationMode::~createAssociationMode()
{
}

void createAssociationMode::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	startPos = mEvent->scenePos();
	if(scene->itemAt(startPos.x(),startPos.y())){
		slob = (umlObject *)scene->itemAt(startPos.x(),startPos.y());
	}
}

void createAssociationMode::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
	movPos = mEvent->scenePos();
	scene->defaultmouseMoveEvent(mEvent);
}

void createAssociationMode::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
	QPointF scenePos = mEvent->scenePos();
	endPos = scenePos;

	if(scene->itemAt(startPos.x(),startPos.y()) && scene->itemAt(endPos.x(),endPos.y())){
		elob = (umlObject *)scene->itemAt(scenePos.x(),scenePos.y());

		association *assocLine=new association();
		scene->addItem(assocLine);
		assocLine->findport(slob,elob,startPos,endPos);
	}
	if(!scene->itemAt(endPos.x(),endPos.y())){
			//this->removeItem(assoc);
	}	//如果不是在item的地方放掉則不成導引線的連線
}