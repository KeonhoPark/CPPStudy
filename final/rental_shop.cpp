#include "rental_shop.h"

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

// ��ǰ���� ���� ��ü �迭
Product sampleProducts[] =
{
	Product(0, "��ǳ��", 90000),
	Product(1, "�����", 220000),
	Product(2, "���ڷ�����", 150000),
	Product(3, "��Ź��", 1000000),
	Product(4, "����ƮTV", 3200000),
	Product(5, "����ũž", 1230000),
	Product(6, "��Ʈ��", 1350000),
	Product(7, "�ڵ���", 810000),
	Product(8, "�����", 1600000),
	Product(9, "û�ұ�", 230000)
};

// ���ΰ� ���� ���� �迭
Customer *samplePersons[] =
{
	new PersonCustomer("�迵ö", "010-1234-5678"),
	new PersonCustomer("����ȣ", "010-1122-3344"),
	new PersonCustomer("�ڼ���", "010-3355-7788"),
};

// ����� ���� ���� �迭
Customer *sampleCompanies[] =
{
	new CompanyCustomer("�����Ǿ�", "����", CompanyCustomer::SIZE_BIG),
	new CompanyCustomer("������ũ��", "�����", CompanyCustomer::SIZE_MEDIUM),
};

RentalShop::RentalShop()
	: productCount( sizeof(sampleProducts)/sizeof(sampleProducts[0]))   // ��ǰ ���� ����
	, products(sampleProducts)                                          // extern sampleProducts�迭�� products �ʱ�ȭ
	, personCount( sizeof(samplePersons)/sizeof(samplePersons[0]))      // ���ΰ� �ο� ����
	, persons(samplePersons)                                            // extern samplePersons�迭�� persons �ʱ�ȭ
	, companyCount( sizeof(sampleCompanies)/sizeof(sampleCompanies[0])) // ����� ȸ��� ����
	, companies(sampleCompanies)                                        // sampleCompanies �迭�� companies �ʱ�ȭ
	, screen(new Screen)
{
	// ������ ��ǰ�� ���� �뿩 ó�� �ڵ带 ������ ����
	Product  *p1 = &this->products[1];
	Product  *p2 = &this->products[2];
	Product  *p3 = &this->products[3];
	 
	Customer *c1 = this->persons[0];
	Customer *c2 = this->companies[0];

	p1->setRental(false);
	p2->setRental(false);
	p3->setRental(false);

	c1->addRental(p1->getId()); 
	c1->addRental(p2->getId());
	c2->addRental(p3->getId());
}

void RentalShop::mainLoop() const
{
	while(true)
	{
		this->screen->showMenu();

		int menu = this->screen->getMenuSelect();

		if(menu == this->screen->MENU_END) // �ý��� ���� �޴� ���ý�
		{
			this->screen->outputMessage("������ǰ ��Ż �ý��� ����");
			break;
		}

		processMenu(menu); 
	}
}

void RentalShop::processMenu(int menu) const
{
	// ��� ��� �ڵ�� �� Ŭ����(Screen)�� ����. ����� �Է�(�뿩/�ݳ�)�� ��Ʈ�ѷ� Ŭ����(RentalShop)���� ó��
	switch(menu)
	{
	case 1 : this->screen->showAllProductList    (this->products,  this->productCount);         break;
	case 2 : this->screen->showCustomerList      (this->persons,   this->personCount );         break;
	case 3 : this->screen->showCustomerList      (this->companies, this->companyCount);         break;
	case 4 : this->screen->showRentalCustomerList(this->persons,   this->personCount );         break;
	case 5 : this->screen->showRentalCustomerList(this->companies, this->companyCount);         break;
	case 6 : this->screen->showRentalProductList (this->products,  this->productCount, false);  break;
	case 7 : this->screen->showRentalProductList (this->products,  this->productCount,  true);  break;
	case 8 : processRental();   break;
	case 9 : processReturn();   break;
	}
}

// �뿩 �Լ�
void RentalShop::processRental() const
{
   if(processChecker())
}

// ���̵� ��ȿ�� �˻�. �뿩 �� ���
bool RentalShop::processChecker(Customer* &pc, Product* &pp) const
{
    
}
// �ݳ� �Լ�
void RentalShop::processReturn() const
{

}

// �� �����ʹ� ���ΰ� ������� ���еǾ� �ִ�. �� �Լ������� ����������, ������Ʈ ��ü�� ���� ���� �����ϴ� ���� ����.
Customer* RentalShop::findCustomer(int customerId) const
{
	for(int i = 0; i < personCount; i++){
		if(*(persons+i)->getId() == customerId) return *(persons+i);
	}

	return nullptr;
}

// ���ΰ� ��� ��ο� ����ϱ� ���� ���� �Լ�
int RentalShop::findCustomer(int customerId, Customer**  p, int count) const
{
	for(int i = 0; i < count; i++){
		if(*(persons+i)->getId() == customerId) return i;
	}

	return NOT_USED;
}

// ��ǰ �˻�
Product* RentalShop::findProduct(int productId) const
{
	for(int i = 0; i < productCount; i++){
		if((products + i)->getId == productId) return (products + i);
	}

	return nullptr;
}

