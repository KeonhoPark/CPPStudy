#include<iostream>
using namespace std;

class FruitSeller{
    private:
        int APPLE_PRICE;
        int numOfApples;
        int money;

    public:
        void init(int price, int num, int mon);
        int sellApple(int income);
        void showSalesResult() const;
};

class FruitBuyer{
    private:
        int money;
        int numOfApples;

    public:
        void init(int mon);
        bool buyApple(FruitSeller &seller, int outcome);
        void showBuyResult() const;
};

void FruitSeller::init(int price, int num, int mon){
    APPLE_PRICE = price;
    numOfApples = num;
    money = mon;
}

int FruitSeller::sellApple(int income){
    int num = income / APPLE_PRICE;
    numOfApples -= num;
    money += income;
    return num;
}

void FruitSeller::showSalesResult() const{
    cout << "남은 사과 : " << numOfApples << endl;
    cout << "판매 수익 : " << money << endl;
}

void FruitBuyer::init(int mon){
    money = mon;
    numOfApples = 0;
}

bool  FruitBuyer::buyApple(FruitSeller &seller, int outcome){
    if(outcome < 0){
        cout << "outcome이 음수입니다." << endl;
        return false;
    }
    int num = seller.sellApple(outcome);
    numOfApples += num;
    money -= outcome;
}

void  FruitBuyer::showBuyResult() const{
    cout << "현재 잔액 : " << money << endl;
    cout << "사과 개수 : " << numOfApples << endl;
}

int main(){
    FruitSeller seller;
    seller.init(1000, 30, 0);
    FruitBuyer buyer;
    buyer.init(10000);

    buyer.buyApple(seller, 2000);

    seller.showSalesResult();
    buyer.showBuyResult();

    return 0;
}