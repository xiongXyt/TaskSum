#include"Monster_List.h"

Monster_List::~Monster_List() {
	this->m_LMonster.clear();
}

// ��ӡ
void Monster_List::Print() {
	list<Monster>::iterator it = this->m_LMonster.begin();
	for (; it!=this->m_LMonster.end(); ++it) {
		it->render();
	}
}

// �������
void Monster_List::clead() {
	this->m_LMonster.clear();
}

// β��������һ������ڵ�
void Monster_List::push_back(int num_Hp, int num_Exp, int num_Att) {
	Monster mTemp(num_Hp, num_Exp, num_Att);
	this->m_LMonster.push_back(mTemp);
}

// β��������һ������ڵ�
void Monster_List::push_back(Monster & monster) {
	this->m_LMonster.push_back(monster);
}

// ͷ������һ������ڵ�
void Monster_List::push_front(int num_Hp, int num_Exp, int num_Att) {
	Monster mTemp(num_Hp, num_Exp, num_Att);
	this->m_LMonster.push_front(mTemp);
}

// ͷ������һ������ڵ�
void Monster_List::push_front(Monster& monster) {
	this->m_LMonster.push_front(monster);
}

// ɾ��ĩβԪ��
void Monster_List::pop_back() {
	this->m_LMonster.pop_back();
}

// ɾ���ײ�Ԫ��
void Monster_List::pop_front() {
	this->m_LMonster.pop_front();
}

// ���ص�һ��Ԫ�ص�����
Monster& Monster_List::front() {
	//return *this->m_LMonster.begin();  // �ȼ���
	return this->m_LMonster.front();
}

// �������һ��Ԫ�ص�����
Monster& Monster_List::back() {
	list<Monster>::reverse_iterator it = this->m_LMonster.rend();
	return *(++it);  // *******************************
}

// �����п�
bool Monster_List::empty() {
	return this->m_LMonster.empty();
}

// ��������ĳ���
int Monster_List::size() {
	return this->m_LMonster.size();
}

// ���
void Monster_List::clear() {
	return this->m_LMonster.clear();
}

// λ�ò���
void Monster_List::insert(int pos) {
	if (pos > 0 && pos <= this->m_LMonster.size()) {
		list<Monster>::iterator it = this->m_LMonster.begin();
		for (; it != this->m_LMonster.end(); ++it) {
			if (0 == pos) {
				break;
			}
			--pos;
		}
		Monster mTemp;
		this->m_LMonster.insert(it, mTemp);
	}
	else {
		cout << "�������󣬲���ʧ�ܣ�" << endl;
	}
}

// λ�ò���
void Monster_List::erase(int pos) {
	if (pos > 0 && pos <= this->m_LMonster.size()) {
		list<Monster>::iterator it = this->m_LMonster.begin();
		for (; it != this->m_LMonster.end(); ++it) {
			if (0 == pos) {
				break;
			}
			--pos;
		}
		Monster mTemp;
		this->m_LMonster.erase(it);
	}
	else {
		cout << "�������󣬲���ʧ�ܣ�" << endl;
	}
}

// ��������Ԫ��
void Monster_List::swap(Monster_List& other) {
	this->m_LMonster.swap(other.m_LMonster);
}



