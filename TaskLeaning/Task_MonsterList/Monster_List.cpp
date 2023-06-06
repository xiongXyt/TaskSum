#include"Monster_List.h"

Monster_List::~Monster_List() {
	this->m_LMonster.clear();
}

// 打印
void Monster_List::Print() {
	list<Monster>::iterator it = this->m_LMonster.begin();
	for (; it!=this->m_LMonster.end(); ++it) {
		it->render();
	}
}

// 清空链表
void Monster_List::clead() {
	this->m_LMonster.clear();
}

// 尾部部插入一个怪物节点
void Monster_List::push_back(int num_Hp, int num_Exp, int num_Att) {
	Monster mTemp(num_Hp, num_Exp, num_Att);
	this->m_LMonster.push_back(mTemp);
}

// 尾部部插入一个怪物节点
void Monster_List::push_back(Monster & monster) {
	this->m_LMonster.push_back(monster);
}

// 头部插入一个怪物节点
void Monster_List::push_front(int num_Hp, int num_Exp, int num_Att) {
	Monster mTemp(num_Hp, num_Exp, num_Att);
	this->m_LMonster.push_front(mTemp);
}

// 头部插入一个怪物节点
void Monster_List::push_front(Monster& monster) {
	this->m_LMonster.push_front(monster);
}

// 删除末尾元素
void Monster_List::pop_back() {
	this->m_LMonster.pop_back();
}

// 删除首部元素
void Monster_List::pop_front() {
	this->m_LMonster.pop_front();
}

// 返回第一个元素的引用
Monster& Monster_List::front() {
	//return *this->m_LMonster.begin();  // 等价于
	return this->m_LMonster.front();
}

// 返回最后一个元素的引用
Monster& Monster_List::back() {
	list<Monster>::reverse_iterator it = this->m_LMonster.rend();
	return *(++it);  // *******************************
}

// 链表判空
bool Monster_List::empty() {
	return this->m_LMonster.empty();
}

// 返回链表的长度
int Monster_List::size() {
	return this->m_LMonster.size();
}

// 清空
void Monster_List::clear() {
	return this->m_LMonster.clear();
}

// 位置插入
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
		cout << "索引有误，插入失败！" << endl;
	}
}

// 位置擦除
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
		cout << "索引有误，擦除失败！" << endl;
	}
}

// 交互链表元素
void Monster_List::swap(Monster_List& other) {
	this->m_LMonster.swap(other.m_LMonster);
}



