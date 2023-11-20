/*================================
1. Nap thu vien
==================================*/
#include<iostream>
#include<conio.h>
using namespace std;
/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/


/*=========================================
3. Khai bao nguyen mau ham
===========================================*/
double DoLanhCuaGio(double t, double v);


/*=========================================
4. Ham main
===========================================*/
int main()
{
	int t, v;
	cout << "Nhap nhiet do : "; cin >> t;
	cout << "\nNhap van toc gio :"; cin >> v;
	if (-50 <= t <= 50 && 3 <= v <= 120)
	{
		double w = DoLanhCuaGio(t, v);
		cout << "\nDo lanh cua gio la: " << w << " F";
	}
	else {
		cout << "Gia tri khong thoa man dieu kien.";
	}
	return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/
/*
* t la nhiet do (F)
* v la van toc gio (dam/gio)
* w la nhiet do hieu dung
*/

double DoLanhCuaGio(double t, double v)
{
	double w;
	w = 35.74 + 0.6215 * t + (0.4275 * t - 35.75) * pow(v, 0.16);
	return w;
}