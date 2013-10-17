#include "createClassMode.h"
#include <QGraphicsSceneMouseEvent>
#include "sceneView.h"
class sceneView;

createClassMode::createClassMode(sceneView *canvas)
{
	scene = canvas;
}
createClassMode::~createClassMode()
{
}

void createClassMode::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	QPointF scenePos = mEvent->scenePos();

	classObject *cobj =new classObject();
	cobj->paintitem(scenePos);
	cobj->updatePortPos(scenePos);
	scene->addItem(cobj);
}
void createClassMode::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
}
void createClassMode::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
}