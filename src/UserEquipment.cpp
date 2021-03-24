#include "../include/UserEquipment.h"
#include "../include/Cell.h"
#include <iostream>

UserEquipment::UserEquipment(bool connected, ConnectionType connType) : connected(connected),
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

bool UserEquipment::callEstablishment(shared_ptr<Cell> cell) {
    //ask for random connection
    // rand(...)
    if (cell->resourceRequest(UserEquipment::CS, this)) {
        connected = true;
        cout << "resourceConfirm" << endl;
        return true;
    } else {
        cout << "resourceReject" << endl;
        return false;
    }

}





