#ifndef _OBJECT_H_
#define _OBJECT_H_
#include<iostream>
using namespace std;

class Object {
protected:
	int m_Hp;
	int m_Att;
	int m_Def;
public:
	Object() {
		this->m_Hp = -1;
		this->m_Att = -1;
		this->m_Def = -1;
	}
	Object(int hp, int att, int def)
		:m_Hp(hp), m_Att(att), m_Def(def) {};

	void SetHp(int num) {
		this->m_Hp = num;
	}
	void SetAtt(int num) {
		this->m_Att = num;
	}
	void SetDef(int num) {
		this->m_Def = num;
	}

	int GetHp() {
		return this->m_Hp;
	}
	int GetAtt() {
		return this->m_Att;
	}
	int GetDef() {
		return this->m_Def;
	}

	virtual void Render() {
		cout << "Object : " << endl;
	}
};

#endif // !_OBJECT_H_
