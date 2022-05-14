#include"contest.h"
#include<iostream>
#include<fstream>
using namespace std;

contest::contest(string cName="Nan", int cnt=0) :contestantList()
{
	prev = NULL;
	next = NULL;
	contestName = cName;
	contestantCount = cnt;
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
		tmpSinger->countScores();			//����ѡ�ֵ���߷֣���ͷ֣��ܷ֣�ƽ���֡�
		int tmpVote;
		singerInput >> tmpVote;				//����ѡ�ֻ�õĹ���ͶƱ��
		tmpSinger->setVotes(tmpVote);
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
	cout << "\t" << contestName << "\t\t\t����������" << contestantCount << endl;
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

void contest::setContestantCount(int newCount)
{
	contestantCount = newCount;
	return;
}

ofstream& operator <<(ofstream& OUT,contest& c)	//��������Ϣд���ļ������������
{
	OUT << c.contestName << " " << c.contestantCount;
	return OUT;
}