#include"MyStack.h"

MyStackVector::MyStackVector() {}
MyStackVector::MyStackVector(int num) {  // ���캬��num����numԪ�ص�ջ
	for (int i = 0; i < num; ++i) {
		this->Push_Back(num);
	}
}

bool MyStackVector::IsEmpty() {  // ջΪ��
	return this->m_V.empty();
}

void MyStackVector::Push_Back(int num) {  // ѹջ
	this->m_V.push_back(num);
}

void MyStackVector::Pop_Back() {  // ��ջ�������ر���ջԪ��
	if (this->IsEmpty()) {  // Ϊ��
		return;
	}
	this->m_V.pop_back();  // ��֪����û���п�
}

int& MyStackVector::Back() {  // �������һ��Ԫ�ص�����
	return this->m_V.back();
}

int MyStackVector::Size() {  // ����ջ�ĵ�ǰ����
	return this->m_V.size();
}

void MyStackVector::Swap(MyStackVector& other) {  // ��������ջԪ��
	MyStackVector temp;

	// ��ȡ�˴�С�����Բ��ÿ���Ϊ�յ����
	for (int i = other.Size() - 1; i >= 0; --i) {
		// otherջ������ʱջ
		temp.Push_Back(other.Back());
		other.Pop_Back();
	}
	for (int i = this->Size() - 1; i >= 0; --i) {
		// otherջ��ȡ��ǰջԪ��
		other.Push_Back(this->Back());
		this->Pop_Back();
	}
	for (int i = temp.Size() - 1; i >= 0; --i) {
		// ��ǰջ��ȡ��ʱջ��Ԫ��
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