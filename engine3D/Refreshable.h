#pragma once

class Refreshable {
protected:
	int callForRefresh;
public:
	bool getIfRefresh();
	void setIfRefresh(bool readRefresh);
};