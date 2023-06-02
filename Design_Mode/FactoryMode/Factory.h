#ifndef _FACTORY_H_
#define _FACTORY_H_
#include"Goods.h"
#include"GoodsA.h"
#include"GoodsB.h"

#include"Object.h"
#include"Monster.h"
#include"Pig.h"


class Factory {
private:

public:
	virtual Goods* CreateGoods() {
		return new Goods;
	}

	virtual Object* CreateObject() {
		return new Object;
	}

};

class FactoryAM :public Factory {
private:

public:
	virtual Goods* CreateGoods() {
		return new GoodsA(100, 200);
	}

	virtual Object* CreateObject() {
		return new Monster(100, 100, 100, 100);
	}

};

class FactoryBP :public Factory {
private:

public:
	virtual Goods* CreateGoods() {
		return new GoodsB(1000, 2000);
	}

	virtual Object* CreateObject() {
		return new Pig(1000, 1000, 1000, 1000);
	}

};

#endif // !_FACTORY_H_
