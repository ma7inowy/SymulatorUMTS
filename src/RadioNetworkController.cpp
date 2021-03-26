#include "../include/RadioNetworkController.h"


RadioNetworkController::RadioNetworkController() {}

bool RadioNetworkController::resourceReserve(Cell *cell, UserEquipment::ConnectionType type) {
    for (auto &it : cells) {
        if (it->getId() == cell->getId()) {
            if (type == UserEquipment::PS) {
                if (it->getAvailablePs() > 0) {
                    it->reservePs();
                    return true;
                }
            } else if (type == UserEquipment::CS) {
                if (it->getAvailableCs() > 0) {
                    it->reserveCs();
                    return true;
                }
            } else if (type == UserEquipment::PSANDCS) {
                if (it->getAvailableCs() > 0 && it->getAvailablePs() > 0) {
                    it->reserveCs();
                    it->reservePs();
                    return true;
                }
            }
        }

    }

    return false;
}

bool RadioNetworkController::resourceHandoverReserve(Cell *cell, UserEquipment::ConnectionType type) {
    for (auto &it : cells) {
        if (it->getId() == cell->getId()) {
            if (type == UserEquipment::PS) {
                it->reservePs();
                return true;
            } else if (type == UserEquipment::CS) {
                it->reserveCs();
                return true;
            } else if (type == UserEquipment::PSANDCS) {
                it->reserveCs();
                it->reservePs();
                return true;
            } else { return false; }
        }
    }
    return false;
}

bool RadioNetworkController::resourceRelease(Cell *cell, UserEquipment::ConnectionType type) {
    for (auto &it : cells) {
        if (it->getId() == cell->getId()) {
            if (type == UserEquipment::PS) {
                it->releasePs();
                return true;
            } else if (type == UserEquipment::CS) {
                it->releaseCs();
                return true;
            } else if (type == UserEquipment::PSANDCS) {
                it->releasePs();
                it->releaseCs();
                return true;
            } else { return false; }
        }
    }
    return false;
}

bool RadioNetworkController::addCell(shared_ptr<Cell> cell) {
    if (cells.size() < maxCells) {
        cells.push_back(cell);
        return true;
    } else return false;
}


