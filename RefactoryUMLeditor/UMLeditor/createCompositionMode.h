#ifndef CREATECOMPOSITIONMODE_H
#define CREATECOMPOSITIONMODE_H
#include "mode.h"
#include "umlObject.h"
#include "composition.h"
class sceneView;

class createCompositionMode : public mode
{
public:
	createCompositionMode(sceneView *canvas);
	~createCompositionMode();

	//sceneView *scene;

	void mousePressEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent);

protected:
private:
	QPointF startPos,endPos,movPos;
};

#endif CREATECOMPOSITIONMODE_H