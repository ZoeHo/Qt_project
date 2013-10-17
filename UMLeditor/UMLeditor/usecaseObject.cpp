#include "usecaseObject.h"
#include <qpainter.h>

usecaseObject::usecaseObject()
{
	this->setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->setFlag(QGraphicsItem::ItemIsMovable, true);

	tport = new port(QPointF(60,0));  //120,70
	lport = new port(QPointF(0,35));
	rport = new port(QPointF(120,35));
	bport = new port(QPointF(60,70));
}

usecaseObject::~usecaseObject()
{
}

void usecaseObject::paintitem(QPointF pos)
{
	mpos=pos;
	this->translate(pos.x(),pos.y());

	brush.setColor(QColor::fromRgb(255,200,0,128));
	brush.setStyle( Qt::SolidPattern );
	path.addEllipse(0,0,120,70);
}
/*
void usecaseObject::getText(QString text)
{
	itemName=text;
}*/

void usecaseObject::updatePortPos(QPointF pos )
{
	tport->setPosition(pos,QPointF(60,0) );
	lport->setPosition(pos,QPointF(0,35) );
	rport->setPosition(pos,QPointF(120,35) );
	bport ->setPosition(pos,QPointF(60,70) );
}