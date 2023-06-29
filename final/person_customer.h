#ifndef __CUSTOMER_TYPE_PERSON_H__
#define __CUSTOMER_TYPE_PERSON_H__

#include "customer.h"

class PersonCustomer : public Customer
{
public:
	PersonCustomer(const string &name_, const string &phone_); // type�� ���ΰ�����, name, phone�� parameter�� �ʱ�ȭ

    string getName()  const { return this->name ; }  // name��� �� ����
    string getPhone() const { return this->phone; }  // phone��� �� ����
    
    // �̸��� ���� �Ұ�. �⺻ ������ �ش�.
    void setPhone(const string &phone_) { this->phone = phone_; }  // phone��� �ʱ�ȭ �Լ�
    
    virtual void showInfo() const; // ����� �� ����ó ���
    
protected:
    string name;  // ���ΰ���
    string phone; // ����ó
};

#endif
