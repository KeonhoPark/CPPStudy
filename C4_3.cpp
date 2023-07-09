#include<iostream>
#include<cstring>
using namespace std;

typedef enum{CLERK=1, SENIOR, ASSIST, MANAGER} COMP_POS;

class NameCard{
    private:
        char* name;
        char* companyName;
        char* phoneNumber;
        int position;

    public:
        NameCard(char* name, char* companyName, char* phoneNumber, int position){
            int nameLen = strlen(name) + 1;
            int companyNameLen = strlen(companyName) + 1;
            int phoneNumberLen = strlen(phoneNumber) + 1;

            this->name = new char[nameLen];
            this->companyName = new char[companyNameLen];
            this->phoneNumber = new char[phoneNumberLen];

            strcpy(this->name, name);
            strcpy(this->companyName, companyName);
            strcpy(this->phoneNumber, phoneNumber);
            this->position = position;
        }

        NameCard(NameCard &ref) : position(ref.position){
            int nameLen = strlen(ref.name) + 1;
            int companyNameLen = strlen(ref.companyName) + 1;
            int phoneNumberLen = strlen(ref.phoneNumber) + 1;

            this->name = new char[nameLen];
            this->companyName = new char[companyNameLen];
            this->phoneNumber = new char[phoneNumberLen];

            strcpy(this->name, ref.name);
            strcpy(this->companyName, ref.companyName);
            strcpy(this->phoneNumber, ref.phoneNumber);
        }

        ~NameCard(){
            cout<<"called destructor"<<endl;
            delete []name;
            delete []companyName;
            delete []phoneNumber;
        }

        void showNameCardInfo(){
            cout<<"이름 : "<<this->name<<endl;
            cout<<"회사 : "<<this->companyName<<endl;
            cout<<"전화번호 : "<<this->phoneNumber<<endl;
            cout<<"직급 : ";

            switch(this->position){
                case(COMP_POS::CLERK):
                    cout<<"사원"<<endl;
                    break;
                case(COMP_POS::SENIOR):
                    cout<<"주임"<<endl;
                    break;
                case(COMP_POS::ASSIST):
                    cout<<"대리"<<endl;
                    break;
                case(COMP_POS::MANAGER):
                    cout<<"과장"<<endl;
                    break;
                default:
                    break;
            }

            cout<<endl;
        }
};

int main(){
    // NameCard manClerk("lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    // NameCard manSENIOR("park", "ORANGEENG", "010-3333-4444", COMP_POS::SENIOR);
    // NameCard manASSIST("kim", "SoGoodCOmp", "010-5555-6666", COMP_POS::ASSIST);
    // NameCard manMANAGER("hong", "DEFEng", "010-7777-8888", COMP_POS::MANAGER);

    // manClerk.showNameCardInfo();
    // manSENIOR.showNameCardInfo();
    // manASSIST.showNameCardInfo();
    // manMANAGER.showNameCardInfo();

    NameCard manClerk("lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard c1 = manClerk;
    NameCard manSENIOR("park", "ORANGEENG", "010-3333-4444", COMP_POS::SENIOR);
    NameCard c2 = manSENIOR;
    c1.showNameCardInfo();
    c2.showNameCardInfo();

    return 0;
}