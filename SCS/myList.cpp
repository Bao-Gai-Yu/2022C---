#include"myList.h"
#include<iostream>
#include<cmath>
using namespace std;
template <typename T>
myList<T>::myList()
{
	listHead = NULL;
	listEnd = NULL;
	size = 0;
}

template <typename T>
myList<T>::~myList()
{
	while (size--)
		deleteNode(1);
}

template <typename T>
int myList<T>::getSize()//����������Ԫ�ظ���
{
	return size;
}

template <typename T>
void myList<T>::addNode(T& newNode)//�������ĩβ����µ�Ԫ��
{
	if (size == 0)
	{
		listHead = &newNode;	//���sizeΪ0����ʾ��������δ����Ԫ�عʴ�ʱ�����м�
		listEnd = &newNode;		//���˵�һ��Ԫ�أ���ͷ�ͱ�β��ָ���Ԫ�ء�
		newNode.prev = NULL;	//��Ȼ�����е�����Ԫ��singer������е�prev��next��
		newNode.next = NULL;	//ֵ��ΪNULL��������������Ƕ�����и�ֵNULL
	}
	else
	{
		newNode.prev = listEnd;	//��Ԫ�ص�ǰ��ָ������β
		newNode.next = NULL;	//��Ԫ�صĺ�������ΪNULL
		listEnd->next = &newNode;//����ĩβԪ�صĺ���ָ����Ԫ�أ��������
		listEnd = &newNode;		//��������βָ��Ϊ�¼����Ԫ��
	}
	size += 1;					//���Ҫ��������Ԫ������+1
	return;
}

template <typename T>
void myList<T>::printList()//�����������
{
	T* p = listHead;
	if (p == NULL)//pΪNULL�����ʾ��������δ����κ�Ԫ��
	{
		cout << "�������ݣ��޷��鿴��" << endl;
	}
	else
	{
		int tmp = 1;
		while (p != NULL)
		{
			cout << "###########################################################" << endl;
			cout << "->" << tmp << "  " << endl;
			p->display();		//����display()�����������
			cout << endl;
			p = p->next;
			tmp += 1;
		}
	}
	return;
}

template <typename T>
void myList<T>::swapNodes(int index1,int index2)
{
	if (index1 > size || index1<1 || index2 > size || index2<1)
	{
		cout << "��������" << endl;
		return;
	}
	if (index1 > index2)//��֤�ڲ��ҽ���λ�ú��������λ����p1��p2ǰ��
	{
		int t = index2;
		index2 = index1;
		index1 = t;
	}
	T* p1 = listHead;
	T* p2 = listHead;
	while (index1 != 1)//Ѱ��Ҫ����������Ԫ��
	{
		p1 = p1->next;
		index1 -= 1;
	}
	while (index2 != 1)//p1��p2ָ������Ҫ������Ԫ��
	{
		p2 = p2->next;
		index2 -= 1;
	}
	if (p1 == listHead)	//���p1ָ������ͷ����p2����Ϊ�µ�����ͷ
		listHead = p2;
	else if (p2 == listHead)//���p2ָ������ͷ����p1����Ϊ�µ�����ͷ
		listHead = p1;
	if (p1 == listEnd)	//���p1ָ������β����p2����Ϊ�µ�����β
		listEnd = p2;
	else if (p2 == listEnd)//���p2ָ������β����p1����Ϊ�µ�����β
		listEnd = p1;
	T* p1Prev = p1->prev;//Ԥ��p1��ǰ������Ϣ
	T* p1Next = p1->next;
	T* p2Prev = p2->prev;//Ԥ��p2��ǰ������Ϣ
	T* p2Next = p2->next;
	if (p1==p2Prev)		//���⴦��Ҫ������������Ԫ�ص����
	{
		p1->prev = p2;
		p1->next = p2Next;
		if (p1Prev != NULL)
			p1Prev->next = p2;
		p2->prev = p1Prev;
		p2->next = p1;
		if (p2Next != NULL)
			p2Next->prev = p1;
	}
	else
	{
		p1->prev = p2Prev;//����p1��ǰ������ϢΪp2��ǰ������Ϣ
		p1->next = p2Next;
		p2->prev = p1Prev;//����p2��ǰ������ϢΪԭ��p1��ǰ������Ϣ
		p2->next = p1Next;
		if (p1Prev != NULL)
			p1Prev->next = p2;
		if (p1Next != NULL)
			p1Next->prev = p2;
		if (p2Prev != NULL)
			p2Prev->next = p1;
		if (p2Next != NULL)
			p2Next->prev = p1;
	}
	return;
}

template <typename T>
void myList<T>::deleteNode(int index)//ɾ�����
{
	if (size == 0)
	{
		cout << "������ȫ��ɾ�����������ݿ�ɾ����" << endl;
		return;
	}
	else
	{
		T* p = listHead;
		while (index != 1)
		{
			p = p->next;
			index -= 1;
		}
		if (p == listHead)
			listHead = p->next;
		else if (p == listEnd)
			listEnd = p->prev;
		T* pPrev = p->prev;
		T* pNext = p->next;
		if (pPrev != NULL)
			pPrev->next = pNext;
		if (pNext != NULL)
			pNext->prev = pPrev;
		delete p;
		size -= 1;
	}
}

template <typename T>
T* myList<T>::getNode(int index)//���ָ��һ������ָ��
{
	T* p = listHead;
	while (index != 1)
	{
		p = p->next;
		index -= 1;
	}
	return p;
}