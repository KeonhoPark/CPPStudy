#include "HomeAutomation.h"
#include "Appliance.h"
#include "RiceCooker.h"
#include<iostream>
#include<string>
using namespace std;

int menu(char **menuList, int menuCnt); // 전달된 메뉴를 출력하고 정확한 메뉴번호를 리턴하는 함수
int controlMenuSelect(string message, int menuCnt); // 가전제품의 상태변경 처리를 위한 메뉴 함수
void displayTitle(string title); // 처리중인 내용 출력하기 위한 타이틀 출력함수 
void screen(HomeAutomation &rHa); // 주메뉴를 출력하고 메뉴를 선택받아 반복적으로 주메뉴를 처리하는 함수
void listDisplayAppliance(HomeAutomation &rHa); // 등록된 가전제품의 상태출력
void controlAppliance(HomeAutomation &rHa); // 등록된 가전제품 제어하기
void addAppliance(HomeAutomation &rHa); // 가전제품 등록
void deleteAppliance(HomeAutomation &rHa); // 가전제품 삭제

int main()
{
	HomeAutomation homeAuto;
	screen(homeAuto);
	// 아래 코드는 화면에 수행되는 변화는 없으나 복사생성자와 대입연산자 함수를 테스트 하기 위한 코드입니다. 
	HomeAutomation temp1=homeAuto;  // 복사 생성자 테스트 코드
	HomeAutomation temp2;
	temp2 = temp1;  // 대입연산자 함수 테스트 코드 
	return 0;
}

void screen(HomeAutomation &rHa)
{
	char *menuList[]={"밥솥 상태확인 ", "밥솥 제어 ", "밥솥 등록 ", "밥솥 삭제 ", "종료 "};
	int menuCnt = sizeof(menuList)/sizeof(menuList[0]);
	int menuNum;

	displayTitle("홈 밥솥 케어시스템 시작");
	while(true)
	{
		menuNum = menu(menuList, menuCnt);
		if(menuNum==menuCnt) {break;}
		switch(menuNum)
		{
		case 1 : listDisplayAppliance(rHa); break;
		case 2 : controlAppliance(rHa); break;
		case 3 : addAppliance(rHa); break;
		case 4 : deleteAppliance(rHa); break;
		}
	}
	displayTitle("홈 밥솥 케어시스템 종료");
	return;
}

void listDisplayAppliance(HomeAutomation &rHa) // 등록된 가전제품의 상태출력
{
	displayTitle("밥솥 상태 보기");
	rHa.listDisplayAppliance();
	displayTitle("밥솥 상태 보기 종료");
}

void controlAppliance(HomeAutomation &rHa) // 등록된 가전제품 제어하기
{
	string input = "";
	cout << "* 제어할 제품명 입력 : "; cin >> input;
	displayTitle("밥솥 제어 하기");
	rHa.controlAppliance(input);
	
}

void addAppliance(HomeAutomation &rHa) // 가전제품을 목록에 추가. 동일한 제품명의 밥솥은 등록 불가
{
	displayTitle("밥솥 등록 하기");
	string input = "";
	cout << "* 제품명 입력( 예)큰밥솥, 1호밥솥 등) : "; cin >> input;
	RiceCooker* newCooker = new RiceCooker;
	newCooker->setMachineName(input);
	rHa.addAppliance(newCooker);
}

void deleteAppliance(HomeAutomation &rHa) // 밥솥 삭제
{
	displayTitle("밥솥 삭제 하기");
	string input = "";
	cout << "* 제품명 입력( 예)큰밥솥, 1호밥솥 등) : "; cin >> input;
	rHa.deleteAppliance(input);
}

int controlMenuSelect(string message, int menuCnt)
{
	int menuNum;

	while(true)
	{
		cout << message;
		cin >> menuNum;
		if(menuNum>0 && menuNum <= menuCnt){ break; }
	}
	return menuNum;
}

int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum=0; /* 입력된 메뉴 번호 저장 변수*/

	cout << endl << "==================================" << endl;
	for(i=0; i<menuCnt; i++)
	{
		cout << i+1 << "." << menuList[i] << endl;
	}
	cout << "==================================" << endl;
	while(menuNum<1 || menuNum>menuCnt)  /* 범위 내의 번호가 입력될 때 까지 반복*/
	{
		cout <<"# 메뉴번호를 입력하세요 : ";
		cin >> menuNum;
	}
	return menuNum;
} 

void displayTitle(string title) // 화면 타이틀 출력 함수
{
	cout << endl << "------------------------------" << endl;
	cout << "    " << title << endl;
	cout << "------------------------------" <<endl;
}
