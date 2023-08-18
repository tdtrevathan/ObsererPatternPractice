#include <iostream>

enum Event {
	HALFWAY,
	LOOP_COMPLETE
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
		case HALFWAY:
			unlock("Almost there!");
			break;
		case LOOP_COMPLETE:
			unlock("We've completed the loop!");
			break;
		}
	}

	void unlock(std::string achievement) {
		std::cout << achievement << std::endl;
	}

public:
	Acheivments() {

	}
};

class Test : public Subject {
	int counter = 0;
public:
	void CoutLoops(const Entity2& entity, int loopMax) {
		std::cout << "Wow we've gone " << counter << " times in a loop!" << std::endl;
		counter++;

		if (counter == loopMax / 2)
			notify(entity, HALFWAY);

		if(counter >= loopMax)
			notify(entity, LOOP_COMPLETE);
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

	int loopMax = 15;
	for (int i = 0; i < loopMax; i++) {
		test.CoutLoops(testEntity, loopMax);
	}
}