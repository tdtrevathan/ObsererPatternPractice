#include <iostream>

enum Event {
	TEST
};

class Entity2 {

};

class Observer {
public:
	  virtual ~Observer() {}

	virtual void onNotify(const Entity2& entity, Event event) {}
};

class Subject {
private:
	Observer* observers[10];
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
		if (numberOfObservers > 0)
			numberOfObservers--;
	}
};



class Acheivments : public Observer {
	virtual void onNotify(const Entity2& entity, Event event) {
		switch (event) {
		case TEST:
			unlock("TEST");
		}
	}

	void unlock(std::string achievement) {
		std::cout << achievement;
	}

public:
	Acheivments() {

	}
};

class Test : public Subject {
public:
	void DoThing(const Entity2& entity, Event event) {
		notify(entity, event);
	}
	void AddObserver(Observer* observer) {
		addObserver(observer);
	}
};

int main() {
	Test test;
	Entity2 testEntity;
	Acheivments* achievments = new Acheivments();

	test.AddObserver(achievments);
	test.DoThing(testEntity, TEST);
}