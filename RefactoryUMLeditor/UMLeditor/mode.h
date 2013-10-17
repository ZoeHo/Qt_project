#ifndef MODE_H
#define MODE_H
#include <QGraphicsSceneMouseEvent>
#include "umlObject.h"
class sceneView;

class mode
{
public:
	mode();
	mode(sceneView *canvas);
	~mode();
	sceneView *scene;
	int modeName;
	umlObject *slob,*elob;

	virtual void mousePressEvent(QGraphicsSceneMouseEvent *mEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent);

protected:
	QPointF startPos,endPos;
private:
	enum modeName{classMode=1,usecaseMode,selectMode,associationMode,generalizationMode,compositionMode};
	
};

#endif //MODE_H