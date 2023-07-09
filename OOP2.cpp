#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);       // 메뉴출력
void MakeAccount(void);    // 계좌개설을 위한 함수
void DepositMoney(void);       // 입    금
void WithdrawMoney(void);      // 출    금
void ShowAllAccInfo(void);     // 잔액조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account{
    private:
        int accID;      // 계좌번호
        int balance;    // 잔    액
        char* cusName;   // 고객이름

    public:
        Account(){
            this->accID = 0;
            this->balance = 0;
            cusName = nullptr;
        }

        Account(int ID, int bal, char* cusName) : accID(ID), balance(bal){
            int len = strlen(cusName);
            this->cusName = new char[len + 1];
            strcpy(this->cusName, cusName);
        }

        ~Account(){
            cout << "called destructor" << this->cusName << endl;
            delete []cusName;
        }

        int getAccID() const{
            return this->accID;
        }

        void setAccID(int accID){
            this->accID = accID;
        }

        int getBalance() const{
            return this->balance;
        }

        void setBalance(int balance){
            this->balance = balance;
        }

        char* getCusName() const{
            return this->cusName;
        }

        void setCusName(char* cusName){
            int len = strlen(cusName) + 1;
            if(this->cusName == nullptr){
                this->cusName = new char[len];
                strcpy(this->cusName, cusName);
            }
            else{
                delete []this->cusName;
                this->cusName = new char[len];
                strcpy(this->cusName, cusName);
            }
        }

};

Account* accArr[100];   // Account 저장을 위한 배열
int accNum=0;        // 저장된 Account 수

int main(void)
{
	int choice;
	
	while(1)
	{
		ShowMenu();
		cout<<"선택: "; 
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
		case MAKE:
			MakeAccount(); 
			break;
		case DEPOSIT:
			DepositMoney(); 
			break;
		case WITHDRAW: 
			WithdrawMoney(); 
			break;
		case INQUIRE:
			ShowAllAccInfo(); 
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout<<"-----Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입    금"<<endl;
	cout<<"3. 출    금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void MakeAccount(void) 
{
	int id;
	char name[NAME_LEN];
	int balance;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	cout<<"이  름: ";	cin>>name;
	cout<<"입금액: ";	cin>>balance;
	cout<<endl;

    //newAccount 객체가 현재 함수가 종료되면 소멸자가 호출되며 객체가 없어짐.
    //하지만 포인터 배열은 없어진 객체의 주소를 가리키고 있음
    //그 후에 newAccount를 호출하면 같은 자리에 newAccount 객체가 생성됨
    //따라서 이전의 포인터 배열 요소와 그 다음 포인터 배열 요소가 같은 방을 가리키게됨
    // Account newAccount(id, balance, name);
    // accArr[accNum] = &newAccount;
    accArr[accNum] = new Account(id, balance, name);
    for(int i = 0; i <= accNum; i++){
        cout<<accArr[i]<<endl;
        cout<<"계좌ID: "<<accArr[i]->getAccID()<<endl;
        cout<<"이  름: "<<accArr[i]->getCusName()<<endl;
        cout<<"잔  액: "<<accArr[i]->getBalance()<<endl<<endl;
    }
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;
	cout<<"[입    금]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	cout<<"입금액: ";	cin>>money;
	
	for(int i=0; i<accNum; i++)
	{
		if(accArr[i]->getAccID()==id)
		{
			accArr[i]->setBalance(accArr[i]->getBalance() + money);
			cout<<"입금완료"<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout<<"[출    금]"<<endl;
	cout<<"계좌ID: ";	cin>>id;
	cout<<"출금액: ";	cin>>money;
	
	for(int i=0; i<accNum; i++)
	{
		if(accArr[i]->getAccID()==id)
		{
            int balance = accArr[i]->getBalance();
			if(balance < money)
			{
				cout<<"잔액부족"<<endl<<endl;
				return;
			}

			accArr[i]->setBalance(balance - money);
			cout<<"출금완료"<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void ShowAllAccInfo(void)	
{
	for(int i=0; i<accNum; i++)
	{
		cout<<"계좌ID: "<<accArr[i]->getAccID()<<endl;
		cout<<"이  름: "<<accArr[i]->getCusName()<<endl;
		cout<<"잔  액: "<<accArr[i]->getBalance()<<endl<<endl;
	}
}