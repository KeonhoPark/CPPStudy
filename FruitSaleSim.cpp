#include<iostream>
using namespace std;

class FruitSeller{
    private:
        const int APPLE_PRICE;
        int numOfApples;
        int money;

    public:
        FruitSeller(int applePrice, int numOfApples, int money);
        int sellApple(int income);
        void showSalesResult() const;
};

class FruitBuyer{
    private:
        int money;
        int numOfApples;

    public:
        FruitBuyer(int money, int numOfApples = 0);
        bool buyApple(FruitSeller &seller, int outcome);
        void showBuyResult() const;
};

FruitSeller::FruitSeller(int applePrice, int numOfApples, int money) : APPLE_PRICE(applePrice), numOfApples(numOfApples), money(money){}

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

FruitBuyer::FruitBuyer(int money, int numOfApples){
    this->money = money;
    this->numOfApples = numOfApples;
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
    FruitSeller seller(1000, 30, 0);
    FruitBuyer buyer(10000);

    buyer.buyApple(seller, 2000);

    seller.showSalesResult();
    buyer.showBuyResult();

    return 0;
}