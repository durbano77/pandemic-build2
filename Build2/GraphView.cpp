#include "GraphView.h"


GraphView::GraphView()
{
}

GraphView::GraphView(Graph* s)
{
	_subject = s;
	_subject->Attach(this);
}
GraphView::~GraphView()
{
	_subject->Detach(this);
    _subject=nullptr;
}

void GraphView::Update(int g){
    display(g);
}

void GraphView::display(int d){
    if(d==5){
        //_subject->showCity();
        _subject->cityWithAdjacency();
        _subject->cityAndConnection();
    }
}

//void GraphView::displayMap(){
//	//_subject->showCity();
//	_subject->cityWithAdjacency();
//	_subject->cityAndConnection();
//	
//}



