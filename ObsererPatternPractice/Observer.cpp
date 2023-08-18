#include "Events.cpp"
#include "Entity.cpp"

class Observer {
public:
	virtual ~Observer() {}
	virtual void onNotify(const Entity2& entity, Event event) {}
};