#pragma once
#include "Observer.cpp"
#include "Events.cpp"
#include "Entity.cpp"


	virtual ~Observer() {}
	virtual void onNotify(const Entity2& entity, Event event) {}
