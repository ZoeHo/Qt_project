#include "sceneView.h"

sceneView::sceneView(QWidget *parent)
{
}

sceneView::~sceneView()
{
}

void sceneView::selectaGroup()
{
	QPainterPath  path;
	QPainter painter;
	path.addRect(startPos.x(),startPos.y(),endPos.x()-startPos.x(),endPos.y()-startPos.y());
	this->setSelectionArea(path);

	selected.append( this->selectedItems() );
	//painter.drawRect(startPos.x(),startPos.y(),fabs(endPos.x()-startPos.x()),fabs(endPos.y()-startPos.y()));
	
 }

void sceneView::mousePressEvent(QGraphicsSceneMouseEvent *mEvent)
{
	QPointF pos = mEvent->scenePos();
	startPos = mEvent->scenePos();

	if( modeNum==1 /*&& !this->itemAt(pos.x(),pos.y())*/){
		classObject *tob =new classObject();
		cob=tob;
		tob->paintitem(pos);
		tob->updatePortPos(pos);
		this->addItem(tob);
	}
		
	if( modeNum==2 /*&& !this->itemAt(pos.x(),pos.y())*/){
		usecaseObject *ob = new usecaseObject();
		mob=ob;
		ob->paintitem(pos);
		ob->updatePortPos(pos);
		this->addItem(ob);
	}	
	
	if( modeNum==3 ){
		if(this->itemAt(pos.x(),pos.y())){
		mob = (usecaseObject *)this->itemAt(pos.x(),pos.y());
		cob = (classObject *)this->itemAt(pos.x(),pos.y());
		slob = (umlObject *)this->itemAt(pos.x(),pos.y());

		this->QGraphicsScene::mousePressEvent(mEvent);  //�NmouseEvent�ǵ�QGraphicsItem��
		}
		else if(!this->itemAt(pos.x(),pos.y())){		//���U����select����
			QPainterPath  path;
			QPainter painter;
			path.addRect(0,0,0,0);
			this->setSelectionArea(path);
		}
	}
}

void sceneView::mouseMoveEvent(QGraphicsSceneMouseEvent *mEvent)
{
	movPos = mEvent->scenePos();
	if(modeNum!=1 && modeNum !=2){
		this->QGraphicsScene::mouseMoveEvent(mEvent);
	}

	if(modeNum==3){
		/*cob->updatePortPos(movPos);
		mob->updatePortPos(movPos);*/
		//if(this->itemAt(movPos.x(),movPos.y())){ slob->updatePortPos(slob->scenePos()); }
		/*if(this->itemAt(movPos.x(),movPos.y())){ 
			slob->updatePortPos(slob->scenePos()); 
		}
		
		if(selected.size()>0){		//�h��item�Q��ܮɤ@�_����
		foreach(item, selected) { 
			slob=(umlObject *)item;
			slob->updatePortPos(slob->scenePos()); }
		}*/
	}
}

void sceneView::mouseReleaseEvent(QGraphicsSceneMouseEvent *mEvent)
{
	endPos = mEvent->scenePos();
	this->QGraphicsScene::mouseReleaseEvent(mEvent);

	slob = (umlObject *)this->itemAt(startPos.x(),startPos.y());
	elob = (umlObject *)this->itemAt(endPos.x(),endPos.y());

	if( modeNum==3 && !this->itemAt(startPos.x(),startPos.y()) && !this->itemAt(endPos.x(),endPos.y())){
		selectaGroup();
		/*selectArea *area=new selectArea();
		area->paintArea(startPos,endPos);
		this->addItem(area);*/
	}

	if(modeNum==4){
		if(this->itemAt(startPos.x(),startPos.y()) && this->itemAt(endPos.x(),endPos.y())){
			association *assocLine=new association();
			assoc=assocLine;
			this->addItem(assoc);
			assoc->findport(slob,elob,startPos,endPos);
		}
		if(!this->itemAt(endPos.x(),endPos.y())){
			//this->removeItem(assoc);
		}	//�p�G���O�bitem���a��񱼫h�����ɤ޽u���s�u
	}

	if(modeNum==5){
		if(this->itemAt(startPos.x(),startPos.y()) && this->itemAt(endPos.x(),endPos.y())){
			generalization *geneLine=new generalization();
			general=geneLine;
			this->addItem(general);
			general->findport(slob,elob,startPos,endPos);
		}
	}

	if(modeNum==6){
		if(this->itemAt(startPos.x(),startPos.y()) && this->itemAt(endPos.x(),endPos.y())){
			composition *comLine=new composition();
			compos=comLine;
			this->addItem(compos);
			compos->findport(slob,elob,startPos,endPos);
		}
	}
}

void sceneView::setn(int num)
{
	this->modeNum=num;
}

void sceneView::setText(QString text)
{
	dialogText=text;
}