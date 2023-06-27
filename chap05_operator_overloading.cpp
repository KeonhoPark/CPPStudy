#include <iostream>
#include <cstdlib>

using namespace std;

class Data
{
public:
    Data() {
        x=0; y=0; 
    }
    Data(int i, int j) {
        x=i; y=j; 
    }
    void getData(int &i, int &j) {
        i=x; j=y;
    }
    Data operator+(const Data &obj);
    Data operator+(int);
    Data operator-(const Data &obj);
    Data operator=(const Data &obj);
    bool operator==(const Data &obj);
    Data operator++();
    void showData();
private:
	int x, y;
};

Data Data::operator+(const Data &obj){
    Data newData(x + obj.x, y + obj.y);
    return newData;
}

Data Data::operator+(int num){
    Data newData(x + num, y + num);
    return newData;
}

Data Data::operator-(const Data &obj){
    Data newData(x - obj.x, y - obj.y);
    return newData;
}

Data Data::operator=(const Data &obj){
    Data newData(obj.x, obj.y);
    return newData;
}

bool Data::operator==(const Data &obj){
    int x, y = 0;
    getData(x, y);
    if(x == obj.x && y == obj.y){
        return true;
    }
    else{
        return false;
    }
}

Data Data::operator++(){
    Data newData(x + 1, y + 1);
    return newData;
}

void Data::showData(){
    int x, y = 0;
    getData(x, y);
    cout << "x : " << x << "  y : " << y << endl;
}

int main(){
    Data d1(3, 5);
    Data d2(4, 6);
    d1.showData();
    d2.showData();
    Data dp1 = d1 + d2;
    dp1.showData();
    Data dm = d1 - d2;
    dm.showData();
    Data de = d1;
    de.showData();
    bool b = d1.operator==(d2);
    cout << b << endl;
    Data dpp = ++dpp;
    dpp.showData();

    return 0;
}



