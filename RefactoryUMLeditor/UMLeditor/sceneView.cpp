#include "sceneView.h"
#include "mode.h"
class mode;

sceneView::sceneView(QWidget *parent)
{
}

sceneView::~sceneView()
{
}

void sceneView::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	QPointF pos = mEvent->scenePos();
	startPos = mEvent->scenePos();
	currentMode->mousePressEvent(mEvent);
}

void sceneView::defaultmousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	this->QGraphicsScene::mousePressEvent(mEvent);
}

void sceneView::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
	movPos = mEvent->scenePos();
	currentMode->mouseMoveEvent(mEvent);
}

void sceneView::defaultmouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
	this->QGraphicsScene::mouseMoveEvent(mEvent);
}

void sceneView::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
	endPos = mEvent->scenePos();
	this->QGraphicsScene::mouseReleaseEvent(mEvent);

	currentMode->mouseReleaseEvent(mEvent);
}

void sceneView::setmode(int num, mode *cmode)
{
	currentMode = cmode;
	currentMode->modeName = num;
}

void sceneView::setText(QString text)
{
	dialogText=text;
}