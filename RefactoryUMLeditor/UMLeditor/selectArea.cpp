#include "selectArea.h"

selectArea::selectArea()
{
}

selectArea::~selectArea()
{
}

void selectArea::paintArea(QPointF startPos,QPointF endPos)
{
	spos=startPos;
	epos=endPos;

	/*brush.setColor(QColor::fromRgb(0,0,255,128));
	brush.setStyle( Qt::SolidPattern );*/

	/*QVector<QPointF> v;
    {
      v.push_back( QPointF(spos.x(), spos.y()) );
      v.push_back( QPointF(spos.x(), epos.y()) );
      v.push_back( QPointF(epos.x(), spos.y()) );
      v.push_back( QPointF(epos.x(), epos.y() ) );
    }
    path.addPolygon( QPolygonF( v ) );
	painter.fillPath( path, brush );
	painter.drawRect(spos.x(),spos.y(),epos.x()-spos.x(),epos.y()-spos.y());*/
}