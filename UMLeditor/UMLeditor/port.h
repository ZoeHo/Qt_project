#ifndef PORT_H
#define PORT_H

#include <Qgraphicsview>
#include <QgraphicsItem>
#include <Qpainter>
#include <Qlist.h>
//#include "association.h"
class association;
class connectLine;

class port : public QGraphicsItem
{
public:
	port(QPointF originPos);
	~port();
	void setPosition(QPointF pos,QPointF originPos );
	//void addLine(association *line);
	void addLine(connectLine *line);
	QPointF getpos();
	QPointF itempos;

	QRectF port::boundingRect() const
	{
		return path.boundingRect();
	}

	QPainterPath port::shape() const
	{
		return path;
	}

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
	{
		painter->fillPath( path, brush );
	}

protected:
	QPen pen;
	QBrush	brush;
	QPainter painter;
	QPainterPath  path;
	QColor lineColor;
	//QList <association *> lineList;  //modify
	//association *connectLine;
	QList <connectLine *> lineList;
	connectLine *lineItem;

private:

};

#endif //UMLOBJECT_H