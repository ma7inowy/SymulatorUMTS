#ifndef SYMULATORUMTS_CELL_H
#define SYMULATORUMTS_CELL_H

#include <memory>
#include "UserEquipment.h"

using namespace std;

class RadioNetworkController;

class UserEquipment;

class Cell {
private:
    shared_ptr<RadioNetworkController> radioNetController;
    int availableCs;
    int availablePs;
    static int counter;
    int id;

public:
    Cell(const shared_ptr<RadioNetworkController> &radioNetController);

    int getId() const;

    bool resourceRequest(UserEquipment::ConnectionType type);

    bool handoverRequest(UserEquipment::ConnectionType type);

    bool releaseResources(UserEquipment::ConnectionType type);

    int getAvailableCs() const;

    int getAvailablePs() const;

    void reserveCs();

    void reservePs();

    void releaseCs();

    void releasePs();

};

#endif //SYMULATORUMTS_CELL_H

