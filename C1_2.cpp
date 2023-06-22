#include<iostream>

void myFunc(void){
	std::cout<<"myFunc(void)"<<std::endl;
}

void myFunc(int a){
	std::cout<<"myFunc2(int)"<<std::endl;
}

int main(){
	myFunc();
	myFunc(1);
	return 0;
}