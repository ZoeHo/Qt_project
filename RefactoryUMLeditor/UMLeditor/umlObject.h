#ifndef UMLOBJECT_H
#define UMLOBJECT_H

#include <Qgraphicsview>
#include <QgraphicsItem>
#include <Qpainter>
#include "port.h"

class umlObject : public QGraphicsItem
{
public:
	umlObject();
	~umlObject();
	virtual void paintitem(QPointF pos);
	void getText(QString text);
	virtual void updatePortPos(QPointF pos);
	port *tport,*rport,*lport,*bport;
	QString itemName;
	
	QRectF umlObject::boundingRect() const
	{
		return path.boundingRect();
	}

	QPainterPath umlObject::shape() const
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
	QPointF itempos;
	
private:
	
	//int port[4][2];
};

#endif //UMLOBJECT_H