#pragma once
#include<string>
#include<iostream>
#include"singer.h"
#include"contest.h"
using namespace std;
//����������
class basic {
public:
	basic();
	void showSingers(contest*);//��ʾ������Ϣ��������ʾ��������
	void search(contest*);//��������,֧��ģ������
};

//��ͨ�û���
class user :public basic {
public:
	user(string,int);
	~user();
	void voteSinger(int, singer*);//������ͶƱ
private:
	string id;//�û���ID
	bool* voted;//��¼��ǰ�û������ε�ͶƱ���
};

//����Ա�û���
class admin :public basic {
public:
	void addContest(myList<contest>&, int&);//׷�ӱ�����Ϣ
	void modifyContestData(myList<contest>&, int&);//�޸ı�������
	void deleteContest(myList<contest>&, int&);//ɾ��������Ϣ
	void addSingerData(contest*);//׷�Ӹ�������
	void modifySingerData(contest*);//�޸ĸ�������
	void deleteSingerData(contest*);//ɾ����������
};