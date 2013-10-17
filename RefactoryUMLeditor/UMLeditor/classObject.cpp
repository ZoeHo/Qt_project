#include "classObject.h"
#include <qpainter.h>

classObject::classObject()
{
	this->setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->setFlag(QGraphicsItem::ItemIsMovable, true);
	
	tport = new port(QPointF(45,0));  //90,100
	lport = new port(QPointF(0,50));
	rport = new port(QPointF(85,50));
	bport = new port(QPointF(45,95));
}

classObject::~classObject()
{
}

void classObject::paintitem(QPointF pos)
{
	mpos=pos;
	this->translate(pos.x(),pos.y());

	brush.setColor(QColor::fromRgb(0,0,255,128));
	brush.setStyle( Qt::SolidPattern );
	
	/*port[0][0]=pos.x()+45;	port[0][1]=pos.y();
	port[1][0]=pos.x();		port[1][1]=pos.y()+50;
	port[2][0]=pos.x()+85;	port[2][1]=pos.y()+50;
	port[3][0]=pos.x()+45;	port[3][1]=pos.y()+95;
	
	QVector<QPointF> v;
    {
      v.push_back( QPointF(pos.x(), pos.y()) );
      v.push_back( QPointF(pos.x(), pos.y()+100) );
      v.push_back( QPointF(pos.x()+90, pos.y()+100 ) );
      v.push_back( QPointF(pos.x()+90, pos.y() ) );
    }
    path.addPolygon( QPolygonF( v ) );
	painter.fillPath( path, brush );
	painter.drawRect(pos.x(),pos.y(),90,100);*/

	QVector<QPointF> v;
    {
      v.push_back( QPointF(0, 0) );
      v.push_back( QPointF(0, 100) );
      v.push_back( QPointF(90, 100 ) );
      v.push_back( QPointF(90, 0 ) );
    }
    path.addPolygon( QPolygonF( v ) );
}
/*
void classObject::getText(QString text)
{
	itemName=text;
}*/

void classObject::updatePortPos(QPointF pos )
{
	tport->setPosition(pos,QPointF(45,0) );
	lport->setPosition(pos,QPointF(0,50) );
	rport->setPosition(pos,QPointF(85,50) );
	bport ->setPosition(pos,QPointF(45,95) );
}
