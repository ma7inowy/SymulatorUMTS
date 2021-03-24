#include "../include/RadioNetworkController.h"
#include <iostream>
#include <algorithm>

RadioNetworkController::RadioNetworkController() {}

bool RadioNetworkController::tryToReserveResources(Cell *cell, UserEquipment::ConnectionType type) {
    for (auto &it : cells) {
        if (it->getId() == cell->getId()) {
            if (type == UserEquipment::PS) {
                if (cell->getAvailablePs() > 0) {
                    cell->reservePs();
                    return true;
                }
            } else if (type == UserEquipment::CS) {
                if (cell->getAvailableCs() > 0) {
                    cell->reserveCs();
                    return true;
                }
            } else if (type == UserEquipment::PSANDCS) {
                if (cell->getAvailableCs() > 0 && cell->getAvailablePs() > 0) {
                    cell->reserveCs();
                    cell->reservePs();
                    return true;
                }
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
