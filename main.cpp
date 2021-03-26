#include <iostream>
#include "include/UserEquipment.h"
#include "include/Cell.h"
#include "include/RadioNetworkController.h"

#include <cstdlib>
#include <ctime>
#include <vector>

#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std;

void simulation(const vector<shared_ptr<UserEquipment>> &uesVector, const vector<shared_ptr<Cell>> &cells, int amountOfIterations) {
    int indexOfVec;
    for (int i = 0; i < amountOfIterations; i++) {
        auto start = high_resolution_clock::now();
        indexOfVec = 0;
        for (auto ue : uesVector) {
            cout << "-----------" << endl;
            ue->randomAction(cells);
            cout << "UserEq nr: " << indexOfVec << endl;
            cout << "connectionType: " << ue->getConnType() << endl;
            if (ue->getCurrentCell() != nullptr)
                cout << "currentCell id: " << ue->getCurrentCell()->getId() << endl;
            cout << "isConnected: " << ue->isConnected() << endl;
            indexOfVec++;
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout<<"TIME(ms) "<<(duration.count())<<endl;
        this_thread::sleep_for(std::chrono::milliseconds(5000-duration.count()));
    }

}

int main() {
    srand(time(NULL));
    ///test data
//    shared_ptr<UserEquipment> ue(new UserEquipment);
//    shared_ptr<UserEquipment> ue2(new UserEquipment);
//    vector<shared_ptr<Cell>> cells;
//    shared_ptr<RadioNetworkController> rnc(new RadioNetworkController);
//    shared_ptr<Cell> c(new Cell(rnc));
//    shared_ptr<Cell> c2(new Cell(rnc));
//    shared_ptr<Cell> c3(new Cell(rnc));
//    rnc->addCell(c);
//    rnc->addCell(c2);
//    rnc->addCell(c3);
//    cells.push_back(c);
//    cells.push_back(c2);
//    cells.push_back(c3);

    ///test with two ues
//    cout<<"-----------"<<endl;
//    cout<<"conn type: "<<ue->getConnType()<<endl;
//    if(ue->getCurrentCell()!= nullptr)
//        cout<<"current cell id: "<<ue->getCurrentCell()->getId()<<endl;
//    cout<<"is connected: "<<ue->isConnected()<<endl;
//    cout<<"-----------"<<endl;
//    ue->randomAction(rnc->getCells());
//    cout<<"conn type: "<<ue->getConnType()<<endl;
//    if(ue->getCurrentCell()!= nullptr)
//        cout<<"current cell id: "<<ue->getCurrentCell()->getId()<<endl;
//    cout<<"is connected: "<<ue->isConnected()<<endl;
//    cout<<"-----------"<<endl;
//
//    cout<<"-------------------"<<endl;
//    cout<<"conn type: "<<ue2->getConnType()<<endl;
//    if(ue2->getCurrentCell()!= nullptr)
//        cout<<"current cell id: "<<ue2->getCurrentCell()->getId()<<endl;
//    cout<<"is connected: "<<ue2->isConnected()<<endl;
//    cout<<"-----------"<<endl;
//    ue2->randomAction(rnc->getCells());
//    cout<<"conn type: "<<ue2->getConnType()<<endl;
//    if(ue2->getCurrentCell()!= nullptr)
//        cout<<"current cell id: "<<ue2->getCurrentCell()->getId()<<endl;
//    cout<<"is connected: "<<ue2->isConnected()<<endl;
//    cout<<"-----------"<<endl;
//    ue2->randomAction(rnc->getCells());
//    cout<<"conn type: "<<ue2->getConnType()<<endl;
//    if(ue2->getCurrentCell()!= nullptr)
//        cout<<"current cell id: "<<ue2->getCurrentCell()->getId()<<endl;
//    cout<<"is connected: "<<ue2->isConnected()<<endl;
/////////////////////////////////////////////////////////////////

    /// UserEquipment container
    vector<shared_ptr<UserEquipment>> uesVector;

    /// parameters
    int amountOfCells = 20;
    int amountOfUes = amountOfCells * 35;
    int amountOfIterations = 3;

    /// RNC
    shared_ptr<RadioNetworkController> rnc1(new RadioNetworkController);

    /// make and add Cells pointers to RNC
    for (int i = 0; i < amountOfCells; i++) {
        shared_ptr<Cell> c11(new Cell(rnc1));
        rnc1->addCell(c11);
    }

    /// make and add UserEquipments pointers to UserEquipment container
    for (int i = 0; i < amountOfUes; i++) {
        shared_ptr<UserEquipment> ue(new UserEquipment);
        uesVector.push_back(ue);
    }

    /// simulation
    simulation(uesVector, rnc1->getCells(),amountOfIterations);

/////////////////////////////////////////////////////////////////

    return 0;
}


