#include<iostream>
#include "MyStack.h"
using namespace std;


int main() {
	//MyStackVector  mystackvector1(3);
	//MyStackVector  mystackvector2(4);
	//mystackvector1.Swap(mystackvector2);
	//mystackvector1.Print();
	//mystackvector2.Print();

	MyStackList  mystacklist1(3);
	MyStackList  mystacklist2(4);
	mystacklist1.Swap(mystacklist2);
	mystacklist1.Print();
	mystacklist2.Print();

	return 0;
}
