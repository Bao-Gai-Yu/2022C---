#include<cstdlib>
#include"user_class.h"
#include"contest.h"
#include"singer.h"

basic::basic(){}

void mySort(myList<singer>& sL, int singerCnt, int sortChoice, int isGreater)
{
	for (int i = 1;i < singerCnt;++i)
	{
		int k = i;
		for (int j = i + 1;j <= singerCnt;++j)
		{
			bool flag = false;
			if (isGreater)
			{
				if ((*sL.getNode(k))[sortChoice] > (*sL.getNode(j))[sortChoice])
				{
					flag = true;
				}
			}
			else
			{
				if ((*sL.getNode(k))[sortChoice] < (*sL.getNode(j))[sortChoice])
				{
					flag = true;
				}
			}
			if (flag)
				k = j;
		}
		if (k != i)
		{
			sL.swapNodes(i, k);
		}
	}
}

void basic::showSingers(contest* c)//ѡ������ʽ�������һ�����������ĸ����б�
{
	system("cls");
	cout << "��ѡ����������ݣ�" << endl;
	cout << " 1����ί1���\t 2����ί2���\t 3����ί3���\t 4����ί4���\t 5����ί5���" << endl;
	cout << " 6����ί6���\t 7����ί7���\t 8����ί8���\t 9����ί9���\t10����ί10���" << endl;
	cout << "11����ί��߷�\t12����ί��ͷ�\t13���ܵ÷�\t14��ƽ���÷�\t15������ͶƱ��" << endl;
	cout << "16���ۺϵ÷�" << endl;
	int sortChoice,isGreater;
	cout << "����������ѡ��";
	cin >> sortChoice;
	while (sortChoice < 1 || sortChoice>16)
	{
		cout << "����������������룺";
		cin >> sortChoice;
	}
	cout << "��ѡ������(1)�ͽ���(0):";
	cin >> isGreater;
	while (isGreater != 1 && isGreater != 0)
	{
		cout << "�����������������";
		cin >> isGreater;
	}
	myList<singer>& sL = c->contestantList;
	int singerCnt = c->getContestantCount();
	mySort(sL, singerCnt, sortChoice, isGreater);
	system("cls");
	sL.printList();
	cout << "��������ɣ�������Ϸ�" << endl;
	return;
}

void basic::search(contest* c)//���ҹ��ܡ���һ�������в���ĳ������
{
	system("cls");
	cout << "��������ֵ����ֽ���������֧��ģ����������" << endl;
	string key;
	cin >> key;
	int singerCnt = c->getContestantCount();
	int idx = 0;
	for (int t = 1;t <= singerCnt;t++)
	{
		singer* cSinger = c->contestantList.getNode(t);
		string name = cSinger->getName();
		if (name.find(key)!=string::npos)
		{
			idx++;
			cout << "###########################################################" << endl;
			cout << "��� " << idx << " :" << endl;
			cSinger->display();
		}
	}
	if (idx)
	{
		cout << "��������ɣ�����" << idx << "�������" << endl;
	}
	else
	{
		cout << "û�в�ѯ���κν����" << endl;
	}
	cout << endl;
	return;
}

user::user(string uid,int contestCount)//��ͨ�û��ĳ�ʼ��
{
	id = uid;
	voted = new bool[contestCount + 1];
	for (int i = 0;i <= contestCount;i++)
		voted[i] = false;
}

user::~user()
{
	delete[] voted;
}

void user::voteSinger(int contestIndex,singer* vSinger)
{
	system("cls");
	if (voted[contestIndex])
	{
		cout << "�ó���������ͶƱ,���������ٽ���ͶƱ��" << endl;
		return;
	}
	else
	{
		cout << "����Ϊѡ�еĸ���Ͷ��һƱ!" << endl;
		cout << "һ��Ҫ�����˳���ͶƱ�Żᱣ��Ŷ~" << endl<<endl;
		voted[contestIndex] = true;
		vSinger->setVotes(vSinger->getVotes() + 1);
		vSinger->countScores();
	}
	return;
}

void checkPromoted(myList<singer>& sL,int size)
{
	mySort(sL, size, 16, 0);//�����ۺϳɼ�(16)����(0)����
	for (int i = 1;i <= size / 2;i++)
	{
		sL.getNode(i)->setPromoted(1);
	}
	for (int i = size / 2 + 1;i <= size;i++)
	{
		sL.getNode(i)->setPromoted(0);
	}
	return;
}

void admin::addContest(myList<contest>&c, int& contestCount)
{
	/*cout << "�������±��������ƣ�";
	string newName;
	cin >> newName;
	cout << "�������±����Ĳ���������";
	int newCount;
	cin >> newCount;
	for (int i = 1;i <= contestCount;i++)
	{
		string tmpName = c.getNode(i)->getContestName();
		if (newName == tmpName)
		{
			cout << "�Ѵ���ͬ�����������ʧ�ܣ�" << endl;
			return;
		}
	}
	contest* newC = new contest(newName,newCount,0);
	for (int i = 0;i < newCount;i++)
	{
		singer* tmp = new singer;
		newC->contestantList.addNode(*tmp);
	}
	c.addNode(*newC);
	contestCount++;*/
	system("cls");
	c.printList();
	cout << "��ѡ��һ�������еı���������һ�׶Σ�";
	int selectKey;
	cin >> selectKey;
	while (selectKey < 1 || selectKey > contestCount)
	{
		cout << "����������������룺";
		cin >> selectKey;
	}
	contest* targetC = c.getNode(selectKey);
	int isF = targetC->getFinished();
	system("cls");
	if (isF)
	{
		cout << "��ǰ�����ѽ������޷�������һ�׶Ρ�" << endl;
		cout << "��������ʧ�ܡ�" << endl;
	}
	else
	{
		targetC->setFinished(1);
		string newName;
		cout << "�������±��������ƣ�";
		cin >> newName;
		while (1)
		{
			bool flag = true;
			for (int i = 1;i <= contestCount;i++)
			{
				string tmpName = c.getNode(i)->getContestName();
				if (i != selectKey && newName == tmpName)
				{
					cout << "�Ѵ���ͬ�����������������룺" << endl;
					flag = false;
				}
			}
			if (flag) {break;}
		}
		int newCount = targetC->getContestantCount() / 2;
		contest* newC = new contest(newName, newCount, 0);
		myList<singer>& sL=targetC->contestantList;
		checkPromoted(sL, targetC->getContestantCount());
		for (int i = 1;i <= targetC->getContestantCount();i++)
		{
			singer* tmp = targetC->contestantList.getNode(i);
			if (tmp->getPromoted())
			{
				singer* newTmp = new singer;
				newTmp->setNumber(tmp->getNumber());
				newTmp->setName(tmp->getName());
				newC->contestantList.addNode(*newTmp);
			}

		}
		c.addNode(*newC);
		contestCount++;
	}
	cout << "�����ɹ�!"<<endl;
	return;
}

void admin::modifyContestData(myList<contest>& c, int& contestCount)
{
	system("cls");
	if (contestCount == 0)
	{
		cout << "��ǰû�б�����" << endl;
		return;
	}
	c.printList();
	cout << "��ѡ����Ҫ�޸ĵı�����";
	int modifyKey;
	cin >> modifyKey;
	while (modifyKey < 1 || modifyKey > contestCount)
	{
		cout << "����������������룺";
		cin >> modifyKey;
	}
	contest* targetC = c.getNode(modifyKey);
	string nowName = targetC->getContestName();
	string newName;
	cout << "����ԭ����Ϊ[ " << nowName << " ]����������Ҫ�޸ĳɵ����ƣ�";
	cin >> newName;
	for (int i = 1;i <= contestCount;i++)
	{
		string tmpName = c.getNode(i)->getContestName();
		if (i != modifyKey && newName == tmpName)
		{
			cout << "�Ѵ���ͬ���������޷��޸ģ�"<<endl;
			return;
		}
	}
	targetC->setContestName(newName);
	system("cls");
	cout << "����������޸ģ�" << endl;
	return;
}

void admin::deleteContest(myList<contest>& c, int& contestCount)
{
	system("cls");
	if (contestCount == 0)
	{
		cout << "��ǰû�б�����" << endl;
		return;
	}
	c.printList();
	cout << "��ѡ����Ҫɾ���ı�����";
	int deleteKey;
	cin >> deleteKey;
	while (deleteKey<1 || deleteKey>contestCount)
	{
		cout << "����������������룺";
		cin >> deleteKey;
	}
	system("cls");
	string deleteName = c.getNode(deleteKey)->getContestName();
	cout << "��ȷ��Ҫɾ��[ " << deleteName << " ]��(y/n)�� ";
	char confirm;
	cin >> confirm;
	if (confirm == 'y')
	{
		c.deleteNode(deleteKey);
		contestCount--;
		cout << "����[ " << deleteName << " ]�ѱ�ɾ����" << endl;
	}
	else
	{
		cout << "ȡ��������û���κα�����ɾ����" << endl;
	}

	return;
}

void admin::addSingerData(contest* c)
{
	singer* tmp=new singer;
	myList<singer>& sL = c->contestantList;
	string newNum, newName;
	cout << "�������������ֵı�ţ�";
	cin >> newNum;
	tmp->setNumber(newNum);
	cout << "�������������ֵ�������";
	cin >> newName;
	tmp->setName(newName);
	for (int i = 0;i < 10;i++)
	{
		double s;
		cout << "�������" << i + 1 << "����ί��֣�";
		cin >> s;
		tmp->setScore(i, s);
	}
	int newVote;
	cout << "�������������ֵĹ���ͶƱ����";
	cin >> newVote;
	tmp->setVotes(newVote);
	
	tmp->countScores();
	c->setContestantCount( c->getContestantCount() + 1 );
	sL.addNode(*tmp);
	system("cls");
	cout << "��������������ɣ�" << endl<<endl;
	return;
}

void admin::modifySingerData(contest* c)
{
	system("cls");
	int singerCnt = c->getContestantCount();
	myList<singer>& sL = c->contestantList;
	for (int i = 1;i <= singerCnt;i++)
	{
		singer* tmp = sL.getNode(i);
		cout << "->" << i << endl;
		cout << "\t��ţ�" << tmp->getNumber() << "\t����:" << tmp->getName() << endl;
	}
	cout << "->0" << endl << "\t�˳��޸Ĳ���" << endl;
	cout << "�����������޸ĵ�ѡ��ǰ����ţ���ѡ�ֱ�ţ���";
	int modifyKey;
	cin >> modifyKey;
	while (modifyKey<0 || modifyKey>singerCnt)
	{
		cout << "����������������룺";
		cin >> modifyKey;
	}
	system("cls");
	if (modifyKey == 0)
	{
		cout << "û���κθ������ݱ��޸ģ�" << endl;
	}
	else
	{
		singer& mS = *sL.getNode(modifyKey);
		char c;
		cout << "������Ҫ�޸ĸ��ֱ����������(����y��ʾȷ��):";
		cin >> c;
		if (c == 'y')
		{
			cout << "����ԭ���Ϊ��[ " << mS.getNumber()<<" ]  �����޸�Ϊ��";
			string newNum;
			cin >> newNum;
			mS.setNumber(newNum);
			cout << "����ԭ����Ϊ��[ " << mS.getName() << " ]  �����޸�Ϊ��";
			string newName;
			cin >> newName;
			mS.setName(newName);
		}
		cout << "������Ҫ�޸���ί�����(����y��ʾȷ��):";
		cin >> c;
		if (c == 'y')
		{
			for (int i = 1;i <= 10;i++)
			{
				cout << "��ί" << i << "��ԭ���Ϊ��[ " << mS.getScore(i) << " ]  �����޸�Ϊ��";
				double newS;
				cin >> newS;
				mS.setScore(i-1, newS);
			}
		}
		cout << "������Ҫ�޸Ĺ���ͶƱ����(����y��ʾȷ��):";
		cin >> c;
		if (c == 'y')
		{
			cout << "���ֵ�ԭ����ͶƱ��Ϊ��[ " << mS.getVotes() << " ]  �����޸�Ϊ��";
			int newVote;
			cin >> newVote;
			mS.setVotes(newVote);
		}
		mS.countScores();
		system("cls");
		cout << "������Ϣ���޸ĳɹ���" << endl;
	}
	return;
}

void admin::deleteSingerData(contest* c)
{
	system("cls");
	int singerCnt = c->getContestantCount();
	if (singerCnt == 0)
	{
		cout << "���޸������ݣ��޷�ɾ����" << endl;
		return;
	}
	myList<singer>& sL = c->contestantList;
	for (int i = 1;i <= singerCnt;i++)
	{
		singer* tmp=sL.getNode(i);
		cout << "->" << i << endl;
		cout << "\t��ţ�" << tmp->getNumber() << "\t����:" << tmp->getName() << endl;
	}
	cout << "->0" << endl << "\t�˳�ɾ������" << endl;
	cout << "����������ɾ����ѡ��ǰ����ţ���ѡ�ֱ�ţ���";
	int deleteKey;
	cin >> deleteKey;
	while (deleteKey<0 || deleteKey>singerCnt)
	{
		cout << "����������������룺";
		cin >> deleteKey;
	}
	system("cls");
	if (deleteKey == 0)
	{
		cout << "û���κθ������ݱ�ɾ����" << endl;
	}
	else
	{
		sL.deleteNode(deleteKey);
		c->setContestantCount(c->getContestantCount() - 1);
		cout << "�ѳɹ�ɾ���������ݣ�"<<endl;
	}
	return;
}
