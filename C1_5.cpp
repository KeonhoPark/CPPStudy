#include<iostream>
using namespace std;

namespace Hybrid{
	void hybFunc(void){
		cout << "so simple func" << std::endl;
		std::cout << "hyb func" << std::endl;
	}
}

int main(){
	using namespace Hybrid;
	hybFunc();
	Hybrid::hybFunc();
	return 0;
}
