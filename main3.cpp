#include "HomeAutomation.h"
#include "Appliance.h"
#include "RiceCooker.h"
#include<iostream>
#include<string>
using namespace std;

int menu(char **menuList, int menuCnt); // ���޵� �޴��� ����ϰ� ��Ȯ�� �޴���ȣ�� �����ϴ� �Լ�
int controlMenuSelect(string message, int menuCnt); // ������ǰ�� ���º��� ó���� ���� �޴� �Լ�
void displayTitle(string title); // ó������ ���� ����ϱ� ���� Ÿ��Ʋ ����Լ� 
void screen(HomeAutomation &rHa); // �ָ޴��� ����ϰ� �޴��� ���ù޾� �ݺ������� �ָ޴��� ó���ϴ� �Լ�
void listDisplayAppliance(HomeAutomation &rHa); // ��ϵ� ������ǰ�� �������
void controlAppliance(HomeAutomation &rHa); // ��ϵ� ������ǰ �����ϱ�
void addAppliance(HomeAutomation &rHa); // ������ǰ ���
void deleteAppliance(HomeAutomation &rHa); // ������ǰ ����

int main()
{
	HomeAutomation homeAuto;
	screen(homeAuto);
	// �Ʒ� �ڵ�� ȭ�鿡 ����Ǵ� ��ȭ�� ������ ��������ڿ� ���Կ����� �Լ��� �׽�Ʈ �ϱ� ���� �ڵ��Դϴ�. 
	HomeAutomation temp1=homeAuto;  // ���� ������ �׽�Ʈ �ڵ�
	HomeAutomation temp2;
	temp2 = temp1;  // ���Կ����� �Լ� �׽�Ʈ �ڵ� 
	return 0;
}

void screen(HomeAutomation &rHa)
{
	char *menuList[]={"��� ����Ȯ�� ", "��� ���� ", "��� ��� ", "��� ���� ", "���� "};
	int menuCnt = sizeof(menuList)/sizeof(menuList[0]);
	int menuNum;

	displayTitle("Ȩ ��� �ɾ�ý��� ����");
	while(true)
	{
		menuNum = menu(menuList, menuCnt);
		if(menuNum==menuCnt) {break;}
		switch(menuNum)
		{
		case 1 : listDisplayAppliance(rHa); break;
		case 2 : controlAppliance(rHa); break;
		case 3 : addAppliance(rHa); break;
		case 4 : deleteAppliance(rHa); break;
		}
	}
	displayTitle("Ȩ ��� �ɾ�ý��� ����");
	return;
}

void listDisplayAppliance(HomeAutomation &rHa) // ��ϵ� ������ǰ�� �������
{
	displayTitle("��� ���� ����");
	rHa.listDisplayAppliance();
	displayTitle("��� ���� ���� ����");
}

void controlAppliance(HomeAutomation &rHa) // ��ϵ� ������ǰ �����ϱ�
{
	string input = "";
	cout << "* ������ ��ǰ�� �Է� : "; cin >> input;
	displayTitle("��� ���� �ϱ�");
	rHa.controlAppliance(input);
	
}

void addAppliance(HomeAutomation &rHa) // ������ǰ�� ��Ͽ� �߰�. ������ ��ǰ���� ����� ��� �Ұ�
{
	displayTitle("��� ��� �ϱ�");
	string input = "";
	cout << "* ��ǰ�� �Է�( ��)ū���, 1ȣ��� ��) : "; cin >> input;
	RiceCooker* newCooker = new RiceCooker;
	newCooker->setMachineName(input);
	rHa.addAppliance(newCooker);
}

void deleteAppliance(HomeAutomation &rHa) // ��� ����
{
	displayTitle("��� ���� �ϱ�");
	string input = "";
	cout << "* ��ǰ�� �Է�( ��)ū���, 1ȣ��� ��) : "; cin >> input;
	rHa.deleteAppliance(input);
}

int controlMenuSelect(string message, int menuCnt)
{
	int menuNum;

	while(true)
	{
		cout << message;
		cin >> menuNum;
		if(menuNum>0 && menuNum <= menuCnt){ break; }
	}
	return menuNum;
}

int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum=0; /* �Էµ� �޴� ��ȣ ���� ����*/

	cout << endl << "==================================" << endl;
	for(i=0; i<menuCnt; i++)
	{
		cout << i+1 << "." << menuList[i] << endl;
	}
	cout << "==================================" << endl;
	while(menuNum<1 || menuNum>menuCnt)  /* ���� ���� ��ȣ�� �Էµ� �� ���� �ݺ�*/
	{
		cout <<"# �޴���ȣ�� �Է��ϼ��� : ";
		cin >> menuNum;
	}
	return menuNum;
} 

void displayTitle(string title) // ȭ�� Ÿ��Ʋ ��� �Լ�
{
	cout << endl << "------------------------------" << endl;
	cout << "    " << title << endl;
	cout << "------------------------------" <<endl;
}
