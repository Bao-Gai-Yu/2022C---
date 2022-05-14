#include"singer.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

singer::singer()
{
	prev = NULL;
	next = NULL;
	number = "Nan";
	name = "Nan";
	for (int i = 0;i < 10;i++)
		score[i] = 0;
	maxScore = 0;
	minScore = 0;
	totalScore = 0;
	averageScore = 0;
	votes = 0;
	isPromtoted = 0;
}

void singer::setNumber(string numS)
{
	number = numS;
	return;
}

void singer::setName(string nameS)
{
	name = nameS;
	return;
}

void singer::setScore(int index,double sco)
{
	score[index] = sco;
	return;
}

void singer::countScores()
{
	totalScore = score[0];
	maxScore = score[0];
	minScore = score[0];
	for (int i = 1;i < 10;i++)
	{
		totalScore += score[i];
		if (score[i] > maxScore)
			maxScore = score[i];
		if (score[i] < minScore)
			minScore = score[i];
	}
	averageScore = (totalScore - maxScore - minScore) / 8;
	finalScore = (totalScore - maxScore - minScore + votes / 10.0) / 9;
	return;
}

void singer::setVotes(int v)
{
	votes = v;
	return;
}

void singer::setPromoted(int f)
{
	isPromtoted = f;
	return;
}

void singer::display()
{
	cout << setprecision(1);
	cout << "\t��ţ�" << number <<endl;
	cout << endl;
	cout << "\t������" << name << endl;
	cout << endl;
	cout << "\t��߷֣�" << maxScore <<"\t��ͷ֣�"<<minScore << endl;
	cout << endl;
	for (int i = 0;i < 10;i++)
		cout << "\t��ί" <<setw(2)<< i + 1 << "�Ĵ��Ϊ��\t\t" << score[i] << endl;
	cout << endl;
	cout << "\t��ί�ܵ÷֣�" << totalScore << "\t��ίƽ���֣�" << setprecision(2) << averageScore << endl;
	cout << endl;
	cout << "\t�û�ͶƱ����\t" << setprecision(0) << votes << endl;
	cout << "\t�ۺϵ÷֣�\t" << setprecision(3) << finalScore << endl;
	cout << "\t����״̬��\t";
	if (isPromtoted)
		cout << "��" << endl;
	else
		cout << "��" << endl;
	return;
}

string singer::getNumber()const 
{
	return number;
}

string singer::getName()const
{
	return name;
}

double singer::getScore(int i)const
{
	if (i >= 1 && i <= 10)
		return score[i - 1];
	else
	{
		switch (i) {
		case 11:
			return maxScore;
		case 12:
			return minScore;
		case 13:
			return totalScore;
		case 14:
			return averageScore;
		case 15:
			return votes;
		case 16:
			return finalScore;
		}
	}
}

int singer::getVotes() const 
{
	return votes;
}

int singer::getPromoted() const
{
	return isPromtoted;
}

ofstream& operator <<(ofstream& OUT, const singer& s)//��������Ϣд���ļ������������
{
	OUT << s.number << ' ' << s.name << endl;
	for (int i = 0;i < 10;i++)
	{
		if (i)
			OUT << ' ';
		OUT << s.score[i];
	}
	OUT << endl << s.votes << ' ' << s.isPromtoted << endl;
	return OUT;
}

double& singer::operator[](int i)
{
	if (i >= 1 && i <= 10)
		return score[i - 1];
	else
	{
		switch (i) {
		case 11:
			return maxScore;
		case 12:
			return minScore;
		case 13:
			return totalScore;
		case 14:
			return averageScore;
		case 15:
			return votes;
		case 16:
			return finalScore;
		}
	}
}