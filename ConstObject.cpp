#include<iostream>
using namespace std;

class SoSimple{
    private:
        int num;
    
    public:
        SoSimple(int num) : num(num){};

        SoSimple& addNum(int num){
            this->num += num;
            return *this;
        }

        void showData() const{
            cout << "num : " << num << endl;
        }
};

int main(){
    const SoSimple s1(10);
    s1.addNum(3);
    s1.showData();
    return 0;
}