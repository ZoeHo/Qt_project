#include "editorView.h"
#include <QGridLayout>
#include <QPushButton>
#include <Qgraphicsview>
#include <Qbuttongroup>
#include <Qinputdialog>
#include <QGraphicsItemGroup>

editorView::editorView(QApplication *app , QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	setBottom(this);
	setGraphicsView(this); 
	setFileMenu(this, app);
}

editorView::~editorView()
{

}

void editorView::setBottom(QWidget *parent)
{
	QWidget *form = new QWidget(this);					//設定內部所有配置的格局
	form->setGeometry(5,30,70,350);						//font(0,30,90,350)

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setSpacing(3);							//設定Grid的空間與彼此之間的邊界
    mainLayout->setMargin(3);
	
	QButtonGroup *bgroup= new QButtonGroup(parent);

	QPushButton *Select = new QPushButton(QIcon("select.png"),"",parent);
	QObject::connect(Select, SIGNAL(clicked()), parent, SLOT(selectClicked()));
	Select->setFixedHeight(50);
	Select->setToolTip("Select");
	Select->setIconSize(QSize(15,18));
	Select->setCheckable(TRUE);
	mainLayout->addWidget(Select , 0, 0);
	bgroup->addButton(Select);

	QPushButton *Association = new QPushButton(QIcon("association.png"),"",parent);
	QObject::connect(Association, SIGNAL(clicked()), parent, SLOT(associationClicked()));
	Association->setFixedHeight(50);
	Association->setToolTip("Association line");
	Association->setIconSize(QSize(18,21));
	Association->setCheckable(TRUE);
	mainLayout->addWidget(Association , 1, 0);
	bgroup->addButton(Association);

	QPushButton *Generalization = new QPushButton(QIcon("generalization.png"),"",parent);
	QObject::connect(Generalization, SIGNAL(clicked()), parent, SLOT(generalizationClicked()));
	Generalization->setFixedHeight(50);
	Generalization->setToolTip("Gerenalization line");
	Generalization->setIconSize(QSize(18,21));
	Generalization->setCheckable(TRUE);
	mainLayout->addWidget(Generalization , 2, 0);
	bgroup->addButton(Generalization);

	QPushButton *Composition = new QPushButton(QIcon("composition.png"),"",parent);
	QObject::connect(Composition, SIGNAL(clicked()), parent, SLOT(compositionClicked()));
	Composition->setFixedHeight(50);
	Composition->setToolTip("Composition line");
	Composition->setIconSize(QSize(18,25));
	Composition->setCheckable(TRUE);
	mainLayout->addWidget(Composition , 3, 0);
	bgroup->addButton(Composition);

	QPushButton *Class = new QPushButton(QIcon("class.png"),"",parent);
	QObject::connect(Class, SIGNAL(clicked()), parent, SLOT(classClicked()));
	Class->setFixedHeight(50);
	Class->setToolTip("Class");
	Class->setIconSize(QSize(18,25));
	Class->setCheckable(TRUE);
	mainLayout->addWidget(Class , 4, 0);
	bgroup->addButton(Class);
	
	QPushButton *UseCase = new QPushButton(QIcon("usecase.png"),"",parent);
	QObject::connect(UseCase, SIGNAL(clicked()), parent, SLOT(usecaseClicked()));
	UseCase->setFixedHeight(50);
	UseCase->setToolTip("Use Case");
	UseCase->setCheckable(TRUE);
	mainLayout->addWidget(UseCase , 5, 0);
	bgroup->addButton(UseCase);

	form->setLayout(mainLayout);

}

void editorView::setFileMenu(QWidget *parent, QApplication *app)
{
	// File選單
    QMenu *fileMenu = new QMenu("&File");
    // 分隔線
    fileMenu->addSeparator();
    // 快捷鍵 Alt+F4，動作連接至 QApplication 的 quit() 
    fileMenu->addAction("Exit", app , SLOT(quit()), Qt::ALT + Qt::Key_F4);

    QMenu *editMenu = new QMenu("&Edit");
    editMenu->addAction("Change Object Name",this,SLOT(rename()),Qt::CTRL + Qt::Key_N);
	editMenu->addSeparator();
	editMenu->addAction("Group Objects",this,SLOT(grouping()),Qt::CTRL + Qt::Key_G);
    editMenu->addAction("UnGroup Objects",this,SLOT(ungroup()),Qt::CTRL + Qt::Key_U);
                
    this->menuBar()->addMenu(fileMenu);
    this->menuBar()->addMenu(editMenu);  
}


void editorView::setGraphicsView(QWidget *parent)
{
	mscene = new sceneView(this);
	QGraphicsView *graphic = new QGraphicsView(mscene,this);
	graphic->setGeometry(80,30,900,560);
	graphic->scene()->setSceneRect(graphic->rect());

	currentMode = new mode(mscene);
	setmode(selectMode);
}

void editorView::classClicked()
{
	if(currentMode!=NULL)
		delete currentMode;
	currentMode = new createClassMode(mscene);
	setmode(classMode);
}

void editorView::usecaseClicked()
{
	if(currentMode!=NULL)
		delete currentMode;
	currentMode = new createUsecaseMode(mscene);
	setmode(usecaseMode);
}

void editorView::selectClicked()
{
	if(currentMode!=NULL)
		delete currentMode;
	currentMode = new createSelectMode(mscene);
	setmode(selectMode);
}

void editorView::associationClicked()
{
	if(currentMode!=NULL)
		delete currentMode;
	currentMode = new createAssociationMode(mscene);
	setmode(associationMode);
}

void editorView::generalizationClicked()
{
	if(currentMode!=NULL)
		delete currentMode;
	currentMode = new createGeneralizationMode(mscene);
	setmode(generalizationMode);
}

void editorView::compositionClicked()
{
	if(currentMode!=NULL)
		delete currentMode;
	currentMode = new createCompositionMode(mscene);
	setmode(compositionMode);
}

void editorView::rename()
{
	QList< QGraphicsItem * > selected( mscene->selectedItems() );
	if( selected.size()==1 ){

	bool isOK;
	QInputDialog dialog=new QInputDialog();
	QString text = 
		dialog.getText(this, "Change Object Name", "Please input the item name", QLineEdit::Normal, "name", &isOK);
	
	if(isOK){			//press OK才做 setText
		mscene->setText(text);
		mscene->slob->getText(text);
	}
	}
}

void editorView::grouping()
{
	QGraphicsItemGroup *group = new QGraphicsItemGroup();
	group->setFlag(QGraphicsItem::ItemIsSelectable, true);
	group->setFlag(QGraphicsItem::ItemIsMovable, true);
	QGraphicsItem *item;
	mscene->addItem(group);

	//grouproot = group;
	grouproot.append(group);

	QList< QGraphicsItem * > selected( mscene->selectedItems() );
	if( selected.size()!=0 ){
		foreach(item, selected) { 
			group->addToGroup(item);
		}
	}
	//mscene->addRect(group->boundingRect());
}

void editorView::ungroup()
{

	QGraphicsItem *item;
	QList< QGraphicsItem * > childptr;
	
	QList< QGraphicsItem * > selected( mscene->selectedItems() );
	//QList< QGraphicsItem * > msele(grouproot->childItems());
	if(selected.size()==1){
		QGraphicsItemGroup *itemGroup = dynamic_cast<QGraphicsItemGroup*>(selected.at(0));
		childptr=itemGroup->childItems();
		//mscene->destroyItemGroup(itemGroup);		//砍掉一個Group
		foreach(item, childptr) {
			itemGroup->removeFromGroup(item);		//將item從Group中移除
			item->setSelected(false);
		}		
	}
}

void editorView::setmode(int modename)
{
	/*if(currentMode!=NULL)
		delete currentMode;
	currentMode = new mode(mscene);*/
	mscene->setmode(modename, currentMode);
}