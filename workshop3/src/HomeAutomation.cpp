#include<iostream>
using namespace std;	
#include "HomeAutomation.h"

HomeAutomation::HomeAutomation(){
    memset(this->riceCookerArray, 0, sizeof(this->riceCookerArray));
    riceCookerCnt = 0;
}

HomeAutomation::HomeAutomation(const HomeAutomation &r){
    riceCookerCnt = r.getRiceCookerCnt();
    for(int i = 0; i < this->riceCookerCnt; i++){
        this->riceCookerArray[i] = new RiceCooker(r.riceCookerArray[i]);
    }
}

HomeAutomation::~HomeAutomation(){
    for(int i = 0; i < sizeof(this->riceCookerArray); i++){
        delete this->riceCookerArray[i];
    }
}

RiceCooker** HomeAutomation::getRiceCookerArray(){
    return riceCookerArray;
}

int HomeAutomation::getRiceCookerCnt() const{
    return riceCookerCnt;
}

HomeAutomation& HomeAutomation::operator=(const HomeAutomation &r){
    if(r == *this){
        return *this
    }

    this->riceCookerCnt = r.getRiceCookerCnt();

    for(int i = 0; i < sizeof(this->riceCookerArray); i++){
        delete this->riceCookerArray[i];
    }

    for(int i = 0; i < sizeof(this->riceCookerArray); i++){
        this->riceCookerArray[i] = new RiceCooker(r.riceCookerArray[i]);
    }

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
