#include "rental_shop.h"

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

// 제품정보 저장 객체 배열
Product sampleProducts[] =
{
	Product(0, "선풍기", 90000),
	Product(1, "모니터", 220000),
	Product(2, "전자레인지", 150000),
	Product(3, "세탁기", 1000000),
	Product(4, "스마트TV", 3200000),
	Product(5, "데스크탑", 1230000),
	Product(6, "노트북", 1350000),
	Product(7, "핸드폰", 810000),
	Product(8, "냉장고", 1600000),
	Product(9, "청소기", 230000)
};

// 개인고객 정보 저장 배열
Customer *samplePersons[] =
{
	new PersonCustomer("김영철", "010-1234-5678"),
	new PersonCustomer("정민호", "010-1122-3344"),
	new PersonCustomer("박수락", "010-3355-7788"),
};

// 기업고객 정보 저장 배열
Customer *sampleCompanies[] =
{
	new CompanyCustomer("유토피아", "울산시", CompanyCustomer::SIZE_BIG),
	new CompanyCustomer("웅진씽크빅", "서울시", CompanyCustomer::SIZE_MEDIUM),
};

RentalShop::RentalShop()
	: productCount( sizeof(sampleProducts)/sizeof(sampleProducts[0]))   // 제품 갯수 설정
	, products(sampleProducts)                                          // extern sampleProducts배열로 products 초기화
	, personCount( sizeof(samplePersons)/sizeof(samplePersons[0]))      // 개인고객 인원 설정
	, persons(samplePersons)                                            // extern samplePersons배열로 persons 초기화
	, companyCount( sizeof(sampleCompanies)/sizeof(sampleCompanies[0])) // 기업고객 회사수 설정
	, companies(sampleCompanies)                                        // sampleCompanies 배열로 companies 초기화
	, screen(new Screen)
{
	// 세개의 제품에 대한 대여 처리 코드를 수행해 놓음
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

		if(menu == this->screen->MENU_END) // 시스템 종료 메뉴 선택시
		{
			this->screen->outputMessage("가전제품 렌탈 시스템 종료");
			break;
		}

		processMenu(menu); 
	}
}

void RentalShop::processMenu(int menu) const
{
	// 모든 출력 코드는 뷰 클래스(Screen)에 존재. 사용자 입력(대여/반납)은 컨트롤러 클래스(RentalShop)에서 처리
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

// 대여 함수
void RentalShop::processRental() const
{
   if(processChecker())
}

// 아이디 유효성 검사. 대여 시 사용
bool RentalShop::processChecker(Customer* &pc, Product* &pp) const
{
    
}
// 반납 함수
void RentalShop::processReturn() const
{

}

// 고객 데이터는 개인과 기업으로 구분되어 있다. 이 함수에서는 복잡하지만, 프로젝트 전체로 봤을 때는 구분하는 것이 좋다.
Customer* RentalShop::findCustomer(int customerId) const
{
	for(int i = 0; i < personCount; i++){
		if(*(persons+i)->getId() == customerId) return *(persons+i);
	}

	return nullptr;
}

// 개인과 기업 모두에 사용하기 위한 공통 함수
int RentalShop::findCustomer(int customerId, Customer**  p, int count) const
{
	for(int i = 0; i < count; i++){
		if(*(persons+i)->getId() == customerId) return i;
	}

	return NOT_USED;
}

// 제품 검색
Product* RentalShop::findProduct(int productId) const
{
	for(int i = 0; i < productCount; i++){
		if((products + i)->getId == productId) return (products + i);
	}

	return nullptr;
}

