#include "../include/Cell.h"
#include "../include/RadioNetworkController.h"
#include <iostream>

int Cell::counter = 0;

Cell::Cell(const shared_ptr<RadioNetworkController> &radioNetController)
        : radioNetController(radioNetController), id(counter++), availableCs(3), availablePs(5) {
}

bool Cell::resourceRequest(UserEquipment::ConnectionType type) {
    if (radioNetController->resourceReserve(this, type)) {
        cout << "resourceConfirm: callEstablishment" << " (PS:" << getAvailablePs() << ", CS:" << getAvailableCs()
             << ") cell_id:" << getId() << endl;
        return true;
    } else {
        cout << "resourceReject: callEstablishment" << " (PS:" << getAvailablePs() << ", CS:" << getAvailableCs()
             << ") cell_id:" << getId() << endl;
        return false;
    }
}

bool Cell::resourceHandoverRequest(UserEquipment::ConnectionType type) {
    if (radioNetController->resourceHandoverReserve(this, type)) {
        cout << "resourceConfirm: handover" << " (PS:" << getAvailablePs() << ", CS:" << getAvailableCs()
             << ") cell_id:" << getId() << endl;
        return true;
    } else {
        cout << "resourceReject: handover" << " (PS:" << getAvailablePs() << ", CS:" << getAvailableCs() << ") cell_id:"
             << getId() << endl;
        return false;
    }
}

bool Cell::resourceReleaseRequest(UserEquipment::ConnectionType type) {
    if (radioNetController->resourceRelease(this, type)) {
        cout << "resourceConfirm: callRelease" << " (PS:" << getAvailablePs() << ", CS:" << getAvailableCs()
             << ") cell_id:" << getId() << endl;
        return true;
    } else {
        cout << "resourceReject: callRelease" << " (PS:" << getAvailablePs() << ", CS:" << getAvailableCs()
             << ") cell_id:" << getId() << endl;
        return false;
    }

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

void Cell::releaseCs() {
    availableCs++;
}

void Cell::releasePs() {
    availablePs++;
}






