#ifndef _MONSTER_H_
#define _MONSTER_H_
#include"Object.h"

class Monster :public Object {
private:
	int m_Exp;
public:
	Monster() :Object() {
		this->m_Exp = -1;
	}
	Monster(int hp, int att, int def, int exp)
		: Object(hp, att, def) {
		this->m_Exp = exp;
	}

	virtual void Render() {
		std::cout << "Monster : " << std::endl;
		cout << "Hp : " << this->m_Hp << endl;
		cout << "Att : " << this->m_Att << endl;
		cout << "Def : " << this->m_Def << endl;
		cout << "Exp : " << this->m_Exp << endl;
	}
};

#endif // !_MONSTER_H_
