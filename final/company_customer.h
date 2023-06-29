#ifndef __CUSTOMER_TYPE_COMPANY_H__
#define __CUSTOMER_TYPE_COMPANY_H__


#include "customer.h"

class CompanyCustomer : public Customer
{
public:
    enum CompSize { SIZE_BIG, SIZE_MEDIUM, SIZE_MINI }; // ����Ը� ��� : ����, �߱��, �ұ��  
    
	CompanyCustomer(const string &title_, const string &address_, CompSize size_); // type�� ���������, title, address, size�� parameter�� �ʱ�ȭ
    
    // getter memeber �Լ�
    string getTitle()   const { return this->title ; }  // title��� �� ���� �Լ� 
    string getAddress() const { return this->address; } // address��� �� ���� �Լ�
    CompSize getSize()    const { return this->size; }  // size��� �� ���� �Լ�
    
    virtual void showInfo() const; // �������, �ּ�, ����Ը�(����, �߱��, �ұ��) ���
    
protected:
    string title;   // ����� ȸ���
    string address; // �ּ�
    CompSize size;  // ����Ը�
};

#endif
