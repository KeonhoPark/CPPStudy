#include <iostream>
using namespace std;

void swap(int* n1, int* n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swap(char* c1, char* c2){
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

void swap(double* d1, double* d2){
    double temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

int main(){
    int num1 = 10, num2 = 20;
    swap(&num1, &num2);
    cout << num1 << " " << num2 << endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    cout << ch1 << " " << ch2 << endl;

    double d1 = 1.1, d2 = 2.2;
    swap(&d1, &d2);
    cout << d1 << " " << d2 << endl;

    return 0;
}