#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]){
    cout << "argc=" << argc << endl;
    for(int i = 0; i < argc; i++){
        cout << "argv[" << i << "] " << argv[i] << endl;
    }

    if(argc != 3){
        cout << "Usage:Copyfile file1 file2" << endl;
        return 0;
    }

    //파일 복사
    ifstream infile(argv[1], ios::in | ios::binary);
    ofstream outfile(argv[2], ios::out | ios::binary);
    if(!infile || !outfile){
        cout << "File Open Error" << endl;
        return 0;
    }

    char buf[100];
    int n;
    while(!infile.eof()){
        infile.read(buf, 100);
        n = infile.gcount(); // 실제 읽어드린 바이트 수
        outfile.write(buf, n);
    }
    infile.close();
    outfile.close();
    cout << "파일복사 완료";
    return 0;
}