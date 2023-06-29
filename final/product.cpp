#include"product.h"

// class Product
// {
// public:
//     Product(int id_, const string &title_, int price_);  // id, title, price는 parameter로 초기화, rental은 true로 초기화
//     ~Product(); // 소멸자함수내에서 삭제되는 제품의 id를 출력해 줌

//     int    getId()    const { return this->id;   }       // id 멤버 값 리턴 함수
//     string getTitle() const { return this->title;}       // title 멤버 값 리턴 함수
//     int    getPrice() const { return this->price;  }     // price 멤버 값 리턴 함수
//     bool   getRental() const { return this->rental; }    // rental 멤버 값 리턴 함수
// 	void   setRental(bool rental_) { this->rental = rental_;}  // rental 멤버 초기화 함수

// 	Product &operator=(const Product &obj);  // 대입연산자 오버로딩 함수
// 	friend ostream &operator <<(ostream &out, const Product &obj);  // extern 출력연산자 오버로딩 함수 friend 선언

// private:
// 	int    id;      // 제품 id
// 	string title;   // 제품명
// 	bool   rental;  // 제품 대여 상태 (true : 대여 가능, false : 대여 불가능)
// 	int    price;   // 제품 대여비용
// };

Product::Product(int id_, const string &title_, int price_){
    id = id_;
    title = title_;
    price = price_;
    rental = true;
}

Product::~Product{
    cout<<"제품 ID: "<<id;
}

Product& Product::operator=(const Product &obj){
    Product newProduct(obj.getId(), obj.getTitle(), obj.getPrice());
    newProduct.setRental(obj.getRental());
}

ostream& operator<<(ostream &out, const Product &obj){
    if(obj.rental == true){
        out<<'['<<obj.id<<" 가능"<<'] '<<obj.title<<", "<<obj.price<<endl;
    }
    else{
        out<<'['<<obj.id<<" 불가"<<'] '<<obj.title<<", "<<obj.price<<endl;
    }
}
