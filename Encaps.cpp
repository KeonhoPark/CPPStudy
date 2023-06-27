#include<iostream>
using namespace std;

class SinivelCap{
    public:
        void take() const{
            cout << "콧물이 납니다. " << endl;
        }
};

class SneezeCap{
    public:
        void take() const{
            cout << "재채기가 멎습니다. " << endl;
        }
};

class SnuffleCap{
    public:
        void take() const{
            cout << "코가 뻥 뚫립니다. " << endl;
        }
};

class Contac{
    private:
        SinivelCap sin;
        SneezeCap snz;
        SnuffleCap snf;

    public:
        void take() const{
            sin.take();
            snz.take();
            snf.take();
        }
};

class ColdPatient{
    public:
        void takeContac(const Contac &cap) const {cap.take();}
};

int main(){
    Contac ct;

    ColdPatient p;
    p.takeContac(ct);

    return 0;
}