#include <iostream>

void f(int& x) {
	x+=10;
}

class A{
	int x=0;
	int y=0;
public:
	void SetX();	
};

void A::SetX() {
	f(x);
	std::cout << x<< '\n';
}


int main() {

	char* a = new char[10]; // ссылка на указатель работает
	a[0] = 10;
	char* &b = a; 
	b = new char[20];
	std::cin >> b;
	std::cout << b << '\n';
	std::cout << a;
	//A a;
	//a.SetX();

	
}
