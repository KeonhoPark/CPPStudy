#ifndef __CUSTOMER_TYPE_PERSON_H__
#define __CUSTOMER_TYPE_PERSON_H__

#include "customer.h"

class PersonCustomer : public Customer
{
public:
	PersonCustomer(const string &name_, const string &phone_); // type은 개인고객으로, name, phone은 parameter로 초기화

    string getName()  const { return this->name ; }  // name멤버 값 리턴
    string getPhone() const { return this->phone; }  // phone멤버 값 리턴
    
    // 이름은 변경 불가. 기본 정보에 해당.
    void setPhone(const string &phone_) { this->phone = phone_; }  // phone멤버 초기화 함수
    
    virtual void showInfo() const; // 고객명과 고객 연락처 출력
    
protected:
    string name;  // 개인고객명
    string phone; // 연락처
};

#endif
