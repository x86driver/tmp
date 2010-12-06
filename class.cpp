#include <iostream>
using namespace std;

class A {
public:
	A() {
		cout << "1" << endl;
	}
	virtual void function() {
		cout << "2" << endl;
	}
	~A() {
		cout << "3" << endl;
	}
};

class B : public A {
public:
	B() {
		cout << "4" << endl;
	}
	virtual void function() {
		cout << "5" << endl;
	}
	~B() {
		cout << "6" << endl;
	}
};

int main()
{
	B b;
	b.function();
	return 0;
}

