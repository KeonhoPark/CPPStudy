#ifndef __SCREEN_H__
#define __SCREEN_H__

// ���� ����
class Product;
class Customer;

class Screen
{
public:
    enum { MENU_BEGIN = 1, MENU_END = 10 };
    
    int  inputNumber(const string &msg) const;     // ���޵� �޼����� ����ϰ� ������ �Է� �޾� ����
    void outputMessage(const string &msg) const;   // ���޵� �޼����� ����ϰ� ����

    void showMenu() const;                         // �ָ޴� ���
    int getMenuSelect() const;                     // �޴���ȣ ������(MENU_BEGIN~MENU_END)���� �޴���ȣ�� �Է� �޾� ����
    
    // �޴� : 1, 2, 3
    void showAllProductList(const Product *list, int count) const;  // �뿩���� �ִ� ��� ������ǰ ���
    void showCustomerList(Customer ** const list, int count) const; // �뿩���� ��ϵ� �� ���(���ΰ�, �����  ��� �� �������� ���)

    // �޴� : 4, 5, 6, 7
    void showRentalCustomerList(Customer ** const list, int count) const;  // �뿩�� �� ��ϸ� ���(���ΰ�, ����� ��� �� �������� ���)
    void showRentalProductList(const Product *list, int count, bool isRental) const;  // �뿩�� �� �ִ� ��ǰ ���, isRental �÷��׸� ����Ͽ� �뿩 �Ұ��� ó��

    // �޴� 8, 9�� RentalShop Ŭ�������� ó��.
};

#endif /* defined(__SCREEN_H__) */
