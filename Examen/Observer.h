#pragma once
#include <vector>
using namespace std;

class Observer
{
public:
	virtual void update() = 0;
	Observer();
	~Observer();
};

class Observable {
private:
	vector<Observer*> obs;
public:
	void notify() {
		for (auto o : obs) {
			o->update();
		}
	}
	void addObs(Observer* o) {
		obs.push_back(o);
	}
};
