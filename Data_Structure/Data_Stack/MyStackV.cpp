#include"MyStackV.h"

MyStackVector::MyStackVector() {}

// ���캬��num����numԪ�ص�ջ
MyStackVector::MyStackVector(int num) {
	for (int i = 0; i < num; ++i) {
		this->Push(num);
	}
}

// ջΪ��
bool MyStackVector::IsEmpty() {
	return this->m_V.empty();
}

// ѹջ
void MyStackVector::Push(int num) {
	this->m_V.push_back(num);
}

// ��ջ�������ر���ջԪ��
void MyStackVector::Pop() {
	if (this->IsEmpty()) {  // Ϊ��
		cout << "ջΪ�գ�" << endl;
	}
	else {
		this->m_V.pop_back();  // ��֪����û���пգ�������������û���п�
	}
}

// ����ջ��Ԫ��
int MyStackVector::Top() {
	if (this->IsEmpty()) {  // Ϊ��
		cout << "ջΪ�գ�" << endl;
		return this->Size();
	}
	else {
		return this->m_V.back();
	}
}

// �������һ��Ԫ�ص�����
int& MyStackVector::Back() {
	if (this->IsEmpty()) {
		cout << "ջΪ�գ�" << endl;
		int num = this->Size();
		int &number = num;
		return number;
	}
	else {
		return this->m_V.back();
	}

}

// ����ջ�ĵ�ǰ����
int MyStackVector::Size() {
	return this->m_V.size();
}

// ��������ջԪ��
void MyStackVector::Swap(MyStackVector& other) {
	MyStackVector temp;

	// ��ȡ�˴�С�����Բ��ÿ���Ϊ�յ����
	for (int i = other.Size() - 1; i >= 0; --i) {
		// otherջ������ʱջ
		temp.Push(other.Back());
		other.Pop();
	}
	for (int i = this->Size() - 1; i >= 0; --i) {
		// otherջ��ȡ��ǰջԪ��
		other.Push(this->Back());
		this->Pop();
	}
	for (int i = temp.Size() - 1; i >= 0; --i) {
		// ��ǰջ��ȡ��ʱջ��Ԫ��
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