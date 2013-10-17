#include "createCompositionMode.h"
#include <QGraphicsSceneMouseEvent>
#include "sceneView.h"
class sceneView;

createCompositionMode::createCompositionMode(sceneView *canvas)
{
	scene = canvas;
}
createCompositionMode::~createCompositionMode()
{
}

void createCompositionMode::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	startPos = mEvent->scenePos();
	if(scene->itemAt(startPos.x(),startPos.y())){
		slob = (umlObject *)scene->itemAt(startPos.x(),startPos.y());
	}
}

void createCompositionMode::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
	movPos = mEvent->scenePos();
	scene->defaultmouseMoveEvent(mEvent);
}

void createCompositionMode::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
	QPointF scenePos = mEvent->scenePos();
	endPos = scenePos;

	if(scene->itemAt(startPos.x(),startPos.y()) && scene->itemAt(endPos.x(),endPos.y())){
		elob = (umlObject *)scene->itemAt(scenePos.x(),scenePos.y());

		composition *comLine=new composition();
		scene->addItem(comLine);
		comLine->findport(slob,elob,startPos,endPos);
	}
	if(!scene->itemAt(endPos.x(),endPos.y())){
			//this->removeItem(assoc);
	}	//如果不是在item的地方放掉則不成導引線的連線
}