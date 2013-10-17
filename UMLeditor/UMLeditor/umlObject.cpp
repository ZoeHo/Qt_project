#include "umlObject.h"
#include <qpainter.h>

umlObject::umlObject()
{
	this->setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

umlObject::~umlObject()
{
}

void umlObject::paintitem(QPointF pos)
{
	itempos = pos;
}

void umlObject::getText(QString text)
{
	itemName=text;
}

void umlObject::updatePortPos(QPointF pos )
{
	tport->setPosition(pos,QPointF(45,0) );
	lport->setPosition(pos,QPointF(0,50) );
	rport->setPosition(pos,QPointF(85,50) );
	bport ->setPosition(pos,QPointF(45,95) );
}