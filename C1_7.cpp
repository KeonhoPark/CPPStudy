#include<iostream>
using namespace std;

void swapByRef(int &n1, int &n2){
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int main(){
	
	int n1 = 10;
	int n2 = 20;
	swapByRef(n1, n2);
	cout << "n1: "<<n1<<endl;
	cout << "n2: "<<n2<<endl;
	
	return 0;
}