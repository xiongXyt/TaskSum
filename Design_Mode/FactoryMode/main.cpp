#include<iostream>
using namespace std;
/*
* 简单工厂模式（Simple Factory Pattern）是一种创建型设计模式，
* 它提供了一种创建对象的最佳方式，而无需向客户端暴露创建逻辑。
* 简单工厂模式定义了一个工厂类，
* 它可以根据所需的参数来创建不同类的对象，
* 而客户端只需要向工厂类请求创建对象即可，不需要知道具体的创建细节。
*
* 简单工厂模式包含以下几个角色：
* 1. 工厂类（Factory）：负责创建对象的工厂类，它包含一个静态方法，
* 根据传入的参数创建不同的对象，并返回给客户端。
* 2. 抽象产品类（Product）：定义了产品的基本属性和方法，
* 是所有具体产品类的父类。
* 3. 具体产品类（Concrete Product）：实现了抽象产品类定义的方法，
* 是简单工厂模式创建的目标对象。
*
* 使用简单工厂模式可以降低客户端和具体产品类的耦合度，
* 提高系统的可维护性和可扩展性。但是它也存在一些缺点，
* 例如增加新产品需要修改工厂类的代码，违反了开闭原则。
*/
#include"Factory.h"

int main() {
	Factory factory;
	FactoryAM factoryam;
	FactoryBP factorybp;
	Goods* goods = factoryam.CreateGoods();
	goods->Render();
	Object* object = factorybp.CreateObject();
	object->Render();

	delete goods;
	goods = nullptr;

	delete object;
	object = nullptr;
	return 0;


}
