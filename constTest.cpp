#include <iostream>
using namespace std;

class EasyClass{
    private:
        int num;

    public:
        void init(int n){
            num = n;
        }

        int getNum() const{
            return num;
        }
};

class LiveClass{
    private:
        int num;
    
    public:
        void init(const EasyClass &ref){
            num = ref.getNum();
        }
};

int main(){
    return 0;
}