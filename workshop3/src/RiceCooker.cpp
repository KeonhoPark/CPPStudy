#include "RiceCooker.h"
#include<iostream>
#include<string>

RiceCooker::RiceCooker() : Appliance(){
    machineState = 1;
}

RiceCooker::RiceCooker(string name) : Appliance(name){
	machineState = 1;
}

int RiceCooker::getMachineState() const{
	return machineState;
}

void RiceCooker::setMachineState(int state){
	machineState = state;
}

void RiceCooker::stateView(){
    if(getPowerFlag() == true){
		switch (machineState)
		{
		case 1:
			cout << "제품명 : " << this->getMachineName() << "(On)" << " 설정상태 : ";
			cout << "무동작" << endl;
			break;
		case 2:
			cout << "제품명 : " << this->getMachineName() << "(On)" << " 설정상태 : ";
			cout << "보온" << endl;
			break;
		case 3:
			cout << "제품명 : " << this->getMachineName() << "(On)" << " 설정상태 : ";
			cout << "밥짓기" << endl;
			break;
		case 4:
			cout << "제품명 : " << this->getMachineName() << "(On)" << " 설정상태 : ";
			cout << "데우기" << endl;
			break;
		case 5:
			cout << "제품명 : " << this->getMachineName() << "(Off)";
			break;
		default:
			break;
		}
    }
    else{
        cout << "제품명 : " << this->getMachineName() << "(Off)";
    }
}