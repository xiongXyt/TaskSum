#include <iostream>
#include "List.h"
using namespace std;
#include "Iterator.h"
/*
1.reverse
2.merge
3.sort(����)
4.erase
*/
/*
1.�����:������/ָ����(ǰ��ָ��/���ָ��)
2.������:ͷ���/β���
*/
int main() {
	//// β���������
	//List list1;
	//List list2;
	//for (int i = 1; i <= 10; ++i) {
	//	list1.push_back(i);
	//}
	//list1.print();

	//// ͷ��ɾ������
	//List list1;
	//List list2;
	//for (int i = 1; i <= 10; ++i) {
	//	list1.push_back(i);
	//}
	//list1.print();
	//list1.pop_front();
	//list1.print();

	// �����пպ�����������
	//List list1;
	//List list2;
	//for (int i = 1; i <= 10; ++i) {
	//	list1.push_back(i);
	//}
	//list1.print();
	//cout << "list1.empty() : " << list1.empty() << endl;
	//list1.clear();
	//cout << "list1.empty() : " << list1.empty() << endl;
	//list1.print();

	// �Ƴ�ָ��Ԫ�ز���
	//List list1;
	//List list2;
	//for (int i = 1; i <= 2; ++i) {
	//	list1.push_back(1);
	//}
	//for (int i = 1; i <= 10; ++i) {
	//	list1.push_back(i);
	//}
	//list1.print();
	//list1.remove(1);
	//list1.remove(10);
	//list1.print();

	//// ɾ���������ظ�Ԫ�ز���
	//List list1;
	//List list2;
	//list1.push_back(1);
	//list1.push_back(1);
	//list1.push_back(2);
	//list1.push_back(2);
	//list1.push_back(3);
	//list1.push_back(3);
	//list1.push_back(4);
	//list1.push_back(4);
	//list1.push_back(5);
	//list1.push_back(5);
	//list1.push_back(6);
	//list1.push_back(6);
	//list1.print();
	//list1.unique();
	//list1.print();

	//// ������������
	//List list1;
	//List list2;
	//for (int i = 1; i <= 20; ++i) {
	//	if (0 == i%2) {
	//		list1.push_back(i);
	//	}
	//	else {
	//		list2.push_back(i);
	//	}
	//}
	//list1.print();
	//list2.print();
	//list1.swap(list2);
	//list1.print();
	//list2.print();

	//// ˳��ת
	//List list1;
	//List list2;
	//for (int i = 1; i <= 20; ++i) {
	//	list1.push_back(i);
	//}
	//list1.print();
	//list1.reverse();
	//list1.print();

	//// ������������
	//List list1;
	//List list2;
	//for (int i = 30; i >= 1; --i) {
	//	list1.push_back(i);
	//}
	//list1.push_back(100);
	//list1.print();
	//list1.sort();
	//list1.print();

	//// ��һ�� list ת��Ԫ�ظ���һ������
	//List list1;
	//List list2;
	//for (int i = 10; i >= 1; --i) {
	//	list1.push_back(1);
	//	list2.push_back(2);
	//}
	//list1.print();
	//list2.print();
	//Iterator it = list1.begin();
	//++it++;
	//list1.splice(it, list2);
	//list1.print();
	//list2.print();

	// ��һ�� list ת��Ԫ�ظ���һ������
	List list1;
	List list2;
	for (int i = 10; i >= 1; --i) {
		list1.push_back(1);
		list2.push_back(2);
	}
	list1.print();
	list2.print();
	Iterator it = list1.begin();
	++it++;
	Iterator itlst = list2.begin();
	itlst = itlst + 9;
	list1.splice(it, list2, itlst, list2.end());
	list1.print();
	list2.print();

	//cout << endl << endl;
	//cout << "***** ***** ***** " << endl;
	//cout << "***** ***** ***** " << endl;

	//List l;
	//// ��ͷ������-1
	//// l.insert(l.begin(), -1);
	//l.push_back(-1);
	//l.push_back(1);
	//l.push_back(3);
	//l.push_back(8);
	//l.push_back(10);
	//l.push_back(20);
	//l.print();

	//l.pop_front();
	//l.print();

	//List other;
	//other.push_back(2);
	//other.push_back(4);
	//other.push_back(6);

	//l.splice(l.begin(), other);
	//l.merge(other);
	//l.sort();
	//l.print();
	//cout << "*********************" << endl;
	//other.print();


	//l.pop_front();
	//l.pop_front();
	//l.print();
	//l.clear();

	//l.push_back(3);
	//l.push_back(-1);
	//l.push_back(2);
	//l.push_back(2);
	//l.push_back(-5);
	//l.push_back(2);
	////l.remove(2);
	//l.unique();
	//l.print();


	//// ɾ������ż��
	//Iterator it = l.begin();
	//for (; it != l.end();)
	//{
	//	if (0 == (*it) % 2)
	//	{
	//		it = l.erase(it);
	//	}
	//	else
	//	{
	//		++it;
	//	}
	//}
	//l.print();
	return 0;
}