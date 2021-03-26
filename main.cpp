#include <iostream>
#include "include/UserEquipment.h"
#include "include/Cell.h"
#include "include/RadioNetworkController.h"

#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    srand(time(NULL));
    ///test data
    shared_ptr<UserEquipment> ue(new UserEquipment);
    shared_ptr<UserEquipment> ue2(new UserEquipment);
    vector<shared_ptr<Cell>> cells;
    shared_ptr<RadioNetworkController> rnc(new RadioNetworkController);
    shared_ptr<Cell> c(new Cell(rnc));
    shared_ptr<Cell> c2(new Cell(rnc));
    rnc->addCell(c);
    rnc->addCell(c2);
    cells.push_back(c);
    cells.push_back(c2);

    ///test with single UE
    cout<<"-----------"<<endl;
    cout<<"conn type: "<<ue->getConnType()<<endl;
    if(ue->getCurrentCell()!= nullptr)
        cout<<"current cell id: "<<ue->getCurrentCell()->getId()<<endl;
    cout<<"is connected: "<<ue->isConnected()<<endl;
    cout<<"-----------"<<endl;
    ue->randomAction(cells);
    cout<<"conn type: "<<ue->getConnType()<<endl;
    if(ue->getCurrentCell()!= nullptr)
        cout<<"current cell id: "<<ue->getCurrentCell()->getId()<<endl;
    cout<<"is connected: "<<ue->isConnected()<<endl;
    cout<<"-----------"<<endl;
    ue->randomAction(cells);
    cout<<"conn type: "<<ue->getConnType()<<endl;
    if(ue->getCurrentCell()!= nullptr)
        cout<<"current cell id: "<<ue->getCurrentCell()->getId()<<endl;
    cout<<"is connected: "<<ue->isConnected()<<endl;
    ///

    return 0;
}


