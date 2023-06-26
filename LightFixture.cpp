#include <iostream>
#include <string>

#include "LightFixture.h"
using namespace std;

void LightFixture::initLightFixture(const string machineName, bool powerFlag){
    this->machineName.assign(machineName);
    this->powerFlag = powerFlag;
}

string LightFixture::getMachineName() const{
    return machineName;
}

bool LightFixture::getPowerFlag() const{
    return powerFlag;
}

void LightFixture::setMachineName(const string machineName){
    this->machineName.assign(machineName);
    // strcpy(this->machineName, machineName);
}

void LightFixture::setPowerFlag(bool powerFlag){
    this->powerFlag = powerFlag;
}

bool LightFixture::turnOn(){
    if(this->powerFlag == true) return false;
    this->powerFlag = true;
    return true;
}

bool LightFixture::turnOff(){
    if(this->powerFlag == false) return false;
    this->powerFlag = false;
    return true;
}

void LightFixture::stateView(){
    if(this->getPowerFlag() == true){
        cout << "제품명 : " << getMachineName() << " (ON)" << endl;
    }
    else{
        cout << "제품명 : " << getMachineName() << " (OFF)" << endl;
    }
}

