#ifndef _MONSTER_LIST_H_
#define _MONSTER_LIST_H_
#include<iostream>
#include <list>
#include "Monster.h"
using namespace std;

struct Monster_Node {
	Monster monster;
	Monster_Node* Next_Monster;  // 下一个怪物节点
	Monster_Node* Front_Monster;  // 上一个怪物节点
};

class Monster_List {
private:
	list<Monster>m_LMonster;
public:
	~Monster_List();

	void Print();
	void clead();

	void push_back(int num_Hp = 100, int num_Exp = 100, int num_Att = 10);
	void push_back(Monster& monster);
	void push_front(int num_Hp = 100, int num_Exp = 100, int num_Att = 10);
	void push_front(Monster& monster);
	void pop_back();
	void pop_front();
	Monster& front();
	Monster& back();
	bool empty();
	int size();
	void clear();
	void insert(int pos);
	void erase(int pos);
	void swap(Monster_List& other);
	void remove(Monster_List& other);
};

#endif // !_MONSTER_LIST_H_
