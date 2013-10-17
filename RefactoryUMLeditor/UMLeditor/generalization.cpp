#include "generalization.h"
#include <math.h>

generalization::generalization()
{
}

generalization::~generalization()
{
}


void generalization::findport(umlObject *startItem,umlObject *endItem,QPointF startPos,QPointF endPos)
{
	startPort=getport(startItem,startPos);
	endPort=getport(endItem,endPos);
	startPort->addLine(this);
	endPort->addLine(this);
	
	
	/*this->translate(startPort->itempos.x(),startPort->itempos.y());
	float ro=(endPort->itempos.y()-startPort->itempos.y())/(endPort->itempos.x()-startPort->itempos.x());
	//this->rotate(ro/(3.14/180)); //±×²v= h/w /(pi/180)
	//this->translate(-20, 0);
	this->rotate(atan(ro)*180/3.14);*/

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
}

void generalization::updateLine(QPointF movpos)  //modify
{
	this->setLine(startPort->itempos.x(),startPort->itempos.y(),
				  endPort->itempos.x(),endPort->itempos.y());
}