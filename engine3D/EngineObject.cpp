#include "EngineObject.h"

int EngineObject::getId() {
    return id;
}

void EngineObject::setId(int newId) {
    id = newId;
}

bool EngineObject::isActive() {
    return active;
}

void EngineObject::setActive(bool readActive) {
    active = readActive;
}