#include<iostream>
#include<string>
#include "LightAutomation.h"
#include "LightFixture.h"
#include "LightFixture.cpp"
using namespace std;

void LightAutomation::initLightAutomation(){
    for(int i = 0; i < LIGHT_MAX_CNT; i++){
        LightFixture* newLightFixture = new LightFixture;
        newLightFixture->initLightFixture("");
        *(this->lightArray + i) = *newLightFixture;
    }
    this->lightCnt = 0;
}

LightFixture* LightAutomation::getLightArray(){
    return this->lightArray;
}

int LightAutomation::getLightCnt() const{
    return this->lightCnt;
}

void LightAutomation::setLightCnt(int lightCnt) {
    this->lightCnt = lightCnt;
}

bool LightAutomation::addAlliance(LightFixture &ap){
    int lightCnt = this->getLightCnt();
    cout << "lightCnt" << lightCnt << endl;
    LightFixture* lightArray = this->getLightArray();

    if(lightCnt == LIGHT_MAX_CNT) {
        cout << "** 가능한 전등 등록 갯수를 넘어섰습니다." << endl;
        return false;
    }
    for(int i = 0; i < LIGHT_MAX_CNT; i++){
        string machineName = (lightArray + i)->getMachineName();
        if(machineName.compare(ap.getMachineName()) == 0){
            cout << "** 이미 같은이름의 전등이 있습니다." << endl;
            return false;
        }
        else if(machineName.empty()){
            *(lightArray + i) = ap;
            this->setLightCnt(++lightCnt);
            return true;
        }
    }
}

int LightAutomation::searchMachine(string machineName){
    if(machineName.empty()) return -1;

    LightFixture* lightArray = this->getLightArray();
    for(int i = 0; i < LIGHT_MAX_CNT; i++){
        string name = (lightArray+i)->getMachineName();
        if(name.compare(machineName) == 0) return i;
    }
    return -1;
}

bool LightAutomation::deleteAlliance(string machineName){
    if(machineName.empty()) return false;

    int index = searchMachine(machineName);
    if(index == -1) return false;

    LightFixture* lightArray = this->getLightArray();
    int curCnt = this->getLightCnt();
    if(sizeof(lightArray) == 0) return false;

    for(int i = index; i < curCnt - 1; i++){
        *(lightArray + i) = *(lightArray + (i + 1));
    }
    LightFixture* newLightFixture = new LightFixture;
    newLightFixture->initLightFixture("");
    *(this->lightArray + (curCnt - 1)) = *newLightFixture;

    setLightCnt(--curCnt);

    return true;
}

void LightAutomation::listDisplayAlliance(){
    LightFixture* lightArray = this->getLightArray();
    for(int i = 0; i < LIGHT_MAX_CNT; i++){
        string curName = (lightArray + i)->getMachineName();
        if(curName.empty() == false){
            (lightArray + i)->stateView();
        }
    }
}

bool LightAutomation::controlAlliance(string machineName){
    if(machineName.empty()) return false;

    int index = searchMachine(machineName);
    if(index == -1) return false;

    LightFixture* lightArray = this->getLightArray();
    LightFixture curLight = *(lightArray + index);
    ((lightArray + index)->getPowerFlag()) ? (lightArray + index)->turnOff() : (lightArray + index)->turnOn();
}
