#include<iostream>
#include"MyDequeL.h"
using namespace std;

int main() {
	MyDequeL my1;
	MyDequeL my2;
	for (int i = 0; i < 10; ++i) {
		my1.push(100);
	}

	my1.print();
	my1.pop();
	my1.front();
	my1.size();
	my1.back() = 90;
	cout << "ÊÇ·ñÎª¿Õ : " << my1.empty() << endl;
	my1.print();
	return 0;
}
