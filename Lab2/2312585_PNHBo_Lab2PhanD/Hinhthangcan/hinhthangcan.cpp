// Khai bao thu vien
#include <iostream>
using namespace std;
#include <math.h>
// Khai bao nguyen mau
double TinhCanhBen(double a, double b, double h);
double TinhChuvi(double a, double b, double h);
double TinhDienTich(double a, double b, double h);
// Ham main
int main()
{
	int a, b, h;
	double canhBen, chuVi, dienTich;
	cout << "Nhap a: "; cin >> a;
	cout << "\nNhap b: "; cin >> b;
	cout << "\nNhap h: "; cin >> h;
	cout << "\nCanh ben cua hinh thang can la: " << TinhCanhBen(a, b, h);
	cout << "\nChu vi cua hinh thang can la: " << TinhChuvi(a, b, TinhCanhBen(a, b, h));
	cout << "\nDien tich cua hinh thang can la: " << TinhDienTich(a, b, h);
	return 1;
}

// Dinh nghia ham
double TinhCanhBen(double a, double b, double h)
{
	double canhBen;
	canhBen = sqrt(((a - b) / 2) * ((a - b) / 2) + (h * h));
	return canhBen;
}
double TinhChuvi(double a, double b, double h)
{
	double chuVi;
	chuVi = (a + b + 2) * TinhCanhBen(a, b, h);
	return chuVi;
}
double TinhDienTich(double a, double b, double h)
{
	double dienTich;
	dienTich = ((a + b) * h) / 2;
	return dienTich;
}