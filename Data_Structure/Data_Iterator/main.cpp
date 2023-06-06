#include<iostream>
#include"MyList.h"
using namespace std;


int main() {
	MyList mylist;
	for (int i = 10; i > 0; --i) {
		mylist.AddList(i);
	}
	ListIterator it = mylist.begin();
	for (; it != mylist.end(); it++) {
		cout << it.m_Node->data << endl;
	}
	return 0;
}
