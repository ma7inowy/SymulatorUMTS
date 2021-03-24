#ifndef SYMULATORUMTS_CELL_H
#define SYMULATORUMTS_CELL_H

#include <memory>
#include "UserEquipment.h"
#include <vector>

using namespace std;

class Cell {
private:
    vector<shared_ptr<UserEquipment>> userEqs;
    const int maxCs = 3;
    const int maxPs = 5;
    int counterCs;
    int counterPs;
public:
    Cell();

    const vector<shared_ptr<UserEquipment>> &getUserEqs() const;

    int getCounterCs() const;

    int getCounterPs() const;
};

#endif //SYMULATORUMTS_CELL_H
