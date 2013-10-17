#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <Qgraphicsview>
#include <QgraphicsItem>
#include <Qpainter>
#include "classObject.h"
#include "connectLine.h"
#include "port.h"
class port;

//#include <QtCore/QtDebug>

class association : public connectLine
{
public:
	association();
	~association();
	void paintassociateLine(QPointF startposx,QPointF endpos);
	void findport(umlObject *startItem,umlObject *endItem,QPointF startPos,QPointF endPos);
	void updateLine(QPointF movpos);
	//port* getport(umlObject *item,QPointF pos);
	port *startPort,*endPort;

	QRectF association::boundingRect() const
	{
		return path.boundingRect();
		//return QGraphicsLineItem::boundingRect();
		/*int lx;				//line boundingDect
		int rx;
		int ty;
		int by;

		if(spos.x()<epos.x()){lx=spos.x();}else{lx=epos.x();}
		if(spos.x()<epos.x()){rx=epos.x();}else{rx=spos.x();}
		if(spos.y()<epos.y()){ty=spos.y();}else{ty=epos.y();}
		if(spos.y()<epos.y()){by=epos.y();}else{by=spos.y();}

         return QRectF(lx, ty, rx - lx, by - ty);*/

	}

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
	{
		QPen pen;
		pen.setColor(QColor(0,0,0));
		pen.setWidth(3);
		pen.setStyle(Qt::SolidLine);

		//painter->drawRect( this->boundingRect() );
		painter->setPen(pen);
		//painter->fillPath( path, brush );
		//painter->drawLine(spos.x(),spos.y(),epos.x(),epos.y());

		painter->drawLine(startPort->itempos.x(),startPort->itempos.y(),
						  endPort->itempos.x(),endPort->itempos.y());
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

#endif //ASSOCIATION_H