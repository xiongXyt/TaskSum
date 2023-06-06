#include"MyStack.h"

MyStackVector::MyStackVector() {}
MyStackVector::MyStackVector(int num) {  // 构造含有num个，num元素的栈
	for (int i = 0; i < num; ++i) {
		this->Push_Back(num);
	}
}

bool MyStackVector::IsEmpty() {  // 栈为空
	return this->m_V.empty();
}

void MyStackVector::Push_Back(int num) {  // 压栈
	this->m_V.push_back(num);
}

void MyStackVector::Pop_Back() {  // 出栈，不返回被出栈元素
	if (this->IsEmpty()) {  // 为空
		return;
	}
	this->m_V.pop_back();  // 不知道有没有判空
}

int& MyStackVector::Back() {  // 返回最后一个元素的引用
	return this->m_V.back();
}

int MyStackVector::Size() {  // 返回栈的当前容量
	return this->m_V.size();
}

void MyStackVector::Swap(MyStackVector& other) {  // 交换两个栈元素
	MyStackVector temp;

	// 获取了大小，所以不用考虑为空的情况
	for (int i = other.Size() - 1; i >= 0; --i) {
		// other栈存入临时栈
		temp.Push_Back(other.Back());
		other.Pop_Back();
	}
	for (int i = this->Size() - 1; i >= 0; --i) {
		// other栈获取当前栈元素
		other.Push_Back(this->Back());
		this->Pop_Back();
	}
	for (int i = temp.Size() - 1; i >= 0; --i) {
		// 当前栈获取临时栈的元素
		this->Push_Back(temp.Back());
		temp.Pop_Back();
	}
}

void MyStackVector::Print() {
	vector<int>::iterator it = this->m_V.begin();
	for (; it != this->m_V.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl << " ---------- " << endl;
}