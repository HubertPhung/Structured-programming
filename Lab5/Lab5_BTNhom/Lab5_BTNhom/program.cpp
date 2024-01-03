#include<iostream>
#include<conio.h>
using namespace std;
#include"ThuVien.h"
#include"Menu.h"
void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	_getch();
	return 0;
}

void ChayChuongTrinh()
{
	int n = 10, chon, somenu = 15;
	DaySo a = { 11, 20, 0, -9, 100, -1, -19, 50, 19, 700 };
	/*Sai --> vi sao?
	DaySo b;
	b= { 10, 20, 0, -9, 100, -1, -19, 50, 19, 7 };
	*/

	/*cout << "\nNhap n=";
	cin >> n;
	NhapMang(a, n);*/
	do {
		system("cls");
		cout << "\nMang vua nhap:";
		XuatMang(a, n);
		XuatMenu();
		chon = ChonMenu(somenu);
		XuLyMenu(chon, a, n);
	} while (chon != THOAT);
}