#ifndef SYMULATORUMTS_USEREQUIPMENT_H
#define SYMULATORUMTS_USEREQUIPMENT_H

using namespace std;

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
};

#endif //SYMULATORUMTS_USEREQUIPMENT_H
