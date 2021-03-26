#ifndef SYMULATORUMTS_RADIONETWORKCONTROLLER_H
#define SYMULATORUMTS_RADIONETWORKCONTROLLER_H

#include <memory>
#include "Cell.h"
#include <vector>

using namespace std;

class RadioNetworkController {
private:
    vector<shared_ptr<Cell>> cells;
    const int maxCells = 20;
public:
    RadioNetworkController();

    bool resourceReserve(Cell *cell, UserEquipment::ConnectionType type);

    bool resourceHandoverReserve(Cell *cell, UserEquipment::ConnectionType type);

    bool resourceRelease(Cell *cell, UserEquipment::ConnectionType type);

    bool addCell(const shared_ptr<Cell>& cell);

    const vector<shared_ptr<Cell>> &getCells() const;

};

#endif //SYMULATORUMTS_RADIONETWORKCONTROLLER_H
