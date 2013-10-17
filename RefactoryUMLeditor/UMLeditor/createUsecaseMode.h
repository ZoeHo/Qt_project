#ifndef CREATEUSECASEMODE_H
#define CREATEUSECASEMODE_H
#include "mode.h"
#include "UsecaseObject.h"
class sceneView;

class createUsecaseMode : public mode
{
public:
	createUsecaseMode(sceneView *canvas);
	~createUsecaseMode();

	//sceneView *scene;

	void mousePressEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent);

protected:
private:
};

#endif CREATEUSECASEMODE_H