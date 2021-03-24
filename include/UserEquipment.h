#ifndef SYMULATORUMTS_USEREQUIPMENT_H
#define SYMULATORUMTS_USEREQUIPMENT_H

#include <memory>
using namespace std;

class Cell;

class UserEquipment {
private:
    bool connected;
public:
    enum ConnectionType {
        NONE, PS, CS, PSANDCS
    } connType;

    UserEquipment(bool connected = false, ConnectionType connType = NONE);

    bool isConnected() const;

    void setConnected(bool connected);

    ConnectionType getConnType() const;

    void setConnType(ConnectionType connType);

    bool callEstablishment(shared_ptr<Cell> cell);
};

#endif //SYMULATORUMTS_USEREQUIPMENT_H
