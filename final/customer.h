#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <iostream>
#include <string>
using namespace std;

enum { NOT_USED = -1 }; // 프로젝트 전체 공통 상수로 "사용할 수 없음"을 의미

class Customer
{
public:
    enum { TYPE_PERSON = 1, TYPE_COMPANY };  // 개인고객 상수, 기업고객 상수
    enum { RENTAL_MAX_PERSON = 2, RENTAL_MAX_COMPANY = 5 }; //개인고객의 최대 대여가능 수, 기업고객의 최대 대여 가능 수 
    
	Customer(int type_); // type은 parameter 값, rentalCount는 0, id는 createId()함수의 return값, maxCont는 고객type에 따라 enum 상수로 설정된 값으로 초기화
	                     // rentalList는 maxCount개의 대여제품Id를 저장할 공간 동적할당 후 힐당된 공간 모두 0으로 초기화
	Customer(const Customer &r);      //복사 생성자
    virtual ~Customer();        // 가상 소멸자
	
    int getId()   const { return this->id;  } // id 멤버의 값 리턴
    int getType() const { return this->type;} // type 멤버의 값 리턴
	int *getRentalList() const { return this->rentalList; }  // retalList 멤버의 값 리턴
	int getRentalCount() const { return this->rentalCount; } // rentalCount 멤버의 값 리턴

	Customer & operator=(const Customer &r);  // 대입연산자 오버로딩 함수
    bool  isRental() const { return this->rentalCount > 0; } // 고객이 대여 건수를 확인하여 대여 고객인지 아닌지를 판별
    bool canRental() const { return this->rentalCount < this->maxCount; }  // 대여 가능 여부 식별
    bool    addRental(int productId); // 해당제품 대여처리, 대여 결과 리턴
    bool removeRental(int productId); // 해당제품 반납처리, 반납 결과 리턴    
    int findRentalIndex(int productId) const; // 대여목록에서 해당 제품검색 후 index리턴(목록에 없는 경우 NOT_USED리턴)
      
    virtual void showInfo() const;  // 고객id, 대여 제품 수, 최대 대여 가능 제품 수 출력

private:
    // 고객 아이디 자동 발급에서 사용
    static int gCount;          // static 멤버데이터 선언부 - 별도로 정의해주어야 함.
    static int createId();      // gCount를 이용한 아이디 반환
    
protected:
	int rentalCount;            // 현재 대여한 갯수
	int maxCount;               // 최대 대여가능 갯수
	int *rentalList;            // 대여 목록(제품 아이디 저장)
	int type;                   // 개인/기업 type 저장
    int id;                     // 고객 식별자
};

#endif
