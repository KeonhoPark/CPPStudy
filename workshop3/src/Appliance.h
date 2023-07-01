#ifndef __APPLIANCE_H__
#define __APPLIANCE_H__
#include <string>

class Appliance
{
	public :
		// constructor, destructor : deep copy cons.�� destructor�� ������ ����,���� ����
		Appliance();  // default constructor (machineName:Null string, powerFlag:false)
		Appliance(string machineName, bool powerFlag=false);
		~Appliance() { } //�Ҹ���
		// getter, setter member function
		string getMachineName() const;  // machineName �����? ��ȯ �Լ�
		bool getPowerFlag() const; // powerFlag ���? �� ��ȯ �Լ� 
		void setMachineName(string machineName);  // machineName ���? �ʱ�ȭ �Լ�
		void setPowerFlag(bool powerFlag); // powerFlag ���? �ʱ�ȭ �Լ� 
		// member fucntion
		bool turnOn(); // ��ǰ�� �Ѵ�
		bool turnOff(); // ��ǰ�� ����
		void stateView(); // ��ǰ�� ���¸� ����ϴ�?
	private :
		string machineName;  // ������ǰ��
		bool powerFlag;  // ���� on_off����(on-ture, off-false)
};
#endif
