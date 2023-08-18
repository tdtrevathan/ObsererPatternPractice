#include "Observer.cpp"

class Subject {
private:
	Observer* observers [10];
	int numberOfObservers = 0;

protected:
	void notify(const Entity2& entity, Event event) {
		for (int i = 0; i < numberOfObservers; i++) {
			observers[i]->onNotify(entity, event);
		}
	}

public:
	void addObserver(Observer* observer) {
		if (numberOfObservers < 10) {
			observers[numberOfObservers] = observer;
			numberOfObservers++;
		}
	}
	void removeObserver(Observer* observer) {
		if(numberOfObservers > 0)
			numberOfObservers--;
	}
};