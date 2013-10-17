#ifndef CREATEGENERLIZATIONMODE_H
#define CREATEGENERLIZATIONMODE_H
#include "mode.h"
#include "umlObject.h"
#include "generalization.h"
class sceneView;

class createGeneralizationMode : public mode
{
public:
	createGeneralizationMode(sceneView *canvas);
	~createGeneralizationMode();

	//sceneView *scene;

	void mousePressEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent);

protected:
private:
	QPointF startPos,endPos,movPos;
};

#endif CREATEGENERLIZATIONMODE_H