#include<iostream>
using namespace std;

#define SQUARE(x) ((x) * (x))

int adder(int n1 = 1, int n2 = 3){
	return n1 + n2;
}

int main(){
	std::cout<<SQUARE(3)<<endl;
	std::cout<<SQUARE(1.3)<<endl;
//	std::cout<<adder(5, 7)<<endl;

	return 0;
}