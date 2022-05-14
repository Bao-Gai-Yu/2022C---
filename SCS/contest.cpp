#include"contest.h"
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

contest::contest(string cName="Nan", int cnt=0,int cFinished=0) :contestantList()
{
	prev = NULL;
	next = NULL;
	contestName = cName;
	contestantCount = cnt;
	isFinished = cFinished;
}

void contest::readContestantList(string cName)//����һ�������ĸ�������
{
	ifstream singerInput;
	singerInput.open("Data/SingerLists/"+cName + ".dat");		//������Ϣ�Ĵ洢�ļ���Ϊ  ������+".dat"
	for (int i = 0;i < contestantCount;i++)
	{
		singer* tmpSinger = new singer;
		string tmpNum, tmpName;
		singerInput >> tmpNum >> tmpName;	//������ֱ�ţ�����
		tmpSinger->setNumber(tmpNum);
		tmpSinger->setName(tmpName);
		for (int i = 0;i < 10;i++)			//������ί���
		{
			double tmpSco;
			singerInput >> tmpSco;
			tmpSinger->setScore(i, tmpSco);
		}
		int tmpVote;
		singerInput >> tmpVote;				//����ѡ�ֻ�õĹ���ͶƱ��
		tmpSinger->setVotes(tmpVote);

		tmpSinger->countScores();			//����ѡ�ֵ���߷֣���ͷ֣��ܷ֣�ƽ���֣��Լ��ۺϵ÷֡�
		
		int tmpPromoted;
		singerInput >> tmpPromoted;
		tmpSinger->setPromoted(tmpPromoted);
		contestantList.addNode	(*tmpSinger);
	}
	singerInput.close();
	return;
}

void contest::printContestantList()
{	
	contestantList.printList();
	return;
}

void contest::display()
{
	cout << setw(29) << contestName << setw(23) << "����״̬��";
	if (isFinished)
		cout << "�ѽ�����" << endl;
	else
		cout << "�����У�" << endl;
}

string contest::getContestName()
{
	return contestName;
}

void contest::setContestName(string newName)
{
	contestName = newName;
	return;
}

int contest::getContestantCount()
{
	return contestantCount;
}

int contest::getFinished()
{
	return isFinished;
}

void contest::setContestantCount(int newCount)
{
	contestantCount = newCount;
	return;
}

void contest::setFinished(int newF)
{
	isFinished = newF;
	return;
}

ofstream& operator <<(ofstream& OUT,contest& c)	//��������Ϣд���ļ������������
{
	OUT << c.contestName << ' ' << c.contestantCount << ' ' << c.isFinished;
	return OUT;
}