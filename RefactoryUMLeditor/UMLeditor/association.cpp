#include "association.h"
#include "qline.h"

association::association()
{
}

association::~association()
{
}

void association::findport(umlObject *startItem,umlObject *endItem,QPointF startPos,QPointF endPos)
{
	startPort=getport(startItem,startPos);
	endPort=getport(endItem,endPos);
	startPort->addLine(this);
	endPort->addLine(this);
	
	QVector<QPointF> v;
	{
	v.push_back( QPointF(startPort->itempos.x(), startPort->itempos.y()) );
	v.push_back( QPointF(endPort->itempos.x(), endPort->itempos.y()) );
	}
	path.addPolygon( QPolygonF( v ) );
}

void association::updateLine(QPointF movpos)  //modify
{
	QVector<QPointF> v;
	{
	v.push_back( QPointF(startPort->itempos.x(), startPort->itempos.y()) );
	v.push_back( QPointF(endPort->itempos.x(), endPort->itempos.y()) );
	}
	path.addPolygon( QPolygonF( v ) );
	this->setLine(startPort->itempos.x(),startPort->itempos.y(),
				  endPort->itempos.x(),endPort->itempos.y());
}