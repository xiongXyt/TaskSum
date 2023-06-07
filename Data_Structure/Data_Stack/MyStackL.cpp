#include"MyStackL.h"

MyStackList::MyStackList() {}
MyStackList::MyStackList(int num) {
	this->m_L.push_back(num);
}
MyStackList::~MyStackList() {
	this->m_L.clear();
}

// 判空 Stack
bool  MyStackList::IsEmpty() {
	return this->m_L.empty();
}

// 压 stack
void  MyStackList::Push(int num) {
	this->m_L.push_back(num);
}

// 出 Stack 
void  MyStackList::Pop() {
	if (this->IsEmpty()) {
		cout << "栈为空！" << endl;
	}
	else {
		this->m_L.pop_back();
	}
}

// 访问栈顶元素
int MyStackList::Top() {
	if (this->IsEmpty()) {
		cout << "栈为空！" << endl;
		return this->Size();
	}
	else {
		return this->m_L.back();
	}
}

// 返回 Stack 顶部元素的引用
int& MyStackList::Back() {
	if (this->IsEmpty()) {
		cout << "栈为空！" << endl;
		int num = this->Size();
		int& number = num;
		return number;
	}
	else {
		return this->m_L.back();
	}

}

// Stack 的大小
int   MyStackList::Size() {
	return this->m_L.size();
}

// 交换
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
