#include<iostream>
#include<string.h>
using namespace std;
#define ID_LEN 10

struct Car{
	char gamerId[ID_LEN];
	int fuelGauge;
	int curSpeed;
	
	void showCarState(){
		cout << "소유자 ID : " << gamerId << endl;
		cout << "기 : " << fuelGauge << endl;
		cout << "현재 속도  : " << curSpeed << endl; 
	}
};

int main(){
	Car car1 = {"park", 10, 100};
	car1.showCarState();
	return 0;
}













