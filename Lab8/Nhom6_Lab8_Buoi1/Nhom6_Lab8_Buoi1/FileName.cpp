#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main() {
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh() {
	int menu, soMenu = 6, n = 5;
	DSThueBao dstb = {
		{100579, "Nguyen Quoc Binh","Da Lat","051.3432157",{1,3,2007}},
		{100821, "Tran Dinh Quy","Da Lat","051.2650120",{1,5,2010}},
		{100720, "Phan Duc Hai","Di Linh","045.0364722",{1,1,2006}},
		{100521, "Le Van A","Don Duong","049.141213",{1,5,2004}},
		{100301, "Le Minh Duy","Da Lat","051.2052157",{1,3,2017}},
		{100345, "Pham Cao Thanh","Di Linh","045.0156573",{12,3,2014}},
		{100301, "Nguyen minh Quan","Thai Nguyen","051.3420355",{23,11,2021}},
		{100345, "Pham Duc Duy","Duc Trong","055.5694157",{12,12,2015}},
	};


	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dstb, n);
	} while (menu > 0);
}