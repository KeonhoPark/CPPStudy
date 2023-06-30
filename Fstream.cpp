#include<fstream>
#include<iostream>
#include<ioManip>
using namespace std;

int main(){
    ofstream ofile("test.txt", ios::out|ios::app);
    if(ofile.is_open() == false){
        cout << "파일 읽기 실패" << endl;
    }
    ofile << "hello" << endl;
    ofile << 123 << setw(10) << 123 << endl;

    ofstream ofile2("test2.txt");
    if(ofile2.is_open() == false){
        cout << "파일 읽기 실패" << endl;
    }
    ofile2 << "world" << endl;
    ofile2 << 123 << setw(10) << 123 << endl;

    ifstream infile("test2.txt");
    if(infile.is_open() != false){
        cout << "file open fail!" << endl;
    }

    char ch;
    while(!infile.eof()){
        infile >> ch;
        cout << ch << endl;
    }

    char word[100];
    infile.clear();
    infile.seekg(0, ios::beg);
    while(!infile.eof()){
        infile >> word;
        cout << word << endl;
    }

    char line[1000];
    infile.clear();
    infile.seekg(0, ios::beg);
    int count = 0;
    cout.fill(' ');
    while(!infile.eof()){
        infile.getline(line, 256);
        cout << setw(3) << left << ++count << line << endl;
    }
    infile.close();
}