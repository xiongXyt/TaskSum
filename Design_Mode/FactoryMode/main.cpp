#include<iostream>
using namespace std;
/*
* �򵥹���ģʽ��Simple Factory Pattern����һ�ִ��������ģʽ��
* ���ṩ��һ�ִ����������ѷ�ʽ����������ͻ��˱�¶�����߼���
* �򵥹���ģʽ������һ�������࣬
* �����Ը�������Ĳ�����������ͬ��Ķ���
* ���ͻ���ֻ��Ҫ�򹤳������󴴽����󼴿ɣ�����Ҫ֪������Ĵ���ϸ�ڡ�
*
* �򵥹���ģʽ�������¼�����ɫ��
* 1. �����ࣨFactory�������𴴽�����Ĺ����࣬������һ����̬������
* ���ݴ���Ĳ���������ͬ�Ķ��󣬲����ظ��ͻ��ˡ�
* 2. �����Ʒ�ࣨProduct���������˲�Ʒ�Ļ������Ժͷ�����
* �����о����Ʒ��ĸ��ࡣ
* 3. �����Ʒ�ࣨConcrete Product����ʵ���˳����Ʒ�ඨ��ķ�����
* �Ǽ򵥹���ģʽ������Ŀ�����
*
* ʹ�ü򵥹���ģʽ���Խ��Ϳͻ��˺;����Ʒ�����϶ȣ�
* ���ϵͳ�Ŀ�ά���ԺͿ���չ�ԡ�������Ҳ����һЩȱ�㣬
* ���������²�Ʒ��Ҫ�޸Ĺ�����Ĵ��룬Υ���˿���ԭ��
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
