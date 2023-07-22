#include<iostream>
using namespace std;

class Temp{
    private:
        int num;
    public:
        Temp(int num) : num(num){
            cout << "create Temp obj" << endl;
        };
        ~Temp(){
            cout << "destroy Temp obj" << endl;
        }
        void showData(){
            cout << "num : " << num << endl;
        }
};

int main(){
    Temp(100);
    cout << "===========after make============" << endl << endl;

    Temp(200).showData();
    cout << "===========after make============" << endl << endl;

    const Temp &t = Temp(300);
    cout << "===========end of main()==========" << endl << endl;
    return 0;
}