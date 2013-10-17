#include "createSelectMode.h"
#include <QGraphicsSceneMouseEvent>
#include "sceneView.h"
class sceneView;

createSelectMode::createSelectMode(sceneView *canvas)
{
	scene = canvas;
}
createSelectMode::~createSelectMode()
{
}

void createSelectMode::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	QPointF scenePos = mEvent->scenePos();
	startPos = scenePos;
	if(scene->itemAt(scenePos.x(),scenePos.y())){
		umlObject *slob;
		slob = (umlObject *)scene->itemAt(scenePos.x(),scenePos.y());
		scene->slob = slob;
		scene->defaultmousePressEvent(mEvent);
	}else if(!scene->itemAt(scenePos.x(),scenePos.y())){		//«ö¤U¥ªÁäselect®ø¥¢
		QPainterPath  path;
		QPainter painter;
		path.addRect(0,0,0,0);
		scene->setSelectionArea(path);
	}
}
void createSelectMode::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
	scene->defaultmouseMoveEvent(mEvent);
}
void createSelectMode::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
	endPos = mEvent->scenePos();
	if(!scene->itemAt(endPos.x(),endPos.y())){
		QPainterPath  path;
		QPainter painter;
		path.addRect(startPos.x(),startPos.y(),endPos.x()-startPos.x(),endPos.y()-startPos.y());
		scene->setSelectionArea(path);

		scene->selected.append( scene->selectedItems() );
		//painter.drawRect(startPos.x(),startPos.y(),fabs(endPos.x()-startPos.x()),fabs(endPos.y()-startPos.y()));
	}
}