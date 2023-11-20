/*================================
1. Nap thu vien
==================================*/
#include<iostream>
#include<conio.h>
using namespace std;
/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/
#define PI 3.14


/*=========================================
3. Khai bao nguyen mau ham
===========================================*/
double TinhChiSoBMI(double w, double h);
/*=========================================
4. Ham main
===========================================*/
int main()
{
	/*
	* w la khoi kuong co the (kg)
	* h laf chieu cao (m)
	*/
	int w, h;
	cout << "Nhap khoi luong co the : "; cin >> w;
	cout << "\nNhap chieu cao con nguoi : "; cin >> h;
	cout << "\nChi so khoi co the cua ban la: " << TinhChiSoBMI(w, h);
	_getch();
	return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/

double TinhChiSoBMI(double w, double h)
{
	double BMI;
	BMI = w / h * h;
	return BMI;

}
