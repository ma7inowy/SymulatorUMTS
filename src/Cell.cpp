#include "../include/Cell.h"
#include "../include/UserEquipment.h"
#include "../include/RadioNetworkController.h"
#include <iostream>

int Cell::counter = 0;

Cell::Cell(const shared_ptr<RadioNetworkController> &radioNetController)
        : radioNetController(radioNetController), id(++counter), availableCs(3), availablePs(5) {
}

const vector<shared_ptr<UserEquipment>> &Cell::getUserEqs() const {
    return userEqs;
}

bool Cell::resourceRequest(UserEquipment::ConnectionType type, UserEquipment *ue) {
    // cell ask rnc if can add Ue to its vector
    if (radioNetController->tryToReserveResources(this, type)) {
        // if tryToReserveResources -> addUe to vector of Ues
        addUserEquipment(shared_ptr<UserEquipment>(ue));
        // cout << "Size of Ues vector in cell: " << userEqs.size() << endl;
        return true;
    } else return false;
}

int Cell::getId() const {
    return id;
}

int Cell::getAvailableCs() const {
    return availableCs;
}

int Cell::getAvailablePs() const {
    return availablePs;
}

void Cell::reserveCs() {
    availableCs--;
}

void Cell::reservePs() {
    availablePs--;

}

bool Cell::addUserEquipment(shared_ptr<UserEquipment> userEq) {
    //it doesnt check bcs RNC checks
    userEqs.push_back(userEq);
    return true;
}


