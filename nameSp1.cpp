#include <iostream>
#include <cstring>
using namespace std;

namespace BestComImpl{
	void simpleFunc(void){
		cout << "bestComImpl" << endl;
	}
}

namespace ProgComImpl{
	void simpleFunc(void){
		cout << "progComImpl" << endl;
	}
}

int main(int argc, char** argv) {
	
	BestComImpl::simpleFunc();
	ProgComImpl::simpleFunc();
	
	return 0;
}