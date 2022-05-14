#pragma once
#include<string>
#include"myList.h"
using namespace std;
class singer {
public:
	singer* prev;//���������У�ָ����ǰһ��Ԫ��
	singer* next;//���������У�ָ�����һ��Ԫ��
	singer();
	void setNumber(string);//���ñ��
	void setName(string);//��������
	void setScore(int, double);//������ίi+1�Ĵ��(0-9)
	void countScores();//���������ͷ֣��ܵ÷֣�ƽ����
	void setVotes(int);//���ù���ͶƱ��
	void setPromoted(int);
	void display();//���������Ϣ
	string getNumber()const;//���ر��
	string getName()const;//��������
	double getScore(int)const;//int Ϊ1-10���򷵻���ί1-10��֣�11������߷֣�12������ͷ֣�13�����ܷ֣�14����ƽ���֣�15����ͶƱ��
	int getVotes()const;//���ع���ͶƱ��
	int getPromoted()const;//�����Ƿ����
	friend void checkPromoted(myList<singer>&,int);
	friend ofstream& operator <<(ofstream&, const singer&);
	double& operator [](int);
private:
	string number;//���ֱ��
	string name;//��������
	double score[10];//ʮ����ί���
	double maxScore;//��ί��߷�
	double minScore;//��ί��ͷ�
	double totalScore;//��ί�ܵ÷֣�������ȥ�������ͷֵģ�
	double averageScore;//ƽ���÷֣�ȥ�������ͺ�ģ�
	double votes;//��õ��û�ͶƱ��
	double finalScore;//�ۺϵ÷�
	int isPromtoted;//���ø�ѡ���Ƿ����,0��ʾδ������1��ʾ�ѽ���
};