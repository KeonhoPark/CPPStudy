#include<iostream>
using namespace std;

int adder(const int& a, const int& b){
	return a + b;
}

int main(){
	
	int answer = adder(10, 20);
	cout<<answer<<endl;
	
	return 0;
}