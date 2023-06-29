#ifndef __CUSTOMER_TYPE_COMPANY_H__
#define __CUSTOMER_TYPE_COMPANY_H__


#include "customer.h"

class CompanyCustomer : public Customer
{
public:
    enum CompSize { SIZE_BIG, SIZE_MEDIUM, SIZE_MINI }; // 기업규모 상수 : 대기업, 중기업, 소기업  
    
	CompanyCustomer(const string &title_, const string &address_, CompSize size_); // type은 기업고객으로, title, address, size는 parameter로 초기화
    
    // getter memeber 함수
    string getTitle()   const { return this->title ; }  // title멤버 값 리턴 함수 
    string getAddress() const { return this->address; } // address멤버 값 리턴 함수
    CompSize getSize()    const { return this->size; }  // size멤버 값 리턴 함수
    
    virtual void showInfo() const; // 기업고객명, 주소, 기업규모(대기업, 중기업, 소기업) 출력
    
protected:
    string title;   // 기업고객 회사명
    string address; // 주소
    CompSize size;  // 기업규모
};

#endif
