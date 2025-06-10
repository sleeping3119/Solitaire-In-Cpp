#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
//#include <conio.h>
#include <windows.h>


using namespace std;
typedef unsigned short us;
typedef unsigned int ui;

enum type { heart, diamond, club, spade };
enum colour { red, black };

class card {
	colour clr; type typ; us nmbr; char ch;
public:
	card() {
		clr=red; typ=heart; nmbr=0; ch=0;
	}
	char getCh() {
		return ch;
	}
	card(type _typ,us _nmbr,char _ch=0) :typ(_typ),nmbr(_nmbr),ch(_ch){
		clr = (_typ > 1) ? black : red;
		switch (nmbr)
		{
			case 1:  ch = 'A';break;
			case 11: ch = 'J';break;
			case 12: ch = 'Q'; break;
			case 13: ch = 'K'; break;
		} 
	}
	static vector<card> shuf(vector<card> arr) {
		srand(ui(time(0)));
		for (int i = int(arr.size()) - 1; i >= 0; i--) {
			int j = std::rand() % (i + 1);
			swap(arr[i], arr[j]);
		}
		return arr;
	}
	static vector<card> load() {
		vector<card> ptr(52);
		ifstream rdr("start.txt");
		int t, n;
		for (int i = 0; i < 52; i++)
		{
			rdr >> t >> n;
			ptr[i] = card(type(t), n);
		}
		return ptr;
	}
	friend ostream& operator<<(ostream&, const card&);
	int getNmbr() {
		return this->nmbr;
	}
	int getClr() {
		return this->clr;
	}
};
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void getCurrentCursorPosition(int& rpos, int& cpos) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	if (GetConsoleScreenBufferInfo(hOutput, &csbi)) {
		rpos = csbi.dwCursorPosition.Y;
		cpos = csbi.dwCursorPosition.X;
	}
	else {
		rpos = -1;  
		cpos = -1;
	}
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
