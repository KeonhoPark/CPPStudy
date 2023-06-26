#include<iostream>
#include "LightAutomation.h"
#include "LightAutomation.cpp"
using namespace std;

int menu(char **menuList, int menuCnt); // 전달된 메뉴를 출력하고 정확한 메뉴번호를 리턴하는 함수
void displayTitle(string title); // 처리중인 내용 출력하기 위한 타이틀 출력함수 
void screen(LightAutomation &rHa); // 주메뉴를 출력하고 메뉴를 선택받아 반복적으로 주메뉴를 처리하는 함수
void listDisplayAlliance(LightAutomation &r); // 등록된 전등의 상태출력
void controlAlliance(LightAutomation &r); // 등록된 전등 제어하기
void addAlliance(LightAutomation &r); // 전등 등록(동일한 
void deleteAlliance(LightAutomation &r); // 전등 삭제


int main()
{
	LightAutomation homeAuto;
	homeAuto.LightAutomation::initLightAutomation();
	screen(homeAuto);
	return 0;
}

void screen(LightAutomation &r)
{
	char *menuList[]={"전등 상태확인 ", "전등 제어 ", "전등 등록 ", "전등 삭제 ", "종료 "};
	int menuCnt = sizeof(menuList)/sizeof(menuList[0]);
	int menuNum;

	displayTitle("홈 조명 케어시스템 시작");
	while(true)
	{
		menuNum = menu(menuList, menuCnt);
		if(menuNum==menuCnt) {break;}
		switch(menuNum)
		{
		case 1 : listDisplayAlliance(r); break;
		case 2 : controlAlliance(r); break;
		case 3 : addAlliance(r); break;
		case 4 : deleteAlliance(r); break;
		default : break;
		}
	}
	displayTitle("홈 조명 케어시스템 종료");
	return;
}

void listDisplayAlliance(LightAutomation &r) // 등록된 전등의 상태출력
{
	displayTitle("전등 상태 보기");
	r.listDisplayAlliance();
	displayTitle("전등 상태 보기 종료");
}

void controlAlliance(LightAutomation &r) // 등록된 전등 제어하기
{
	string curName = "";
	displayTitle("전등 제어 하기");
	cout << "* 제어할 전등명 입력 : "; cin >> curName;
	if(r.controlAlliance(curName)){
		cout << "전등명 : " << curName << "의 제어가 완료되었습니다." << endl;
	}
	else{
		cout << "** 해당하는 제품이 존재하지 않거나 입력값이 없습니다." << endl;
		cout << "전등명 : " << curName << "의 제어가 실패하였습니다." << endl;
	}

	
}
void addAlliance(LightAutomation &r) // 전등 등록. 동일한 이름의 전등객체는 등록되지 않도록 함
{
	displayTitle("전등 등록 하기");
	string curName = "";
	cout << "* 제품명 입력( 예)거실전등, 안방등 등) :"; cin >> curName;
	LightFixture* newLightFixture = new LightFixture;
	newLightFixture->initLightFixture(curName);
	if(r.addAlliance(*newLightFixture) == true){
		cout << "전등명 : " << curName << "의 등록이 완료되었습니다." << endl;
	}
	else{
		cout << "전등명 : " << curName << "의 등록을 실패하였습니다." << endl;
	}
}
void deleteAlliance(LightAutomation &r) // 전등 삭제
{
	displayTitle("전등 삭제 하기");
	string curName = "";
	cout << "* 제품명 입력( 예)거실전등, 안방등 등) :"; cin >> curName;
	if(r.deleteAlliance(curName) == true){
		cout << "전등명 : " << curName << "의 삭제가 완료되었습니다." << endl;
	}
	else{
		cout << "** 해당하는 제품이 존재하지 않거나 입력값이 없습니다." << endl;
		cout << "전등명 : " << curName << "의 삭제를 실패하였습니다." << endl;
	}

}

int menu(char **menuList, int menuCnt)
{
	int menuSelect = 0;
	cout << "=======================================" << endl;
	for(int i = 0; i < menuCnt; i++){
		cout << i+1 << ". " << *(menuList + i) << endl;
	}
	cout << "=======================================" << endl;
	cout << "# 메뉴번호를 입력하세요 : "; cin >> menuSelect;
	return menuSelect;
}   

void displayTitle(string title) // 화면 타이틀 출력 함수
{
	cout << endl << "------------------------------" << endl;
	cout << "    " << title << endl;
	cout << "------------------------------" <<endl;
}