#pragma once
template <typename T>
class myList {
public:
	myList();
	~myList();
	int getSize();//����������Ԫ�ظ���
	void addNode(T&);//������ĩβ���Ԫ��
	void printList();//�������������
	void swapNodes(int ,int);//��������������Ԫ��λ��
	void deleteNode(int);//������ɾ��Ԫ��
	T* getNode(int);//���һ��Ԫ��

private:
	T* listHead;//����ͷ��������ΪNULL����ָ������ĵ�һ��Ԫ��
	T* listEnd;//����β
	int size;//�����С
};