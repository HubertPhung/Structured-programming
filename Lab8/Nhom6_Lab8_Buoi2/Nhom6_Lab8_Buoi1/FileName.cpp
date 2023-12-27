#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <map>


using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main() {
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh() {
	int menu, soMenu = 9, n = 8;
	DSThueBao dstb = {
		{1000579, "Nguyen Quoc Binh","Da Lat","051.3432157",{1,3,2007}},
		{1000821, "Tran Dinh Quy","Da Lat","051.2650120",{1,5,2010}},
		{1000720, "Phan Duc Hai","Di Linh","045.0364722",{1,1,2006}},
		{1000521, "Le Van A","Don Duong","049.1412138",{1,5,2004}},
		{1000301, "Le Minh Duy","Da Lat","051.2052157",{1,3,2017}},
		{1000345, "Pham Cao Thanh","Di Linh","045.0156573",{12,3,2014}},
		{1000301, "Nguyen minh Quan","Thai Nguyen","051.3420355",{23,11,2021}},
		{1000345, "Pham Duc Duy","Duc Trong","055.5694157",{12,12,2015}},
	};


	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dstb, n);
	} while (menu > 0);
}