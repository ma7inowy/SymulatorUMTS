#include "../include/UserEquipment.h"
#include "../include/Cell.h"
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
    //resourceRequest
    return false;
}





