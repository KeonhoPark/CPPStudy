#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <iostream>
#include <string>
using namespace std;

enum { NOT_USED = -1 }; // ������Ʈ ��ü ���� ����� "����� �� ����"�� �ǹ�

class Customer
{
public:
    enum { TYPE_PERSON = 1, TYPE_COMPANY };  // ���ΰ� ���, ����� ���
    enum { RENTAL_MAX_PERSON = 2, RENTAL_MAX_COMPANY = 5 }; //���ΰ��� �ִ� �뿩���� ��, ������� �ִ� �뿩 ���� �� 
    
	Customer(int type_); // type�� parameter ��, rentalCount�� 0, id�� createId()�Լ��� return��, maxCont�� ��type�� ���� enum ����� ������ ������ �ʱ�ȭ
	                     // rentalList�� maxCount���� �뿩��ǰId�� ������ ���� �����Ҵ� �� ����� ���� ��� 0���� �ʱ�ȭ
	Customer(const Customer &r);      //���� ������
    virtual ~Customer();        // ���� �Ҹ���
	
    int getId()   const { return this->id;  } // id ����� �� ����
    int getType() const { return this->type;} // type ����� �� ����
	int *getRentalList() const { return this->rentalList; }  // retalList ����� �� ����
	int getRentalCount() const { return this->rentalCount; } // rentalCount ����� �� ����

	Customer & operator=(const Customer &r);  // ���Կ����� �����ε� �Լ�
    bool  isRental() const { return this->rentalCount > 0; } // ���� �뿩 �Ǽ��� Ȯ���Ͽ� �뿩 ������ �ƴ����� �Ǻ�
    bool canRental() const { return this->rentalCount < this->maxCount; }  // �뿩 ���� ���� �ĺ�
    bool    addRental(int productId); // �ش���ǰ �뿩ó��, �뿩 ��� ����
    bool removeRental(int productId); // �ش���ǰ �ݳ�ó��, �ݳ� ��� ����    
    int findRentalIndex(int productId) const; // �뿩��Ͽ��� �ش� ��ǰ�˻� �� index����(��Ͽ� ���� ��� NOT_USED����)
      
    virtual void showInfo() const;  // ��id, �뿩 ��ǰ ��, �ִ� �뿩 ���� ��ǰ �� ���

private:
    // �� ���̵� �ڵ� �߱޿��� ���
    static int gCount;          // static ��������� ����� - ������ �������־�� ��.
    static int createId();      // gCount�� �̿��� ���̵� ��ȯ
    
protected:
	int rentalCount;            // ���� �뿩�� ����
	int maxCount;               // �ִ� �뿩���� ����
	int *rentalList;            // �뿩 ���(��ǰ ���̵� ����)
	int type;                   // ����/��� type ����
    int id;                     // �� �ĺ���
};

#endif
