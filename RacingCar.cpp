#include<iostream>
using namespace std;

namespace CAR_CONST{
    enum{
        ID_LEN =20,
        MAX_SPEED =200,
        FUEL_STEP =2,
        ACC_STEP =10,
        BRK_STEP =10,
    };
}

struct Car 
{

    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    void showCarState();
    void accel();
    void Break();
};

void Car::showCarState(){
    cout << "gamerID : " << gamerID << endl;
    cout << "fuelGauge : " << fuelGauge << endl;
    cout << "curSpeed : " << curSpeed << endl;
    }

void Car::accel(){
    if(fuelGauge <= 0){
        return;
    }

    fuelGauge -= CAR_CONST::FUEL_STEP;

    if(curSpeed += CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPEED){
        curSpeed = CAR_CONST::MAX_SPEED;
        return;
    }

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break(){
    if(curSpeed < CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    } 

    curSpeed -= CAR_CONST::BRK_STEP;
}

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


