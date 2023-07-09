#include<iostream>
using namespace std;

class SelfRef{
    private:
        int num;
    public:
        SelfRef(int n) : num(n){
            cout << "객체 생성" << endl;
        }

        SelfRef& adder(int n){
            num += n;
            return *this;
        }

        SelfRef& showTwoNumber(){
            cout << num << endl;
            return *this;
        }

        friend ostream& operator<<(ostream& out, const SelfRef &ref){
            out << "number : " << ref.num << endl;
            return out;
        }
};

int main(){
    SelfRef obj(3);
    SelfRef ref = obj.adder(2);
    cout << ref << endl;

    obj.showTwoNumber();
    ref.showTwoNumber();

    ref.adder(1).showTwoNumber().adder(3).showTwoNumber();
    return 0;
}