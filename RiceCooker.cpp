#include "RiceCooker.h"
#include "Appliance.h"
#include<iostream>
// #include<string>

using namespace std;

// class RiceCooker : public Appliance
// {
// public : 
// 	RiceCooker(); // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
// 	RiceCooker(string machineName); // Appliance Overloaded 생성자로 생성, machineState는 무동작으로 초기화
// 	// getter, setter member function
// 	int getMachineState() const; // machineState 멤버 값 반환 함수
// 	void setMachineState(int machineState); // machineState 멤버 초기화 함수
// 	// member function
// 	void stateView(); // 객체의 상태 출력
	
// private :
// 	int machineState; // 제품상태(1:무동작, 2:보온, 3:밥짓기, 4:데우기)

// };

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
			cout << "제품명 : " << getMachineName() << "(On)" << " 설정상태 : ";
			cout << "무동작" << endl;
			break;
		case 2:
			cout << "제품명 : " << getMachineName() << "(On)" << " 설정상태 : ";
			cout << "보온" << endl;
			break;
		case 3:
			cout << "제품명 : " << getMachineName() << "(On)" << " 설정상태 : ";
			cout << "밥짓기" << endl;
			break;
		case 4:
			cout << "제품명 : " << getMachineName() << "(On)" << " 설정상태 : ";
			cout << "데우기" << endl;
			break;
		case 5:
			cout << "제품명 : " << getMachineName() << "(Off)";
			break;
		default:
			break;
		}
    }
    else{
        cout << "제품명 : " << getMachineName() << "(Off)";
    }
}