#ifndef __RACINGCAR_H__
#define __RACINGCAR_H__
#include<iostream>
#include<cstring>
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

class RacingCar 
{

    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    public:
        void initMembers(char* ID, int fuelGauge, int curSpeed);
        void showCarState();
        void accel();
        void Break();
};
#endif