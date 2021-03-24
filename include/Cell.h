#ifndef SYMULATORUMTS_CELL_H
#define SYMULATORUMTS_CELL_H

#include <memory>
#include <vector>
#include "UserEquipment.h"


using namespace std;

class RadioNetworkController;

class UserEquipment;

class Cell {
private:
    shared_ptr<RadioNetworkController> radioNetController;
    vector<shared_ptr<UserEquipment>> userEqs;
    int availableCs;
    int availablePs;
    static int counter;
    int id;

public:
    Cell(const shared_ptr<RadioNetworkController> &radioNetController);

    int getId() const;

    const vector<shared_ptr<UserEquipment>> &getUserEqs() const;

    bool resourceRequest(UserEquipment::ConnectionType type, UserEquipment *ue);

    int getAvailableCs() const;

    int getAvailablePs() const;

    void reserveCs();

    void reservePs();

    bool addUserEquipment(shared_ptr<UserEquipment> userEq);

};

#endif //SYMULATORUMTS_CELL_H

