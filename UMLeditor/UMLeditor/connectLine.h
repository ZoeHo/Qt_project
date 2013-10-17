#ifndef CONNECTLINE_H
#define CONNECTLINE_H

#include <Qgraphicsview>
#include <QgraphicsItem>
#include <Qpainter>
#include "umlObject.h"
#include "port.h"
class port;

class connectLine :public QGraphicsLineItem
{
public:
	connectLine();
	~connectLine();

	virtual void findport(umlObject *startItem,umlObject *endItem,QPointF startPos,QPointF endPos);
	virtual void updateLine(QPointF movpos);
	port* getport(umlObject *item,QPointF pos);
	port *startPort,*endPort;

	QRectF connectLine::boundingRect() const
	{
		return path.boundingRect();
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
	QPointF spos,epos;

private:
};

#endif //CONNECTLINE_H