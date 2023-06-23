#import <iostream>
#import <cstring>
using namespace std;
enum{CREATE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct 
{
   int accountId;
   char customerName[10];
   int balance;
} account;

void makeAccount();
void deposit();
void withdraw();
void showAllAccInfo();

account accounts[100];
int accIndex = 0;

int main(){
    int select = 0;
    while(1){
        cout << "------Menu------" << endl;
        cout << "1. 계좌개설" << endl;
        cout << "2. 입금" << endl;
        cout << "3. 출금" << endl;
        cout << "4. 계좌정보 전체 출력" << endl;
        cout << "5. 프로그램 종료" << endl;
        cout << "선택 : "; cin >> select;

        switch (select)
        {
            case CREATE:
                makeAccount();
                break;
            case DEPOSIT:
                deposit();
                break;
            case WITHDRAW:
                withdraw();
                break;
            case INQUIRE:
                showAllAccInfo();
                break;
            default:
                exit(1);
                break;
        }
    }
}

void makeAccount(){
    char name[10];
    int accountId;
    int balance;

    cout << "계좌 ID 입력: ";
    cin >> accountId;
    cout << "고객 이름 입력: ";
    cin >> name;
    cout << "입금액 입력: ";
    cin >> balance;

    account newAccount;
    newAccount.accountId = accountId;
    strcpy(newAccount.customerName, name);
    newAccount.balance = balance;
    *(accounts + accIndex) = newAccount;
    accIndex ++;
}

void showAllAccInfo(){
    for(int i = 0; i < accIndex; i++){
        cout << "계좌번호 : " << (accounts + i)->accountId <<endl;
        cout << "고객이름 : " << (accounts + i)->customerName <<endl;
        cout << "계좌잔고 : " << (accounts + i)->balance <<endl;
        cout << endl;
    }
}

void deposit(){
    int accountId;
    int money;
    int flag = 0;

    cout << "계좌ID 입력 : "; cin >> accountId;
    cout << "맡길 금액 입력 : "; cin >> money;

    for(int i = 0; i < accIndex; i++){
        if((accounts + i) -> accountId == accountId){
            flag = 1;
            (accounts + i) -> balance += money;
            cout << "잔고 : " << (accounts + i) -> balance << "원 입니다." << endl;
            break;
        }
    }

    if(flag == 0){
        cout << "없는 계좌ID 입니다." << endl;
    }
}

void withdraw() {
    int accountId;
    int money;
    int flag = 0;

    cout << "계좌ID 입력 : "; cin >> accountId;
    cout << "인출할 금액 입력 : "; cin >> money;

    for(int i = 0; i < accIndex; i++){
        if((accounts + i) -> accountId == accountId) {
            flag = 1;
            (accounts + i) -> balance -= money;
            cout << "잔고 : " << (accounts + i) -> balance << "원 입니다." << endl;
            break;
        }
    }

    if(flag == 0){
        cout << "없는 계좌ID 입니다." << endl;
    }
}
