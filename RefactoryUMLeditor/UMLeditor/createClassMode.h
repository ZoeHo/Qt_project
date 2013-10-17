#ifndef CREATECLASSMODE_H
#define CREATECLASSMODE_H
#include "mode.h"
#include "classObject.h"
class sceneView;

class createClassMode : public mode
{
public:
	createClassMode(sceneView *canvas);
	~createClassMode();

	//sceneView *scene;

	void mousePressEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent);

protected:
private:
};

#endif CREATECLASSMODE_H