#include<iostream>
using namespace std;

namespace parent{
    namespace child{
            
        void print();
    }
}

int main(){
    parent::child::print();
    return 0;
}

void parent::child::print(){
    cout << "parent child" << endl;
}