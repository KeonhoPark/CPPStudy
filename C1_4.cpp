#include<iostream>
using namespace std;

namespace c1{
	void func(void);
}

namespace c2{
	void func(void);
}

void c1::func(void){
	cout << "c1" << endl;
}

void c2::func(void){
	cout << "c2" << endl;
}

int main(void){
	c1::func();
	c2::func();
}