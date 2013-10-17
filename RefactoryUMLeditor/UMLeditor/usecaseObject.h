#ifndef USECASEOBJECT_H
#define USECASEOBJECT_H

#include <Qgraphicsview>
#include <QgraphicsItem>
#include <Qpainter>
#include "umlObject.h"

class usecaseObject : public umlObject
{
public:
	usecaseObject();
	~usecaseObject();
	void paintitem(QPointF pos);
	void updatePortPos(QPointF pos);
	//void getText(QString text);
	
	QRectF usecaseObject::boundingRect() const
	{
		return path.boundingRect();
	}

	QPainterPath usecaseObject::shape() const
	{
		return path;
	}

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
	{
		this->updatePortPos(this->scenePos());
		QPen pen;
		pen.setColor(QColor(255,100,0));
		pen.setWidth(2);
		pen.setStyle(Qt::SolidLine);

		painter->setPen(pen);

		painter->fillPath( path, brush );
		//painter->drawEllipse(mpos.x(),mpos.y(),120,70);
		painter->drawEllipse(0,0,120,70);

		if(this->isSelected()){
			pen.setColor(QColor(255,255,0));
			/*painter->drawRect(mpos.x()+60,mpos.y()+2,2,2);
			painter->drawRect(mpos.x()+2,mpos.y()+35,2,2);
			painter->drawRect(mpos.x()+117,mpos.y()+35,2,2);
			painter->drawRect(mpos.x()+60,mpos.y()+67,2,2);*/

			painter->drawRect(60,2,2,2);
			painter->drawRect(2,35,2,2);
			painter->drawRect(117,35,2,2);
			painter->drawRect(60,67,2,2);
		}

		QFont font;
		font.setPointSize(18);
		painter->setFont(font);
		//painter->drawText(QPointF(mpos.x()+60-itemName.length()*6,mpos.y()+38),itemName);
		painter->drawText(QPointF(60-itemName.length()*6,38),itemName);
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

#endif //USECASEOBJECT_H