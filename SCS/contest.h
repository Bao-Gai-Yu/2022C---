#pragma once
#include<string>
#include"singer.h"
#include"myList.h"
#include"myList.cpp"
using namespace std;

class contest {
public:
	contest* prev;//���������У�ָ��ǰһ������
	contest* next;//���������У�ָ���һ������
	myList<singer> contestantList;//����������
	contest(string,int);
	void readContestantList(string);//��ȡ��������
	void printContestantList();//����������б�
	void  display();//���������Ϣ
	string getContestName();
	void setContestName(string);
	int getContestantCount();
	void setContestantCount(int);
	friend ofstream& operator <<(ofstream&,contest&);
private:
	string contestName;//��������
	int contestantCount;//����������
};