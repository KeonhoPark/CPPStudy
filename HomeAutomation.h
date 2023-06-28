#ifndef __HOMEAUTOMATION_H__
#define	__HOMEAUTOMATION_H__
#include "Appliance.h"
#include "RiceCooker.h"
#include<string>
using namespace std;

#define APPLIANCE_MAX_CNT 5 // 최대 등록 가능한 가전제품의 개수

class HomeAutomation
{
public : 
	HomeAutomation(); // riceCookerArray의 메모리 영역을 모두 0으로 초기화 하고, riceCookerCnt를 0으로 초기화
	HomeAutomation(const HomeAutomation &r); // deep copy constructor
	~HomeAutomation(); // riceCookerArray에 동적 할당된 객체를 모두 해제함

	// getter, setter member function
	RiceCooker ** getRiceCookerArray(); // riceCookerArray 멤버 값 반환 함수
	int getRiceCookerCnt() const ; // riceCookerCnt 멤버 값 반환 함수
	
	// member function
	HomeAutomation & operator=(const HomeAutomation &r); // 대입(할당)연산자 오버로딩 함수
	bool addAppliance(RiceCooker *ap);	// 가전제품을 목록에 추가. 동일한 제품명의 밥솥은 등록 불가
	int searchMachine(string machineName); // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
	bool deleteAppliance(string machineName); // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
	void listDisplayAppliance(); // 등록된 가전제품 전체 목록 및 상태를  확인하다
	bool controlAppliance(string machineName);   // 해당 가전제품을 제어하다
	void setStateAppliance(RiceCooker * ap); // 켜져있는 가전제품의 상태를 변경하다
private : 
	RiceCooker* riceCookerArray[APPLIANCE_MAX_CNT]; // 등록된 밥솥 객체의 정보 저장 배열(동적객체 할당 후 주소저장)
	int riceCookerCnt; // 등록된 밥솥 객체의 개수 저장
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
        cout << "** 더이상 밥솥을 추가할 수 없습니다." << endl;
    } return false;
    if(searchMachine(ap->getMachineName()) != -1){
        cout << "** 이미 같은이름의 밥솥이 존재합니다." << endl;
        return false;
    }

    riceCookerArray[riceCookerCnt] = ap;
    riceCookerCnt++;
    cout << "밥솥명 : " << ap->getMachineName() << "의 등록이 완료되었습니다." << endl;
    return true;
}

bool HomeAutomation::deleteAppliance(string name){
    int index = searchMachine(name);
    if(index == -1){
        cout << "밥솥명 : " << name << "의 삭제가 실패하였습니다." << endl;
        cout << "**" << name << "밥솥이 존재하지 않습니다." << endl;
    } return false;
    for(int i = index; i < riceCookerCnt - 1; i++){
        riceCookerArray[i] = riceCookerArray[i+1];
    }
    riceCookerArray[riceCookerCnt - 1] = nullptr;
    cout << "밥솥명 : " << name << "의 삭제가 완료되었습니다." << endl;
    return true;
}

void HomeAutomation::listDisplayAppliance(){
    for(int i = 0; i < riceCookerCnt; i++){
        riceCookerArray[i]->stateView();
    }
}

void HomeAutomation::setStateAppliance(RiceCooker* ap){
    int state = 0;
    cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : "; cin >> state;
    cout << endl;
    ap->setMachineState(state);
    ap->stateView();
    cout << "밥솥명 : " << ap->getMachineName() << "의 제어가 완료되었습니다." << endl;
}

bool HomeAutomation::controlAppliance(string name){
    int index = searchMachine(name);
    if(index == -1){
        cout << "** 해당하는 제품이 존재하지 않습니다." << endl;
        return false;
    }
    if(riceCookerArray[index]->getPowerFlag() == true){
        setStateAppliance(riceCookerArray[index]);
        return true;
    } 
    else{
        char answer;
        cout << "전원을 켜시겠습니까?(Y/N) : "; cin >> answer;
        if(answer == 'n' || answer == 'N'){
            return false;
        }
        else if(answer == 'y' || answer == 'Y'){
            riceCookerArray[index]->turnOn();
            setStateAppliance(riceCookerArray[index]);
            return true;
        }
        else{
            cout << "**잘못 입력하셨습니다." << endl;
            return false;
        }
    }
}
