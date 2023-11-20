/*================================
1. Nap thu vien
==================================*/
#include<iostream>
#include<conio.h>
using namespace std;
/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/
#define PI 3.1415926


/*=========================================
3. Khai bao nguyen mau ham
===========================================*/
double TheTich(double r, double h);
double DienTichXQ(double r, double h);
double DienTichTP(double r, double h);
double TinhChuViHinhTron(double r);
double TinhDienTichHinhTron(double r);



/*=========================================
4. Ham main
===========================================*/
int main()
{
	int r, h;
	cout << "Nhap ban kinh R: "; cin >> r;
	cout << "\nNhap chieu cao h: "; cin >> h;
	cout << "\nDien tich hinh tron la: "<< TinhDienTichHinhTron(r);
	cout << "\nChu vi hinh tron la: "<< TinhChuViHinhTron(r);
	cout << "\nDien tich xung quanh la: " << DienTichXQ(r, h);
	cout << "\nDien tich toan phan: " << DienTichTP(r, h);
	cout << "\nThe tich cua hinh tru tron la: " << TheTich(r, h);
	_getch();
	return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/
double TheTich(double r, double h)
{
	double v;
	v = 4 * PI * r * r * h;
	return v;
}
double DienTichXQ(double r, double h)
{
	double sxq;
	sxq= 2 * PI * r * h;
	return sxq;
}
double DienTichTP(double r, double h)
{
	double stp;
	stp = 2 * PI * r * h + 2 * PI * r * r;
	return stp;
}
double TinhChuViHinhTron(double r)
{
	double cv;
	cv = (r * 2) * PI;
	return cv;
}
double TinhDienTichHinhTron(double r)
{
	double s;
	s = PI * r * r;
	return s;
}