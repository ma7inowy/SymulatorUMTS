#include "../include/Cell.h"

Cell::Cell() : counterCs(0), counterPs(0) {

}

const vector<shared_ptr<UserEquipment>> &Cell::getUserEqs() const {
    return userEqs;
}

int Cell::getCounterCs() const {
    return counterCs;
}

int Cell::getCounterPs() const {
    return counterPs;
}
