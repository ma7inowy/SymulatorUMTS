#include "../include/UserEquipment.h"

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

