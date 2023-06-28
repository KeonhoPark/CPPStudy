#ifndef __RICECOOKER_H__
#define	__RICECOOKER_H__
#include "Appliance.h"
#include <string>
class RiceCooker : public Appliance
{
public : 
 
	RiceCooker(); // Appliance default생성자로 생성, machineState는 무동작으로 초기화
	RiceCooker(string machineName); // Appliance Overloaded 생성자로 생성, machineState는 무동작으로 초기화
	// getter, setter member function
	int getMachineState() const; // machineState 멤버 값 반환 함수
	void setMachineState(int machineState); // machineState 멤버 초기화 함수
	// member function
	void stateView(); // 객체의 상태 출력
	
private :
	int machineState; // 제품상태(1:무동작, 2:보온, 3:밥짓기, 4:데우기)
};
#endif
