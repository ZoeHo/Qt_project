#include "createUsecaseMode.h"
#include <QGraphicsSceneMouseEvent>
#include "sceneView.h"
class sceneView;

createUsecaseMode::createUsecaseMode(sceneView *canvas)
{
	scene = canvas;
}
createUsecaseMode::~createUsecaseMode()
{
}

void createUsecaseMode::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	QPointF scenePos = mEvent->scenePos();

	usecaseObject *uobj = new usecaseObject();
	uobj->paintitem(scenePos);
	uobj->updatePortPos(scenePos);
	scene->addItem(uobj);
}
void createUsecaseMode::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
}
void createUsecaseMode::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
}