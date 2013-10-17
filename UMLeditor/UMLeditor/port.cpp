#include "port.h"
#include "association.h"
class association;
#include "connectLine.h"
class connectLine;

port::port(QPointF originPos)
{
	itempos=originPos;
}

port::~port()
{
}

void port::setPosition(QPointF pos,QPointF originPos)
{
	itempos=pos+originPos;	
	if(lineList.size()!=0){
		//foreach(connectLine, lineList) { connectLine->updateLine(itempos); }
		foreach(lineItem, lineList) { lineItem->updateLine(itempos); }
	}
	
}

QPointF port::getpos()
{
	return itempos;
}

void port::addLine(connectLine *line)
{
	lineList.append(line);  //modify
	//connectLine=line;
	lineItem=line;
}