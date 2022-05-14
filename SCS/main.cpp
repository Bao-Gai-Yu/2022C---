#include<iostream>
#include<cstdlib>
#include<fstream>
#include"myList.h"
#include"user_class.h"
#include"contest.h"
#include"singer.h"
using namespace std;

void readData(int&, myList<contest>&);
void writeData(int&, myList<contest>&);

int main()
{
	myList<contest> contestList;//�����洢��ͬ���εı���������
	int contestCount;//�洢����������
	readData(contestCount, contestList);//�ļ���������

	cout << "################################################" << endl;
	cout << "#                                              #" << endl;
	cout << "#   ��ӭʹ�ø��ֱ�������ϵͳ                   #" << endl;
	cout << "#                                              #" << endl;
	cout << "#   ��ѡ���û����                           #" << endl;
	cout << "#       1 - ��ͨ�û�                           #" << endl;
	cout << "#       2 - ����Ա                             #" << endl;
	cout << "#                                              #" << endl;
	cout << "################################################" << endl;
	char choice;
	cin >> choice;
	while (choice != '1' && choice != '2')
	{
		cout << "����������������룺";
		cin >> choice;
	}
	if (choice == '1')		//��ͨ�û��Ĳ���
	{
		string uid;
		cout << "���������ID��";
		cin >> uid;
		user currentUser(uid, contestCount);
		system("cls");
		cout << "��ӭ�����װ��� " << uid << " !" << endl;
		if (contestCount == 0)
		{
			cout << "��ǰû�б���Ŷ~" << endl;
			system("pause");
		}
		else
		{
			cout << "��ǰ����"<<contestCount<<"������" << endl;
			while (1)
			{

				contestList.printList();
				cout << "###########################################################" << endl;
				cout << "��������Ҫ�鿴�ĳ���ǰ�����֣�1-" << contestCount << ")" << endl;
				cout << "����0��ʾ�˳�ϵͳ\n\t(ע�⣡�������˳�ϵͳ�Ļ��������κβ������ᱻ��¼��)"<<endl;
				cout << "����ѡ���ǣ�";
				int contestChoice;
				cin >> contestChoice;
				while ((contestChoice<0 || contestChoice > contestCount ))
				{
					cout << "����������������룺";
					cin >> contestChoice;
				}
				if (contestChoice == 0)
				{
					system("cls");
					break;
				}
				else
				{
					system("cls");
					while (1)
					{
						contest* currentContest = contestList.getNode(contestChoice);
						myList<singer>* currentSingerList = &(currentContest->contestantList);
						int singerNum = currentContest->getContestantCount();
						cout <<endl<< "��ǰ���ڲ鿴�ı���Ϊ��" << currentContest->getContestName() << endl;
						cout << "###########################" << endl;
						cout << "#                         #" << endl;
						cout << "#  ������                 #" << endl;
						cout << "#     1.�鿴ѡ����Ϣ      #" << endl;
						cout << "#     2.Ϊѡ��ͶƱ        #" << endl;
						cout << "#     3.���ر���ѡ��      #" << endl;
						cout << "#                         #" << endl;
						cout << "###########################" << endl;
						char inContestChoice;
						cout << "��Ҫ���еĲ����ǣ�";
						cin >> inContestChoice;
						while (inContestChoice < '1' || inContestChoice > '3')
						{
							cout << "�����������������룺";
							cin >> inContestChoice;
						}
						if (inContestChoice == '1')//ѡ��鿴ѡ����Ϣ
						{
							system("cls");
							currentSingerList->printList();//��������б�
							while (1)
							{
								cout << "#############################" << endl;
								cout << "#                           #" << endl;
								cout << "#  ������                   #" << endl;
								cout << "#     1.����鿴            #" << endl;
								cout << "#     2.��������            #" << endl;
								cout << "#     3.������һ��          #" << endl;
								cout << "#                           #" << endl;
								cout << "#############################" << endl;
								char singerListChoice;
								cout << "����������ѡ��";
								cin >> singerListChoice;
								while (singerListChoice < '1' || singerListChoice > '3')
								{
									cout << "����������������룺";
									cin >> singerListChoice;
								}
								if (singerListChoice == '1')
								{
									currentUser.showSingers(currentContest);//������������б�
								}
								else if(singerListChoice=='2')
								{
									currentUser.search(currentContest);//��������
								}
								else if (singerListChoice == '3')
								{
									system("cls");
									break;
								}
							}
						}
						else if (inContestChoice == '2')//Ϊѡ��ͶƱ
						{
							system("cls");
							for (int i = 1;i <= singerNum;i++)
							{
								singer* tmp = currentSingerList->getNode(i);
								cout << "->" << i << endl;
								cout << "\t��ţ�" <<tmp->getNumber()<< "\t������" <<tmp->getName()<< endl;
								cout << "\t\t��ǰ��Ʊ����" << tmp->getVotes() << endl;
								cout << endl;
							}
							int voteChoose;
							cout << "����������ҪͶƱ��ѡ��ǰ����ţ���ѡ�ֱ�ţ���:";
							cin >> voteChoose;
							while (voteChoose<1 || voteChoose>singerNum)
							{
								cout << "����������������룺";
								cin >> voteChoose;
							}
							currentUser.voteSinger(contestChoice, currentSingerList->getNode(voteChoose));
						}
						else if (inContestChoice == '3')//������һ��
						{
							system("cls");
							break;
						}
					}
				}
		}
		

		}
	}
	else if (choice == '2')//����Ա
	{
		system("cls");
		const string adminPassword = "123456";
		cout << "����������:";
		string pwd;
		cin >> pwd;
		while (pwd != adminPassword)
		{
			system("cls");
			cout << "����������������룺";
			cin >> pwd;
		}
		admin op;
		system("cls");
		cout << "��ӭ�����Ļ������Ա��"<<endl;
		while (1)
		{
			if (contestCount == 0)
			{
				cout << "��ǰû�б���Ŷ~"<<endl;
			}
			else
			{
				contestList.printList();
			}
			cout << "###########################################################" << endl;
			cout << "->" << contestCount + 1 << endl;
			cout << "\t\t����/�޸�/ɾ������"<<endl;
			cout << endl;
			cout << "###########################################################" << endl;
			cout << "��������Ҫ���в����ĳ���ǰ�����֣�1-" << contestCount+1 << ")" << endl;
			cout << "����0��ʾ�˳�ϵͳ\n\t(ע�⣡�������˳�ϵͳ�Ļ��������κβ������ᱻ��¼��)" << endl;
			cout << "����ѡ���ǣ�";
			int opContestChoice;
			cin >> opContestChoice;
			while (opContestChoice < 0 || opContestChoice>contestCount + 1)
			{
				cout << "����������������룺";
				cin >> opContestChoice;
			}
			system("cls");
			if (opContestChoice == 0)
			{
				system("cls");
				break;
			}
			else if (opContestChoice >= 1 && opContestChoice <= contestCount)//��ĳ���������в���
			{
				while (1)
				{
					contest* currentContest = contestList.getNode(opContestChoice);
					cout << "��ǰѡ�еı���Ϊ�� " << currentContest->getContestName() << endl;
					cout << "#############################" << endl;
					cout << "#                           #" << endl;
					cout << "#  ������                   #" << endl;
					cout << "#     1.����鿴            #" << endl;
					cout << "#     2.��������            #" << endl;
					cout << "#     3.��������            #" << endl;
					cout << "#     4.�޸ĸ�������        #" << endl;
					cout << "#     5.ɾ������            #" << endl;
					cout << "#     6.������һ��          #" << endl;
					cout << "#                           #" << endl;
					cout << "#############################" << endl;
					int oop;
					cout << "���������Ĳ�����";
					cin >> oop;
					while (oop < 1 || oop > 6)
					{
						cout << "����������������룺";
						cin >> oop;
					}
					if (oop == 1)//����鿴
					{
						op.showSingers(currentContest);
					}
					else if (oop == 2)//����
					{
						op.search(currentContest);
					}
					else if (oop == 3)//׷�Ӹ�������
					{
						op.addSingerData(currentContest);
					}
					else if (oop == 4)//�޸ĸ�������
					{
						op.modifySingerData(currentContest);
					}
					else if (oop == 5)//ɾ������
					{
						op.deleteSingerData(currentContest);
					}
					else if (oop == 6)//������һ��
					{
						system("cls");
						break;
					}
				}

			}
			else if (opContestChoice == contestCount + 1)//��ɾ����
			{
				while (1)
				{
					cout << "#############################" << endl;
					cout << "#                           #" << endl;
					cout << "#  ������                   #" << endl;
					cout << "#     1.���ӱ���            #" << endl;
					cout << "#     2.�޸ı���            #" << endl;
					cout << "#     3.ɾ������            #" << endl;
					cout << "#     4.������һ��          #" << endl;
					cout << "#                           #" << endl;
					cout << "#############################" << endl;
					cout << "����ѡ���ǣ�";
					int opSelect;
					cin >> opSelect;
					while (opSelect < 1 || opSelect>4)
					{
						cout << "����������������룺";
						cin >> opSelect;
					}
					if (opSelect == 1)
					{
						op.addContest(contestList,contestCount);
					}
					else if (opSelect == 2)
					{
						op.modifyContestData(contestList, contestCount);
					}
					else if (opSelect == 3)
					{
						op.deleteContest(contestList, contestCount);
					}
					else if(opSelect == 4)
					{
						system("cls");
						break;
					}
				}
			}
		}
	}

	system("cls");
	cout << "#####################################" << endl;
	cout << "#                                   #" << endl;
	cout << "#\t���˳����ڴ��´��ټ�~       #" << endl;
	cout << "#                                   #" << endl;
	cout << "#####################################" << endl;

	writeData(contestCount, contestList);//����д���ļ�
	system("pause");
	return 0;
}

void readData(int& contestCount,myList<contest>& contestList)
{
	ifstream Input;
	Input.open("Data/contestData.dat");
	Input >> contestCount;
	for (int i = 0;i < contestCount;i++)
	{
		string cName;
		int singerCnt;
		Input >> cName >> singerCnt;		//����ÿ����������Ϣ���������ƣ�����������
		contest* contestObj = new contest(cName, singerCnt);
		contestObj->readContestantList(cName);		//����ó��εĲ���ѡ����Ϣ
		contestList.addNode(*contestObj);
	}
	Input.close();
	return;
}

void writeData(int& contestCount, myList<contest>& contestList)
{
	ofstream Output;					//������д���ļ�����
	Output.open("Data/contestData.dat");
	Output << contestCount << endl;
	for (int i = 1;i <= contestCount;i++)
	{
		contest* pc = contestList.getNode(i);
		Output << (*pc) << endl;
		ofstream singerOutput;
		singerOutput.open("Data/SingerLists/"+pc->getContestName() + ".dat");
		for (int j = 1;j <= pc->getContestantCount();j++)
		{
			singer* ps = (pc->contestantList).getNode(j);
			singerOutput << (*ps);
		}
		singerOutput.close();
	}
	Output.close();
	return;
}
