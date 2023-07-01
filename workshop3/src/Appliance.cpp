#include<iostream>
using namespace std;
#include "Appliance.h"

Appliance::Appliance(){
    machineName = "";
    powerFlag = false;
}

Appliance::Appliance(string name, bool flag){
    machineName = name;
    powerFlag = flag;
}

string Appliance::getMachineName() const{
    return machineName;
}

bool Appliance::getPowerFlag() const{
    return powerFlag;
}

void Appliance::setMachineName(string name){
    machineName = name;
}

void Appliance::setPowerFlag(bool flag){
    powerFlag = flag;
}

bool Appliance::turnOn(){
    if(powerFlag == false){
        powerFlag = true;
        return true;
    }
    else{
        return false;
    }
}

bool Appliance::turnOff(){
    if(powerFlag == true){
        powerFlag = false;
        return true;
    }
    else{
        return false;
    }
}

void Appliance::stateView(){
    if(powerFlag = true){
        cout << "제품명 : " << machineName << "(On)";
    }
    else{
        cout << "제품명 : " << machineName << "(Off)";
    }
}

