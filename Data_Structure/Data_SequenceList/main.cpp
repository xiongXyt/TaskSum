#include<iostream>
#include"SList.h"
using namespace std;

int main() {
	short num[3] = { 1,2,3 };
	SList myarr01;
	SList myarr02(10, 100);
	SList myarr03(num, num + 3);
	SList myarr04(myarr03);
	myarr01.PrintArr();
	myarr02.PrintArr();
	myarr03.PrintArr();
	myarr04.PrintArr();

	return 0;
}