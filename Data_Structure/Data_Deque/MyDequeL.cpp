#include"MyDequeL.h"

MyDequeL::MyDequeL() {

}

MyDequeL::~MyDequeL() {
	this->m_deque.clear();
}

// �������һ��Ԫ��
int& MyDequeL::back() {
	if (this->empty()) {
		cout << "����Ϊ�գ�" << endl;
		int num = this->size();
		int& number = num;
		return number;
	}
	else {
		return this->m_deque.back();
	}
}

// ������п��򷵻���
bool MyDequeL::empty() {
	return this->m_deque.empty();
}

// ���ص�һ��Ԫ��
int& MyDequeL::front() {
	if (this->empty()) {
		cout << "����Ϊ�գ�" << endl;
		int num = this->size();
		int& number = num;
		return number;
	}
	else {
		this->m_deque.front();
	}
}

// ɾ����һ��Ԫ��
void MyDequeL::pop() {
	if (this->empty()) {
		cout << "����Ϊ�գ�" << endl;
	}
	else {
		this->m_deque.pop_front();
	}
}

// ��ĩβ����һ��Ԫ��
void MyDequeL::push(int num) {
	this->m_deque.push_back(num);
}

// ���ض�����Ԫ�صĸ���
int  MyDequeL::size() {
	return this->m_deque.size();
}

// ��ӡ����
void MyDequeL::print() {
	list<int>::iterator it = this->m_deque.begin();
	for (; it != this->m_deque.end(); ++it) {
		cout << *(it) << endl;
	}
	cout << "----- ----- ----- -----" << endl << endl;
}
