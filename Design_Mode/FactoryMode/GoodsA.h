#ifndef _GOODSA_H_
#define _GOODSA_H_
#include"Goods.h"

class GoodsA :public Goods {
private:
	int m_Exp;
public:
	GoodsA() :Goods(), m_Exp(-1) {};
	GoodsA(int hp, int exp) :Goods(hp), m_Exp(exp) {};

	virtual void Render() {
		cout << "GoodsA : " << endl;
		cout << "Hp : " << this->m_Hp << endl;
		cout << "Exp : " << this->m_Exp << endl;
	}

};

#endif // !_GOODSA_H_
