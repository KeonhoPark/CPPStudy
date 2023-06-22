#pragma warning (disable : 4996)
#include<iostream>
using namespace std;
#include<string.h>
#include<windows.h>
#include<stdio.h>

#define POINTWORD_FILENAME "C:\\pointword.txt"
#define POINTWORD_CNT 5
#define INPUT_MAX_CNT 10
#define BLACK 0        
#define LIGHTGRAY 7   
#define LIGHTRED 12  

struct PointWord
{
	char word[80];
	bool status;
};

bool pointWordRead(PointWord (&)[POINTWORD_CNT]);
void textcolor(int , int );
void wordGame(PointWord (&)[POINTWORD_CNT]);
void pointWordDisplay(PointWord (&)[POINTWORD_CNT]);
void userWordDisplay(char (*)[80], int);
bool wordAgree(char (*)[80], int);
bool pointWordCheck(PointWord (&)[POINTWORD_CNT], char *);
bool isDuplicated(char (*)[80], int);

int main()
{
	struct PointWord pointW[POINTWORD_CNT];

	int res;

	res=pointWordRead(pointW);

	if(res==false)
	{
		cout << POINTWORD_FILENAME << " 파일 오픈 에러로 프로그램을 종료합니다.\n";
		return 0;
	}

//	pointWordDisplay(pointW);
	wordGame(pointW);  
	
	

	return 0;
}

bool pointWordRead(struct PointWord (&pointW)[POINTWORD_CNT])
{
	FILE *fp;
	int i;

	fp = fopen(POINTWORD_FILENAME, "rt");
	if(fp==NULL)
	{
		return false;
	}
	for(i=0; i<POINTWORD_CNT; i++)
	{
		fgets(pointW[i].word, sizeof(pointW[0].word), fp);
		pointW[i].word[strlen(pointW[i].word)-1] = NULL; 
		pointW[i].status = false;
	}
	fclose(fp); 
	return true;  
}

/*------------------------------------------------------------------------------
  중복제거 함수
-------------------------------------------------------------------------------*/
bool isDuplicated(char (*userWord)[80], int inCnt){
	for(int i = 0; i < inCnt; i++){
		if(strcmp(*(userWord + inCnt), *(userWord + i)) == 0){
			return true;
		}
	}
	return false;
}

/*------------------------------------------------------------------------------
  끝말잇기 게임 처리 함수
-------------------------------------------------------------------------------*/
void wordGame(struct PointWord (&pointW)[POINTWORD_CNT]){
	cout <<"**끝말잇기 게임을 시작합니다**" << endl;
	cout <<"* 포인트단어 : ";
	pointWordDisplay(pointW);
	char userWord[INPUT_MAX_CNT+1][80] = {"pointer",};
	int score = 0;
	int count = 1;
	int wordCount = 0;
	
	cout << "사용자 입력 단어 : ";
	userWordDisplay(userWord, wordCount);
	cout << endl;
	
	while(count <= INPUT_MAX_CNT){
		wordCount++;
		char input[80] = {' '};
		cout << "끝말잇기 단어 입력(" << count << "회차) : " ;
		cin >> input;
		for(int i = 0; i < 80; i++){
			if(input[i] >= 'A' && input[i] <= 'Z'){
				//대소문자 구분 없애기
				input[i] += 32;
			}
			userWord[wordCount][i] = input[i];
		}
		
		if(wordAgree(userWord, wordCount) == false || isDuplicated(userWord, wordCount) == true){
			cout << "잘못 입력하셨습니다." << endl; 
			wordCount--;
		}
		else if(wordAgree(userWord, wordCount) == true && pointWordCheck(pointW, input) == false){
			pointWordDisplay(pointW);
			cout << "사용자 입력 단어 : ";
			for(int i=0; i <= wordCount; i++){
				userWordDisplay(userWord, i);
			}
			cout << endl;
			count++;
		}
		else if(wordAgree(userWord, wordCount) == true && pointWordCheck(pointW, input) == true){
			pointWordDisplay(pointW);
			cout << "사용자 입력 단어 : ";
			for(int i=0; i <= wordCount; i++){
				userWordDisplay(userWord, i);
			}
			cout << endl;
			score++;
			count++;
		}
		
		if(score == POINTWORD_CNT){
			break;
		}
		
	}
	cout << "당신의 점수는 " << score * 20 << "점 입니다." << endl;
	
}
/*------------------------------------------------------------------------------
  사용자 입력 단어를 포인트단어와 비교하여 포인트단어를 맞췄으면 
  포인트단어의 상태정보를 true로 변경
  맞춘단어이면 true 리턴, 못맞춘 단어이면 false 리턴
-------------------------------------------------------------------------------*/	
bool pointWordCheck(struct PointWord (&pointW)[POINTWORD_CNT], char *userWord)
{
	for(int i=0; i < POINTWORD_CNT; i++){
		if(strcmp(pointW[i].word, userWord) == 0){
			pointW[i].status = true;
			return true;
		}
	}
	
	return false;
	
}
/*------------------------------------------------------------------------------
  입력단어 끝말잇기 여부 확인 
  제대로 이어진 단어이면 true 리턴 / 제대로 잇지 못한 단어이면 false 리턴
-------------------------------------------------------------------------------*/	
bool wordAgree(char (*userWord)[80], int inCnt){
	char last = ' ';
	char first = ' ';
	
	for(int i=0; i < 80; i++){
		if(*(*(userWord+inCnt-1) + i) == '\0'){
			last = *(*(userWord+inCnt-1) + (i-1));
			break;
		}
	}
	
	first = *(*(userWord + inCnt)+0);

	if(last == first){
		return true;
	}
	else {
		for(int i = 0; i < 80; i++){
			userWord[inCnt+1][i] = ' ';
		}
		return false;	
	}
	
}
/*------------------------------------------------------------------------------
  사용자 입력 단어 출력 
-------------------------------------------------------------------------------*/	
void userWordDisplay(char (*userWord)[80], int inCnt){
	cout << *(userWord + inCnt) << " / ";
}
/*------------------------------------------------------------------------------
  포인트단어 출력 함수
-------------------------------------------------------------------------------*/
void pointWordDisplay(struct PointWord (&pointW)[POINTWORD_CNT]){
	for(int i = 0; i < POINTWORD_CNT; i++){
		if(pointW[i].status == false){
			textcolor(LIGHTRED, BLACK);
			cout << pointW[i].word << " / ";
		}
		else if(pointW[i].status == true){
			textcolor(LIGHTGRAY, BLACK);
			cout << pointW[i].word << " / ";
		}
		textcolor(LIGHTGRAY, BLACK);
	}
	cout << endl;
}
/*------------------------------------------------------------------------------
  문자 칼라 조정 함수
  (전달인자 의미) foreground - 문자색, background - 배경색
-------------------------------------------------------------------------------*/
void textcolor(int foreground, int background) 
{ 
    int color=foreground+background*16; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}