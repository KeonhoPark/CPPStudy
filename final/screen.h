#ifndef __SCREEN_H__
#define __SCREEN_H__

// 전방 선언
class Product;
class Customer;

class Screen
{
public:
    enum { MENU_BEGIN = 1, MENU_END = 10 };
    
    int  inputNumber(const string &msg) const;     // 전달된 메세지를 출력하고 정수를 입력 받아 리턴
    void outputMessage(const string &msg) const;   // 전달된 메세지를 출력하고 개행

    void showMenu() const;                         // 주메뉴 출력
    int getMenuSelect() const;                     // 메뉴번호 범위내(MENU_BEGIN~MENU_END)내의 메뉴번호만 입력 받아 리턴
    
    // 메뉴 : 1, 2, 3
    void showAllProductList(const Product *list, int count) const;  // 대여점에 있는 모든 가전제품 출력
    void showCustomerList(Customer ** const list, int count) const; // 대여점에 등록된 고객 출력(개인고객, 기업고객  출력 시 공통으로 사용)

    // 메뉴 : 4, 5, 6, 7
    void showRentalCustomerList(Customer ** const list, int count) const;  // 대여한 고객 목록만 출력(개인고객, 기업고객 출력 시 공통으로 사용)
    void showRentalProductList(const Product *list, int count, bool isRental) const;  // 대여할 수 있는 제품 출력, isRental 플래그를 사용하여 대여 불가도 처리

    // 메뉴 8, 9는 RentalShop 클래스에서 처리.
};

#endif /* defined(__SCREEN_H__) */
