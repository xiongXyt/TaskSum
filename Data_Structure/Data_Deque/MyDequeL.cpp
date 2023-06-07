#include"MyDequeL.h"

MyDequeL::MyDequeL() {

}

MyDequeL::~MyDequeL() {
	this->m_deque.clear();
}

// 返回最后一个元素
int& MyDequeL::back() {
	if (this->empty()) {
		cout << "队列为空！" << endl;
		int num = this->size();
		int& number = num;
		return number;
	}
	else {
		return this->m_deque.back();
	}
}

// 如果队列空则返回真
bool MyDequeL::empty() {
	return this->m_deque.empty();
}

// 返回第一个元素
int& MyDequeL::front() {
	if (this->empty()) {
		cout << "队列为空！" << endl;
		int num = this->size();
		int& number = num;
		return number;
	}
	else {
		this->m_deque.front();
	}
}

// 删除第一个元素
void MyDequeL::pop() {
	if (this->empty()) {
		cout << "队列为空！" << endl;
	}
	else {
		this->m_deque.pop_front();
	}
}

// 在末尾加入一个元素
void MyDequeL::push(int num) {
	this->m_deque.push_back(num);
}

// 返回队列中元素的个数
int  MyDequeL::size() {
	return this->m_deque.size();
}

// 打印函数
void MyDequeL::print() {
	list<int>::iterator it = this->m_deque.begin();
	for (; it != this->m_deque.end(); ++it) {
		cout << *(it) << endl;
	}
	cout << "----- ----- ----- -----" << endl << endl;
}
