#ifndef _GOODSB_H_
#define _GOODSB_H_
#include"Goods.h"

class GoodsB :public Goods {
private:
	int m_Exp;
public:
	GoodsB() :Goods(), m_Exp(-1) {};
	GoodsB(int hp, int exp) :Goods(hp), m_Exp(exp) {};

	virtual void Render() {
		cout << "GoodsB : " << endl;
		cout << "Hp : " << this->m_Hp << endl;
		cout << "Exp : " << this->m_Exp << endl;
	}

};

#endif // !_GOODSB_H_
