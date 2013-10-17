#include "composition.h"

composition::composition()
{
}

composition::~composition()
{
}

void composition::findport(umlObject *startItem,umlObject *endItem,QPointF startPos,QPointF endPos)
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
		v.push_back( QPointF(endPort->itempos.x()-20, endPort->itempos.y()) );  //-------

		v.push_back( QPointF(endPort->itempos.x()-10, endPort->itempos.y()+6) );
		v.push_back( QPointF(endPort->itempos.x(), endPort->itempos.y()) );
		v.push_back( QPointF(endPort->itempos.x()-10, endPort->itempos.y()-6) );
		v.push_back( QPointF(endPort->itempos.x()-20, endPort->itempos.y()) );
	}
	path.addPolygon( QPolygonF( v ) );
}

void composition::updateLine(QPointF movpos)  //modify
{
	this->setLine(startPort->itempos.x(),startPort->itempos.y(),
				  endPort->itempos.x(),endPort->itempos.y());
}