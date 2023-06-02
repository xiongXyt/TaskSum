#ifndef _PIG_H_
#define _PIG_H_
#include"Object.h"

class Pig :public Object {
private:
	int m_Exp;
public:
	Pig() :Object() {
		this->m_Exp = -1;
	}

	Pig(int hp, int att, int def, int exp)
		: Object(hp, att, def) {
		this->m_Exp = exp;
	}

	virtual void Render() {
		std::cout << "Pig : " << std::endl;
		cout << "Hp : " << this->m_Hp << endl;
		cout << "Att : " << this->m_Att << endl;
		cout << "Def : " << this->m_Def << endl;
		cout << "Exp : " << this->m_Exp << endl;
	}

};

#endif // !_PIG_H_
