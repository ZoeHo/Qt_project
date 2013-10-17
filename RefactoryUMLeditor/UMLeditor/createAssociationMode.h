#ifndef CREATEASSOCIATIONMODE_H
#define CREATEASSOCIATIONMODE_H
#include "mode.h"
#include "umlObject.h"
#include "association.h"
class sceneView;

class createAssociationMode : public mode
{
public:
	createAssociationMode(sceneView *canvas);
	~createAssociationMode();

	//sceneView *scene;

	void mousePressEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent);

protected:
private:
	QPointF startPos,endPos,movPos;
};

#endif CREATEASSOCIATIONMODE_H