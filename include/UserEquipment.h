#ifndef SYMULATORUMTS_USEREQUIPMENT_H
#define SYMULATORUMTS_USEREQUIPMENT_H

#include <memory>
#include <vector>

using namespace std;

class Cell;

class UserEquipment {
private:
    bool connected;
    shared_ptr<Cell> currentCell;
public:
    enum ConnectionType {
        NONE, PS, CS, PSANDCS
    } connType;

    UserEquipment(bool connected = false, ConnectionType connType = NONE);

    bool isConnected() const;

    void setConnected(bool connected);

    ConnectionType getConnType() const;

    void setConnType(ConnectionType connType);

    bool callEstablishment(const shared_ptr<Cell> &cell);

    bool handover(const shared_ptr<Cell> &newCell);

    bool callRelease();

    const shared_ptr<Cell> &getCurrentCell() const;

    ConnectionType getRandomConnType();

    void randomAction(const vector<shared_ptr<Cell>> &listOfCells);

};

#endif //SYMULATORUMTS_USEREQUIPMENT_H
