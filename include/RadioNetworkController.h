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
};

#endif //SYMULATORUMTS_RADIONETWORKCONTROLLER_H
