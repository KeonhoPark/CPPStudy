#ifndef __RICECOOKER_H__
#define	__RICECOOKER_H__
#include "Appliance.h"

class RiceCooker : public Appliance
{
public : 
 
	RiceCooker(); // Appliance default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	RiceCooker(string machineName); // Appliance Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	// getter, setter member function
	int getMachineState() const; // machineState ���? �� ��ȯ �Լ�
	void setMachineState(int machineState); // machineState ���? �ʱ�ȭ �Լ�
	// member function
	void stateView(); // ��ü�� ���� ���?
	
private :
	int machineState; // ��ǰ����(1:������, 2:����, 3:������, 4:�����?)
};
#endif
