#include"RacingCar.h"
#include<iostream>
#include<cstring>

void RacingCar::initMembers(char* ID, int fuel, int speed){
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = speed;
}

void RacingCar::showCarState(){
    cout << "gamerID : " << gamerID << endl;
    cout << "fuelGauge : " << fuelGauge << endl;
    cout << "curSpeed : " << curSpeed << endl;
    }

void RacingCar::accel(){
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

void RacingCar::Break(){
    if(curSpeed < CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    } 

    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(){

    RacingCar lambo;
    lambo.initMembers("lambo", 100, 0);
    lambo.showCarState();
    lambo.accel();
    lambo.accel();
    lambo.showCarState();
    lambo.Break();
    lambo.showCarState();
    lambo.Break();
    lambo.showCarState();

    RacingCar ferrari;
    ferrari.initMembers("ferrari", 70, 0);
    ferrari.showCarState();
    ferrari.accel();
    ferrari.accel();
    ferrari.accel();
    ferrari.showCarState();
    ferrari.Break();
    ferrari.showCarState();

    return 0;
}


