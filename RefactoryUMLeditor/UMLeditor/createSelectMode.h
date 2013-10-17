#ifndef CREATESELECTMODE_H
#define CREATESELECTMODE_H
#include "mode.h"
#include "classObject.h"
class sceneView;

class createSelectMode : public mode
{
public:
	createSelectMode(sceneView *canvas);
	~createSelectMode();

	//sceneView *scene;

	void mousePressEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent);

protected:
private:
	QPointF startPos,endPos,movPos;
};

#endif CREATESELECTMODE_H