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
	int menu, soMenu = 9, n;
	DSThueBao dstb;
	NhapCoDinh(dstb, n);

	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dstb, n);
	} while (menu > 0);
}