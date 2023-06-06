#ifndef _MONSTER_H_
#define _MONSTER_H_
#include<iostream>
using namespace std;

class Monster {
private:
	int m_Hp;
	int m_Exp;
	int m_Att;
	int m_num;
	static int number;
public:
	Monster() {
		this->m_Exp = this->m_Hp = 100;
		this->m_Att = 10;
		this->m_num = ++number;
	}
	Monster(int num_Hp) {
		this->m_Exp = 100;
		this->m_Hp = 1000;
		this->m_Att = 10;
		this->m_num = ++number;
	}
	Monster(int num_Hp, int num_Exp) {
		this->m_Exp = num_Exp;
		this->m_Hp = num_Hp;
		this->m_Att = 10;
		this->m_num = ++number;
	}
	Monster(int num_Hp, int num_Exp,int num_Att) {
		this->m_Exp = num_Exp;
		this->m_Hp = num_Hp;
		this->m_Att = num_Att;
		this->m_num = ++number;
	}

	~Monster() {
		--number;
	}

	void Set_Hp(int num_Hp) {
		this->m_Hp = num_Hp;
	}
	void Set_Exp(int num_Exp) {
		this->m_Exp = num_Exp;
	}
	int Get_Hp() {
		return this->m_Hp;
	}
	int Get_Exp() {
		return this->m_Exp;
	}

	void render() {
		cout << " number: " << this->m_num << endl;
		cout << " m_Hp  : "<<this->m_Hp << endl;
		cout << " m_Exp : "<<this->m_Exp << endl;
		cout << " m_Att : "<<this->m_Att << endl;
		cout << " ----- ----- ----- ----- -----" << endl << endl;
	}
};

#endif // !_MONSTER_H_
