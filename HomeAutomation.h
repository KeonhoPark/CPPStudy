#ifndef __HOMEAUTOMATION_H__
#define	__HOMEAUTOMATION_H__
#include "Appliance.h"
#include "RiceCooker.h"
#include<string>
using namespace std;

#define APPLIANCE_MAX_CNT 5 // �ִ� ��� ������ ������ǰ�� ����

class HomeAutomation
{
public : 
	HomeAutomation(); // riceCookerArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, riceCookerCnt�� 0���� �ʱ�ȭ
	HomeAutomation(const HomeAutomation &r); // deep copy constructor
	~HomeAutomation(); // riceCookerArray�� ���� �Ҵ�� ��ü�� ��� ������

	// getter, setter member function
	RiceCooker ** getRiceCookerArray(); // riceCookerArray ��� �� ��ȯ �Լ�
	int getRiceCookerCnt() const ; // riceCookerCnt ��� �� ��ȯ �Լ�
	
	// member function
	HomeAutomation & operator=(const HomeAutomation &r); // ����(�Ҵ�)������ �����ε� �Լ�
	bool addAppliance(RiceCooker *ap);	// ������ǰ�� ��Ͽ� �߰�. ������ ��ǰ���� ����� ��� �Ұ�
	int searchMachine(string machineName); // ������ǰ�� �ش��ϴ� ������ǰ�� ã�Ƽ� �迭�� index����/���� �� -1 ����
	bool deleteAppliance(string machineName); // ������ǰ�� �ش��ϴ� ������ǰ�� ��Ͽ��� �����ϴ�
	void listDisplayAppliance(); // ��ϵ� ������ǰ ��ü ��� �� ���¸�  Ȯ���ϴ�
	bool controlAppliance(string machineName);   // �ش� ������ǰ�� �����ϴ�
	void setStateAppliance(RiceCooker * ap); // �����ִ� ������ǰ�� ���¸� �����ϴ�
private : 
	RiceCooker* riceCookerArray[APPLIANCE_MAX_CNT]; // ��ϵ� ��� ��ü�� ���� ���� �迭(������ü �Ҵ� �� �ּ�����)
	int riceCookerCnt; // ��ϵ� ��� ��ü�� ���� ����
};
#endif

HomeAutomation::HomeAutomation(){
    for(int i = 0; i < APPLIANCE_MAX_CNT; i++){
		riceCookerArray[i] = nullptr;
	}
    riceCookerCnt = 0;
}

HomeAutomation::HomeAutomation(const HomeAutomation &r){
    riceCookerArray = r.getRiceCookerArray();
    riceCookerCnt = r.getRiceCookerCnt();
}

HomeAutomation::~HomeAutomation(){
    delete riceCookerArray;
}

RiceCooker** HomeAutomation::getRiceCookerArray(){
    return riceCookerArray;
}

int HomeAutomation::getRiceCookerCnt() const{
    return riceCookerCnt;
}

HomeAutomation& HomeAutomation::operator=(const HomeAutomation &r){
    HomeAutomation temp(r);
    return temp;
}

int HomeAutomation::searchMachine(string machineName){
    for(int i = 0; i < APPLIANCE_MAX_CNT; i++){
        if(riceCookerArray[i]->getMachineName() == machineName){
            return i;
        }
    }
    return -1;
}

bool HomeAutomation::addAppliance(RiceCooker *ap){
    if(riceCookerCnt == APPLIANCE_MAX_CNT){
        cout << "** ���̻� ����� �߰��� �� �����ϴ�." << endl;
    } return false;
    if(searchMachine(ap->getMachineName()) != -1){
        cout << "** �̹� �����̸��� ����� �����մϴ�." << endl;
        return false;
    }

    riceCookerArray[riceCookerCnt] = ap;
    riceCookerCnt++;
    cout << "��ܸ� : " << ap->getMachineName() << "�� ����� �Ϸ�Ǿ����ϴ�." << endl;
    return true;
}

bool HomeAutomation::deleteAppliance(string name){
    int index = searchMachine(name);
    if(index == -1){
        cout << "��ܸ� : " << name << "�� ������ �����Ͽ����ϴ�." << endl;
        cout << "**" << name << "����� �������� �ʽ��ϴ�." << endl;
    } return false;
    for(int i = index; i < riceCookerCnt - 1; i++){
        riceCookerArray[i] = riceCookerArray[i+1];
    }
    riceCookerArray[riceCookerCnt - 1] = nullptr;
    cout << "��ܸ� : " << name << "�� ������ �Ϸ�Ǿ����ϴ�." << endl;
    return true;
}

void HomeAutomation::listDisplayAppliance(){
    for(int i = 0; i < riceCookerCnt; i++){
        riceCookerArray[i]->stateView();
    }
}

void HomeAutomation::setStateAppliance(RiceCooker* ap){
    int state = 0;
    cout << "1.������ / 2.���� / 3.������ / 4.����� / 5.���� : "; cin >> state;
    cout << endl;
    ap->setMachineState(state);
    ap->stateView();
    cout << "��ܸ� : " << ap->getMachineName() << "�� ��� �Ϸ�Ǿ����ϴ�." << endl;
}

bool HomeAutomation::controlAppliance(string name){
    int index = searchMachine(name);
    if(index == -1){
        cout << "** �ش��ϴ� ��ǰ�� �������� �ʽ��ϴ�." << endl;
        return false;
    }
    if(riceCookerArray[index]->getPowerFlag() == true){
        setStateAppliance(riceCookerArray[index]);
        return true;
    } 
    else{
        char answer;
        cout << "������ �ѽðڽ��ϱ�?(Y/N) : "; cin >> answer;
        if(answer == 'n' || answer == 'N'){
            return false;
        }
        else if(answer == 'y' || answer == 'Y'){
            riceCookerArray[index]->turnOn();
            setStateAppliance(riceCookerArray[index]);
            return true;
        }
        else{
            cout << "**�߸� �Է��ϼ̽��ϴ�." << endl;
            return false;
        }
    }
}
