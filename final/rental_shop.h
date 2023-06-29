#ifndef __RENTALSHOP_H__
#define __RENTALSHOP_H__

#include "product.h"
#include "person_customer.h"
#include "company_customer.h"
#include "screen.h"

class RentalShop
{
public:
	RentalShop();   // extern �迭��� products, persons, companies ��� �ʱ�ȭ
    ~RentalShop() {} // �Ҹ��� �Լ�
    
    void mainLoop() const; // �۾��Լ�
    void processMenu(int menu) const; // ��� ����� �� Ŭ����(Screen)�� ����Լ��� ó���ϰ�, ����� �Է�(�뿩/�ݳ�)�� ��Ʈ�ѷ� Ŭ����(RentalShop)���� ó��
    
    Product  *findProduct(int productId) const;   // �ش� ��ǰid�� ��ǰ ã��(�����ϸ� ��ü�� �ּ�, ������ NULL pointer ����)
    Customer *findCustomer(int customerId) const; // ���ΰ� �迭�� ����� �迭���� �ش� ��id�� �� ã��
	                                              // (�����ϸ� ��ü�� �ּ�, ������ NULL pointer ����)
	                                              // int findCustomer(int, Customer**, int)�� 2���� ȣ���Ͽ� �ش� ���� index�� �޾ƿ��� ����
    int findCustomer(int customerId, Customer ** p, int count) const; // Customer *findCustomer(int)�Լ��� ���� ȣ��Ǿ� ��id�� �ش��ϴ� 
	                                              // ���� �迭���� index�� ����, ������ NULL pointer ����(���ΰ�/����� �˻��� ���Ǵ� �����Լ�)

    void processRental() const;   // �뿩 �Լ�:��id�� ��ǰid�� �˻��Ͽ� ��ȿ�ϸ�(�Է� �� ��ȿ���˻�� processChecker()����Լ��� �˻�) �뿩(�뿩�� ��ǰ�̳� �뿩������ �ʰ��� ���� ���� �뿩�Ұ� �޼��� ���, �뿩 ���� �� �����޼��� ���
    void processReturn() const;   // �ݳ� �Լ�:��id�� ��ǰid�� �˻��Ͽ� ��ȿ�ϸ�(�Է� �� ��ȿ�˻�� processChecker()����Լ��� �˻�) �ݳ�(�̹� �ݳ��� ��ǰ�� ���� �ݳ��Ұ� �޼��� ���, �ݳ� ������ �����޼��� ���
    bool processChecker(Customer *&pc, Product *&pp) const; // ��id�� ��ǰid�� �Է� �޾� �ش� ���� ��ǰ�� ã���� �� �ּҸ� parameter�� �����ϰ�, ��ã���� NULL pointer�� ����

private:
    Product *products;    // ��ǰ��� ���� ���
    int productCount;     // ��ǰ��� ���� ����
    
    Customer **persons;   // ���ΰ� ���� ���
    int personCount;      // ���ΰ� ��� ����
    
    Customer **companies; // ����� ���� ���
    int companyCount;     // ����� ��� ����
    
    Screen *screen;       // ȭ�� ���� ��ü ���� ���
};

#endif

