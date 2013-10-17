#include "mode.h"
#include "sceneView.h"
class sceneView;
#include <QGraphicsSceneMouseEvent>

mode::mode()
{
}

mode::mode(sceneView *canvas)
{
	scene = canvas;
}

mode::~mode()
{
}


void mode::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	startPos = mEvent->scenePos();

	/*switch (modeName)
	{
	case classMode: 
		createClassItem(startPos);
		break;
	case usecaseMode:
		createUsecaseItem(startPos);
		break;
	case selectMode:
		doSelection(mEvent);
		break;
	default:
		break;
	}*/
}

void mode::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
	/*if(modeName!=classMode && modeName !=usecaseMode){
		scene->defaultmouseMoveEvent(mEvent);
	}*/
}

void mode::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
	endPos = mEvent->scenePos();

	/*switch (modeName)
	{
	case selectMode:
		if(!scene->itemAt(endPos.x(),endPos.y())){
			selectaGroup();
		}
		break;
	case associationMode:
		createAssociateLine(endPos);
		break;
	case generalizationMode:
		createGeneralizeLine(endPos);
		break;
	case compositionMode:
		createCompositeLine(endPos);
		break;
	default:
		break;
	}*/
}