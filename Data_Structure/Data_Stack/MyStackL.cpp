#include"MyStackL.h"

MyStackList::MyStackList() {}
MyStackList::MyStackList(int num) {
	this->m_L.push_back(num);
}
MyStackList::~MyStackList() {
	this->m_L.clear();
}

// �п� Stack
bool  MyStackList::IsEmpty() {
	return this->m_L.empty();
}

// ѹ stack
void  MyStackList::Push(int num) {
	this->m_L.push_back(num);
}

// �� Stack 
void  MyStackList::Pop() {
	if (this->IsEmpty()) {
		cout << "ջΪ�գ�" << endl;
	}
	else {
		this->m_L.pop_back();
	}
}

// ����ջ��Ԫ��
int MyStackList::Top() {
	if (this->IsEmpty()) {
		cout << "ջΪ�գ�" << endl;
		return this->Size();
	}
	else {
		return this->m_L.back();
	}
}

// ���� Stack ����Ԫ�ص�����
int& MyStackList::Back() {
	if (this->IsEmpty()) {
		cout << "ջΪ�գ�" << endl;
		int num = this->Size();
		int& number = num;
		return number;
	}
	else {
		return this->m_L.back();
	}

}

// Stack �Ĵ�С
int   MyStackList::Size() {
	return this->m_L.size();
}

// ����
void  MyStackList::Swap(MyStackList& other) {
	this->m_L.swap(other.m_L);
}

// 
void  MyStackList::Print() {
	list<int>::iterator it = this->m_L.begin();
	for (; it != this->m_L.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl << " ---------- " << endl;
}
