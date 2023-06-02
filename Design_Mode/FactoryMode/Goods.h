#ifndef _GOODS_H_
#define _GOODS_H_
#include<iostream>
using namespace std;

class Goods {
protected:
	int m_Hp;
public:
	Goods() :m_Hp(-1) {};
	Goods(int hp) :m_Hp(hp) {};

	void SetHp(int num) {
		this->m_Hp = num;
	}

	int GetHp() {
		return this->m_Hp;
	}

	virtual void Render() {
		cout << "Goods : " << endl;
	}

};

#endif // !_GOODS_H_
