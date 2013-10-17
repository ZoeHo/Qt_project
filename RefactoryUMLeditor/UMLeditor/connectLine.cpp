#include "connectLine.h"

connectLine::connectLine()
{
}

connectLine::~connectLine()
{
}

void connectLine::findport(umlObject *startItem,umlObject *endItem,QPointF startPos,QPointF endPos)
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

void connectLine::updateLine(QPointF movpos)  //modify
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

port* connectLine::getport(umlObject *item,QPointF pos)
{
	int mindis=fabs(item->tport->itempos.x()-pos.x())+fabs(item->tport->itempos.y()-pos.y());
	int mindisport=1;
	if(fabs(item->tport->itempos.x()-pos.x())+fabs(item->tport->itempos.y()-pos.y())<mindis){mindisport=1;} //tport
	if(fabs(item->lport->itempos.x()-pos.x())+fabs(item->lport->itempos.y()-pos.y())<mindis){
		mindis=fabs(item->lport->itempos.x()-pos.x())+fabs(item->lport->itempos.y()-pos.y());
		mindisport=2;
	} //lport
	if(fabs(item->rport->itempos.x()-pos.x())+fabs(item->rport->itempos.y()-pos.y())<mindis){
		mindis=fabs(item->rport->itempos.x()-pos.x())+fabs(item->rport->itempos.y()-pos.y());
		mindisport=3;
	} //rport
	if(fabs(item->bport->itempos.x()-pos.x())+fabs(item->bport->itempos.y()-pos.y())<mindis){
		mindis=fabs(item->bport->itempos.x()-pos.x())+fabs(item->bport->itempos.y()-pos.y());
		mindisport=4;
	} //bport

	if(mindisport==1){return item->tport;}
	else if(mindisport==2){return item->lport;}
	else if(mindisport==3){return item->rport;}
	else if(mindisport==4){return item->bport;}
}