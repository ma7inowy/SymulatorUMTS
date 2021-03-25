#include "../include/Cell.h"
#include "../include/UserEquipment.h"
#include "../include/RadioNetworkController.h"
#include <iostream>

int Cell::counter = 0;

Cell::Cell(const shared_ptr<RadioNetworkController> &radioNetController)
        : radioNetController(radioNetController), id(++counter), availableCs(3), availablePs(5) {
}

bool Cell::resourceRequest(UserEquipment::ConnectionType type) {
    if (radioNetController->tryToReserveResources(this, type)) {
        cout << "resourceConfirm: callEstablishment" << endl;
        return true;
    } else {
        cout << "resourceReject: callEstablishment" << endl;
        return false;
    }
}

bool Cell::handoverRequest(UserEquipment::ConnectionType type) {
    if (radioNetController->reserveResourcesHandover(this, type)) {
        cout << "resourceConfirm: handover" << endl;
        return true;
    } else {
        cout << "resourceReject: handover" << endl;
        return false;
    }
}

bool Cell::releaseResources(UserEquipment::ConnectionType type) {
    if (radioNetController->releaseResourcesHandover(this, type)) {
        return true;
    }
    return false;

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






