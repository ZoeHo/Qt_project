#include "createGeneralizationMode.h"
#include <QGraphicsSceneMouseEvent>
#include "sceneView.h"
class sceneView;

createGeneralizationMode::createGeneralizationMode(sceneView *canvas)
{
	scene = canvas;
}
createGeneralizationMode::~createGeneralizationMode()
{
}

void createGeneralizationMode::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	startPos = mEvent->scenePos();
	if(scene->itemAt(startPos.x(),startPos.y())){
		slob = (umlObject *)scene->itemAt(startPos.x(),startPos.y());
	}
}

void createGeneralizationMode::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
	movPos = mEvent->scenePos();
	scene->defaultmouseMoveEvent(mEvent);
}

void createGeneralizationMode::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
	QPointF scenePos = mEvent->scenePos();
	endPos = scenePos;

	if(scene->itemAt(startPos.x(),startPos.y()) && scene->itemAt(endPos.x(),endPos.y())){
		elob = (umlObject *)scene->itemAt(scenePos.x(),scenePos.y());

		generalization *geneLine=new generalization();
		scene->addItem(geneLine);
		geneLine->findport(slob,elob,startPos,endPos);
	}
	if(!scene->itemAt(endPos.x(),endPos.y())){
			//this->removeItem(assoc);
	}	//如果不是在item的地方放掉則不成導引線的連線
}