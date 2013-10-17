#ifndef CLASSOBJECT_H
#define CLASSOBJECT_H

#include <Qgraphicsview>
#include <QgraphicsItem>
#include <Qpainter>
#include "umlObject.h"

class classObject : public umlObject
{
public:
	classObject();
	~classObject();
	void paintitem(QPointF pos);
	void updatePortPos(QPointF pos);
	//void getText(QString text);

	QRectF classObject::boundingRect() const
	{
		return path.boundingRect();
	}

	QPainterPath classObject::shape() const
	{
		return path;
	}

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
	{
		this->updatePortPos(this->scenePos());

		QPen pen;
		pen.setColor(QColor(0,0,255));
		pen.setWidth(2);
		pen.setStyle(Qt::SolidLine);

		painter->setPen(pen);
		
		painter->fillPath( path, brush );
		/*painter->drawLine(mpos.x(),mpos.y()+30,mpos.x()+90,mpos.y()+30);
		painter->drawLine(mpos.x(),mpos.y()+60,mpos.x()+90,mpos.y()+60);
		painter->drawRect(mpos.x(),mpos.y(),90,100);*/

		painter->drawLine(0,30,90,30);
		painter->drawLine(0,60,90,60);
		painter->drawRect(0,0,90,100);

		if(this->isSelected()){
			pen.setColor(QColor(0,255,0));
			/*painter->drawRect(mpos.x()+45,mpos.y()+2,2,2);
			painter->drawRect(mpos.x()+2,mpos.y()+50,2,2);
			painter->drawRect(mpos.x()+87,mpos.y()+50,2,2);
			painter->drawRect(mpos.x()+45,mpos.y()+97,2,2);*/
			painter->drawRect(45,2,2,2);
			painter->drawRect(2,50,2,2);
			painter->drawRect(87,50,2,2);
			painter->drawRect(45,97,2,2);
		}

		QFont font;
		font.setPointSize(18);
		painter->setFont(font);
		//painter->drawText(QPointF(mpos.x()+45-itemName.length()*6,mpos.y()+25),itemName);
		painter->drawText(QPointF(45-itemName.length()*6,25),itemName);
	}

protected:
	QPen pen;
	QBrush	brush;
	QPainter painter;
	QPainterPath  path;
	QColor lineColor;
	QPointF mpos;
	
private:

};

#endif //CLASSOBJECT_H