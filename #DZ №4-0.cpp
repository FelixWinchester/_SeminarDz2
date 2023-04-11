#include <iostream>
#include <string>

using namespace std;

class BowlingBall {
	int weight;
	string color;
public:
	static int count;
	BowlingBall() {
		count++;
	}

	BowlingBall(int weight, string color) {
		count++;
		setParams(weight, color);
	}

	BowlingBall(const BowlingBall& other) {
		setParams(other.weight, other.color);
		count++;
	}

	bool setWeight(int weight) {
		if (weight > 0) {
			this->weight = weight;
			return true;
		}
		return false;
	}
	bool setColor(string color) {
		if (color != "") {
			this->color = color;
			return true;
		}
		return false;
	}
	void setParams(int weight, string color) {
		setWeight(weight);
		setColor(color);
	}
	void print() {
		cout << weight << " (" << color << ")\n";
	}
	BowlingBall& operator++() {
		weight++;
		return *this;
	}
	BowlingBall operator++(int) {
		BowlingBall tmp(*this);
		weight++;
		return tmp;
	}
};

int BowlingBall::count = 0;

int main()
{
	BowlingBall ball1(10, "purple");
	(++ball1).print();
	BowlingBall ball2(3, "green");
	ball2++.print();
}
