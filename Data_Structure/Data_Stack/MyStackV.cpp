#include"MyStackV.h"

MyStackVector::MyStackVector() {}

// 构造含有num个，num元素的栈
MyStackVector::MyStackVector(int num) {
	for (int i = 0; i < num; ++i) {
		this->Push(num);
	}
}

// 栈为空
bool MyStackVector::IsEmpty() {
	return this->m_V.empty();
}

// 压栈
void MyStackVector::Push(int num) {
	this->m_V.push_back(num);
}

// 出栈，不返回被出栈元素
void MyStackVector::Pop() {
	if (this->IsEmpty()) {  // 为空
		cout << "栈为空！" << endl;
	}
	else {
		this->m_V.pop_back();  // 不知道有没有判空，测试了他就是没有判空
	}
}

// 访问栈顶元素
int MyStackVector::Top() {
	if (this->IsEmpty()) {  // 为空
		cout << "栈为空！" << endl;
		return this->Size();
	}
	else {
		return this->m_V.back();
	}
}

// 返回最后一个元素的引用
int& MyStackVector::Back() {
	if (this->IsEmpty()) {
		cout << "栈为空！" << endl;
		int num = this->Size();
		int &number = num;
		return number;
	}
	else {
		return this->m_V.back();
	}

}

// 返回栈的当前容量
int MyStackVector::Size() {
	return this->m_V.size();
}

// 交换两个栈元素
void MyStackVector::Swap(MyStackVector& other) {
	MyStackVector temp;

	// 获取了大小，所以不用考虑为空的情况
	for (int i = other.Size() - 1; i >= 0; --i) {
		// other栈存入临时栈
		temp.Push(other.Back());
		other.Pop();
	}
	for (int i = this->Size() - 1; i >= 0; --i) {
		// other栈获取当前栈元素
		other.Push(this->Back());
		this->Pop();
	}
	for (int i = temp.Size() - 1; i >= 0; --i) {
		// 当前栈获取临时栈的元素
		this->Push(temp.Back());
		temp.Pop();
	}
}

void MyStackVector::Print() {
	vector<int>::iterator it = this->m_V.begin();
	for (; it != this->m_V.end(); ++it) {
		cout << *it << endl;
	}
	cout << endl << " ---------- " << endl;
}