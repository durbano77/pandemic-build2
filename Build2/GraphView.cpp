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
    switch(d){
        case 0:
            //all player info
            break;
        case 1:
            //player hand
            break;
        case 2:
            //discard hand
            break;
        case 3:
            //epidemic card display
            break;
        case 4:
            //pawn
            break;
        case 5:
            //_subject->showCity();
            _subject->cityWithAdjacency();
            break;
        case 6:
            _subject->cityAndConnection();
            break;
        case 7:
            //all cities info
            break;
        case 8:
            //infection card display
            break;
        default:
            std::cout<<"ERR: GraphView - undefined display behavior"<<std::endl;
    }
    

}

//void GraphView::displayMap(){
//	//_subject->showCity();
//	_subject->cityWithAdjacency();
//	_subject->cityAndConnection();
//	
//}



