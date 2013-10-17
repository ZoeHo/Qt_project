#ifndef SELECTAREA_H
#define SELECTAREA_H

#include <Qgraphicsview>
#include <QgraphicsItem>
#include <Qpainter>

class selectArea : public QGraphicsItem
{
public:
	selectArea();
	~selectArea();
	void paintArea(QPointF startpos,QPointF endpos);

	QRectF selectArea::boundingRect() const
	{
		return path.boundingRect();
	}

	QPainterPath selectArea::shape() const
	{
		return path;
	}

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
	{
		QPen pen;
		pen.setColor(QColor(100,0,255));
		pen.setWidth(2);
		pen.setStyle(Qt::DotLine);

		painter->setPen(pen);
		painter->drawRect(spos.x(),spos.y(),epos.x()-spos.x(),epos.y()-spos.y());
	}

protected:
	QPen pen;
	QBrush	brush;
	QPainter painter;
	QPainterPath  path;
	QColor lineColor;
	QPointF spos,epos;
	
private:

};

#endif //SELECTAREA_H