#pragma once

class EngineObject {
protected:
	int id;
	bool active;
public:
    int getId();
    void setId(int id);
    bool isActive();
    void setActive(bool readActive);
};