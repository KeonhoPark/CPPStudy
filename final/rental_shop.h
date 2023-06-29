#ifndef __RENTALSHOP_H__
#define __RENTALSHOP_H__

#include "product.h"
#include "person_customer.h"
#include "company_customer.h"
#include "screen.h"

class RentalShop
{
public:
	RentalShop();   // extern 배열들로 products, persons, companies 멤버 초기화
    ~RentalShop() {} // 소멸자 함수
    
    void mainLoop() const; // 작업함수
    void processMenu(int menu) const; // 모든 출력은 뷰 클래스(Screen)의 멤버함수로 처리하고, 사용자 입력(대여/반납)은 컨트롤로 클래스(RentalShop)에서 처리
    
    Product  *findProduct(int productId) const;   // 해당 제품id의 제품 찾기(존재하면 객체의 주소, 없으면 NULL pointer 리턴)
    Customer *findCustomer(int customerId) const; // 개인고객 배열과 기업고객 배열에서 해당 고객id의 고객 찾기
	                                              // (존재하면 객체의 주소, 없으면 NULL pointer 리턴)
	                                              // int findCustomer(int, Customer**, int)를 2차례 호출하여 해당 고객의 index를 받아오는 구조
    int findCustomer(int customerId, Customer ** p, int count) const; // Customer *findCustomer(int)함수로 부터 호출되어 고객id에 해당하는 
	                                              // 고객의 배열내의 index를 리턴, 없으면 NULL pointer 리턴(개인고객/기업고객 검색에 사용되는 공통함수)

    void processRental() const;   // 대여 함수:고객id와 제품id를 검사하여 유효하면(입력 및 유효성검사는 processChecker()멤버함수로 검사) 대여(대여된 제품이나 대여갯수를 초과한 고객에 대한 대여불가 메세지 출력, 대여 성공 시 성공메세지 출력
    void processReturn() const;   // 반납 함수:고객id와 제품id를 검사하여 유효하면(입력 및 유효검사는 processChecker()멤버함수로 검사) 반납(이미 반납된 제품데 대한 반납불가 메세지 출력, 반납 성공시 성공메세지 출력
    bool processChecker(Customer *&pc, Product *&pp) const; // 고객id와 제품id를 입력 받아 해당 고객와 제품을 찾으면 그 주소를 parameter에 저장하고, 못찾으면 NULL pointer를 저장

private:
    Product *products;    // 제품목록 저장 멤버
    int productCount;     // 제품목록 갯수 저장
    
    Customer **persons;   // 개인고객 저장 멤버
    int personCount;      // 개인고객 명수 저장
    
    Customer **companies; // 기업고객 저장 멤버
    int companyCount;     // 기업고객 명수 저장
    
    Screen *screen;       // 화면 제어 객체 저장 멤버
};

#endif

