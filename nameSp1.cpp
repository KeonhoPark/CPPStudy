#include <iostream>
#include <cstring>
using namespace std;

namespace BestComImpl{
	void simpleFunc(void);
}

namespace ProgComImpl{
	void simpleFunc(void);
}

int main(int argc, char** argv) {
	
	BestComImpl::simpleFunc();
	ProgComImpl::simpleFunc();
	
	return 0;
}

void BestComImpl::simpleFunc(){
    cout << "bestComImpl" << endl;
}

void ProgComImpl::simpleFunc(){
    cout << "progComImpl" << endl;
}

