#include <iostream>
using namespace std;

int boxVolume(int len, int w, int h);
int boxVolume(int len, int w);
int boxVolume(int len);
int boxVolume();

int main(){
    cout << "[3, 3, 3]" << boxVolume(3, 3, 3) << endl;
    cout << "[5, 5, D]" << boxVolume(5, 5) << endl;
    cout << "[7, D, D]" << boxVolume(7) << endl;
    cout << "[D, D, D]" << boxVolume() << endl;

    return 0;
}

int boxVolume(int len, int w, int h){
    return len * w * h;
}

int boxVolume(int len, int w){
    return len * w * 5;
}

int boxVolume(int len){
    return len * 5 * 5;
}

int boxVolume(){
    return 5 * 5 * 5;
}

