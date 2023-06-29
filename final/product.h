#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    Product(int id_, const string &title_, int price_);  // id, title, price�� parameter�� �ʱ�ȭ, rental�� true�� �ʱ�ȭ
    ~Product(); // �Ҹ����Լ������� �����Ǵ� ��ǰ�� id�� ����� ��

    int    getId()    const { return this->id;   }       // id ��� �� ���� �Լ�
    string getTitle() const { return this->title;}       // title ��� �� ���� �Լ�
    int    getPrice() const { return this->price;  }     // price ��� �� ���� �Լ�
    bool   getRental() const { return this->rental; }    // rental ��� �� ���� �Լ�
	void   setRental(bool rental_) { this->rental = rental_;}  // rental ��� �ʱ�ȭ �Լ�

	Product &operator=(const Product &obj);  // ���Կ����� �����ε� �Լ�
	friend ostream &operator <<(ostream &out, const Product &obj);  // extern ��¿����� �����ε� �Լ� friend ����

private:
	int    id;      // ��ǰ id
	string title;   // ��ǰ��
	bool   rental;  // ��ǰ �뿩 ���� (true : �뿩 ����, false : �뿩 �Ұ���)
	int    price;   // ��ǰ �뿩���
};

#endif
