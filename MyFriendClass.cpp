#include<iostream>
#include<cstring>
using namespace std;

class Girl;

class Boy{
    private:
        int height;
        friend Girl;

    public:
        Boy(int height) : height(height){};
        void showFriendInfo(Girl &frn);
};

class Girl{
    private:
        char phNum[20];
    public:
        Girl(char* num){
            strcpy(phNum, num);
        }
        void showFriendInfo(Boy &frn);
        friend Boy;
};

void Boy::showFriendInfo(Girl &frn){
    cout << "phone number : " << frn.phNum << endl;
}

void Girl::showFriendInfo(Boy &frn){
    cout << "height : " << frn.height << endl;
}

int main(){
    Boy b1(180);
    Girl g1("010-5033-1832");
    b1.showFriendInfo(g1);
    g1.showFriendInfo(b1);
    return 0;
}



