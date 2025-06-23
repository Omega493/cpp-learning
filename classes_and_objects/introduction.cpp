#include <iostream>

using namespace std;

template<typename T>

class Rectangle {

private:
	T len;
	T br;

public:
	
	void getData() {
		cout << "Enter length and breadth: ";
		cin >> len >> br;
	}

	void setData(T l, T b) {
		len = l;
		br = b;
	}

	void displayData() {
		cout << "Length:" << len << endl;
		cout << "Breadth: " << br << endl;
	}

	void areaPeri() {
		T peri = 2 * (len + br);
		T area = len * br;
		cout << "Area: " << area << endl;
		cout << "Perimeter: " << peri << endl;
	}
};

int main() {
	Rectangle<int> r1;
	r1.setData(10, 20);
	r1.displayData();
	r1.areaPeri();

	cout << endl;

	Rectangle<double> r2;
	r2.setData(2.732f, 3.1415f);
	r2.displayData();
	r2.areaPeri();

	cout << endl;

	Rectangle<float> r3;
	r3.getData();
	r3.displayData();
	r3.areaPeri();

	return 0;
}