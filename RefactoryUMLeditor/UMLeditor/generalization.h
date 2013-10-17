#ifndef GENERALIATION_H
#define GENERALIATION_H

#include <Qgraphicsview>
#include <QgraphicsItem>
#include <Qpainter>
#include "umlObject.h"
#include "connectLine.h"
#include "port.h"
class port;

class generalization : public connectLine
{
public:
	generalization();
	~generalization();
	void paintassociateLine(QPointF startposx,QPointF endpos);
	void findport(umlObject *startItem,umlObject *endItem,QPointF startPos,QPointF endPos);
	void updateLine(QPointF movpos);
	//port* getport(umlObject *item,QPointF pos);
	port *startPort,*endPort;

	QRectF generalization::boundingRect() const
	{
		return path.boundingRect();
	}

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
	{
		QPen pen;
		pen.setColor(QColor(0,0,0));
		pen.setWidth(3);
		pen.setStyle(Qt::SolidLine);

		//painter->drawRect( this->boundingRect() );  //µe¥XboundingRect
		painter->setPen(pen);
		//painter->fillPath( path, brush );

		QVector<QPointF> v;
		{
		v.push_back( QPointF(startPort->itempos.x(), startPort->itempos.y()) );
		v.push_back( QPointF(endPort->itempos.x()-15, endPort->itempos.y()) );  //-------

		v.push_back( QPointF(endPort->itempos.x()-15, endPort->itempos.y()+7.5) );
		v.push_back( QPointF(endPort->itempos.x(), endPort->itempos.y()) );
		v.push_back( QPointF(endPort->itempos.x()-15, endPort->itempos.y()-7.5) );
		v.push_back( QPointF(endPort->itempos.x()-15, endPort->itempos.y()) );
		}
		path.addPolygon( QPolygonF( v ) );
		painter->drawPolygon(QPolygonF( v ));
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

#endif //CONNECTLINEITEM_H