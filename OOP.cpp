/*
 * Banking System Ver 0.1
 * 작성자: 윤성우
 * 내  용: OOP 단계별 프로젝트의 기본 틀 구성
 */

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account{
    private:
        int accID;
        int balance;
        char cusName[NAME_LEN];

    public:
        // Account(){};
        Account(int accID, int balance, char* name);
        int getAccID();
        int getBalance();
        char* getCusName();
        int setAccID(int accID);
        int setBalance(int balance);
        char* setCusName(char* name);
        void ShowMenu();       // 메뉴출력
        void DepositMoney();       // 입    금
        void WithdrawMoney();      // 출    금
        void ShowAllAccInfo();     // 잔액조회
};

Account::Account(int accID, int balance, char* name){
    this->accID = accID;
    this->balance = balance;
    strcpy(this->cusName, name);
}

int Account::getAccID(){
    return this -> accID;
}

int Account::getBalance(){
    return this->balance;
}

char* Account::getCusName(){
    return this->cusName;
}

int Account::setAccID(int accID){
    this->accID = accID;
    return this->accID;
}

int Account::setBalance(int balance){
    this->balance = balance;
    return this->balance;
}

char* Account::setCusName(char* name){
    strcpy(this->cusName, name);
    return this->cusName;
}

void Account::ShowMenu(void){
    cout<<"-----Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입    금"<<endl;
	cout<<"3. 출    금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}   

void Account::DepositMoney(void){
    int money;
    int balance = this->getBalance();
	cout<<"[입    금]"<<endl;
	cout<<"입금액: ";	cin>>money;

    this->setBalance(balance + money);

    cout<<this->getAccID()<<"계좌잔액 : "<<this->getBalance()<<endl;
}     // 입    금

void Account::WithdrawMoney(void){
    int money;
    int balance = this->getBalance();
	cout<<"[출    금]"<<endl;
	cout<<"출금액: ";	cin>>money;

    this->setBalance(balance - money);

    cout<<this->getAccID()<<"계좌잔액 : "<<this->getBalance()<<endl;
}     // 출    금

void Account::ShowAllAccInfo(void){
    cout<<"계좌 소유자 : "<<this->getCusName()<<endl;
    cout<<this->getAccID()<<"계좌잔액 : "<<this->getBalance()<<endl;
}    // 잔액조회

int MakeAccount(){
    int id = 0;
    char* name = NULL;
    int balance = 0;

    cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	cout<<"이  름: ";	cin>>name;
	cout<<"입금액: ";	cin>>balance;
	cout<<endl;

    Account newAccount = Account(id, balance, name);
    accArr[accNum++] = &newAccount;
    return newAccount.getAccID();
}

Account* accArr[100];   // Account 저장을 위한 배열
int accNum=0;        // 저장된 Account 수   // 계좌개설을 위한 함수

int main(void){
	int choice;

	while(1)
	{
		cout<<"선택: "; 
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
		case MAKE:
			MakeAccount(); 
			break;
		case DEPOSIT:
			accArr[0]->DepositMoney(); 
			break;
		case WITHDRAW: 
			accArr[0]->WithdrawMoney(); 
			break;
		case INQUIRE:
			accArr[0]->ShowAllAccInfo(); 
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}
	return 0;
}
