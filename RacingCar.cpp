#include<iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPEED 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car 
{
    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;

    void showCarState(){
    cout << "gamerID : " << gamerID << endl;
    cout << "fuelGauge : " << fuelGauge << endl;
    cout << "curSpeed : " << curSpeed << endl;
    }

    void accel(){
        if(fuelGauge <= 0){
            return;
        }

        fuelGauge -= FUEL_STEP;

        if(curSpeed += ACC_STEP >= MAX_SPEED){
            curSpeed = MAX_SPEED;
            return;
        }

        curSpeed += ACC_STEP;
    }

    void Break(){
        if(curSpeed < BRK_STEP){
            curSpeed = 0;
            return;
        } 

        curSpeed -= BRK_STEP;
    }
};

int main(){

    Car lambo = {"lambo", 100, 0};
    lambo.showCarState();
    lambo.accel();
    lambo.accel();
    lambo.showCarState();
    lambo.Break();
    lambo.showCarState();
    lambo.Break();
    lambo.showCarState();

    Car ferrari = {"ferrari", 70, 0};
    ferrari.showCarState();
    ferrari.accel();
    ferrari.accel();
    ferrari.accel();
    ferrari.showCarState();
    ferrari.Break();
    ferrari.showCarState();

    return 0;
}


