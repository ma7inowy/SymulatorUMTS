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

    bool tryToReserveResources(Cell *cell, UserEquipment::ConnectionType type);

    bool addCell(shared_ptr<Cell> cell);

};

#endif //SYMULATORUMTS_RADIONETWORKCONTROLLER_H
