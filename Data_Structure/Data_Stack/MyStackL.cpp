#include"MyStack.h"

MyStackList::MyStackList() {}
MyStackList::MyStackList(int num) {
	this->m_L.push_back(num);
}
MyStackList::~MyStackList() {
	this->m_L.clear();
}

bool  MyStackList::IsEmpty() {
	return this->m_L.empty();
}
void  MyStackList::Push_Back(int num) {
	this->m_L.push_back(num);
}
void  MyStackList::Pop_Back() {
	this->m_L.pop_back();
}
int& MyStackList::Back() {
	return this->m_L.back();
}
int   MyStackList::Size() {
	return this->m_L.size();
}
void  MyStackList::Swap(MyStackList& other) {
	this->m_L.swap(other.m_L);
}
void  MyStackList::Print() {
	list<int>::iterator it = this->m_L.begin();
	for (; it != this->m_L.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl << " ---------- " << endl;
}
