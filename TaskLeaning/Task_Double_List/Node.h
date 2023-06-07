#ifndef _NODE_H_
#define _NODE_H_

/*
д����Ĳ�:
1.���ݳ�Ա
2.�Ĵ�Ĭ�ϳ�Ա����
	����:��ʼ��
	����:�ͷ��ڴ�
	��������:���
	��ֵ:�����ͬʱ
3.��Ա����
4.���ӳ�Ա
*/
class Node {
public:
	friend class List;  // List��ΪNode�����Ԫ��
	friend class Iterator;
	Node();
	// ȱʡֻ��д��������
	Node(int data, Node* pFront = nullptr, Node* pNext = nullptr);
	~Node();
private:
	int data;		// ������
	Node* pFront;	// ǰ��ָ��:ָ����һ�����
	Node* pNext;	// ���ָ��:ָ����һ�����
};

#endif // !_NODE_H_
