#include "../include/UserEquipment.h"
#include "../include/Cell.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

UserEquipment::UserEquipment(bool connected, ConnectionType connType) : currentCell(nullptr), connected(connected),
                                                                        connType(connType) {

}

bool UserEquipment::isConnected() const {
    return connected;
}

void UserEquipment::setConnected(bool connected) {
    UserEquipment::connected = connected;
}

UserEquipment::ConnectionType UserEquipment::getConnType() const {
    return connType;
}

void UserEquipment::setConnType(UserEquipment::ConnectionType connType) {
    UserEquipment::connType = connType;
}

bool UserEquipment::callEstablishment(const shared_ptr<Cell> &cell) {
    ConnectionType randomConnType = getRandomConnType();
    if (cell->resourceRequest(randomConnType)) {
        connected = true;
        currentCell = cell;
        connType = randomConnType;
        return true;
    } else {
        return false;
    }

}

bool UserEquipment::handover(const shared_ptr<Cell> &newCell) {
    // only if connected = true;
    if (currentCell->resourceReleaseRequest(getConnType())) {
        if (newCell->resourceHandoverRequest(getConnType())) {
            currentCell = newCell;
            return true;
        }
    }
    return false;
}

bool UserEquipment::callRelease() {
    if (currentCell->resourceReleaseRequest(getConnType())) {
        currentCell = nullptr;
        connType = UserEquipment::NONE;
        connected = false;
        return true;
    } else return false;
}

const shared_ptr<Cell> &UserEquipment::getCurrentCell() const {
    return currentCell;
}

UserEquipment::ConnectionType UserEquipment::getRandomConnType() {
    int i = (rand() % 3 + 1); // rand from 1 to 3
    auto randomConnType = static_cast<ConnectionType>(i);
    return randomConnType;
}

void UserEquipment::randomAction(const vector<shared_ptr<Cell>> &listOfCells) {
    int action = (rand() % 2 + 1); // rand from 1 to 2

    int indexOfRandomCell = rand() % listOfCells.size();
    if (isConnected()) {
        switch (action) {
            case 1: {
                handover(listOfCells[indexOfRandomCell]);
                break;
            }
            case 2:
                callRelease();
                break;
            default:
                cout << "def" << endl;
                break;
        }

    } else {
        callEstablishment(listOfCells[indexOfRandomCell]);
    }

}








