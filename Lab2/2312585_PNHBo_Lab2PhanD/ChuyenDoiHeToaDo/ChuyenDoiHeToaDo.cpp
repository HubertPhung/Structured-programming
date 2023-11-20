/*================================
1. Nap thu vien
==================================*/
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/


/*=========================================
3. Khai bao nguyen mau ham
===========================================*/
double TinhDoCao(double phi, double delta, double h);
double TinhPhuongVi(double phi, double delta, double h, double altitude);
/*=========================================
4. Ham main
===========================================*/
int main()
{
	int phi, delta, h, altitude;
	cout << "Nhap vi do = "; cin >> phi;
	cout << "\nNhap xich vi do = "; cin >> delta;
	cout << "\nNhap goc cua mui gio = "; cin >> h;
	cout << "\nDo cao cua he toa do la : "<< TinhDoCao(phi, delta, h) ;
	altitude = TinhDoCao(phi, delta, h);
	cout << "\nPhuong vi cua he toa do la : " << TinhPhuongVi( phi, delta, h, altitude);
	return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/

double TinhDoCao(double phi, double delta, double h)
{
	double TinhDoCao;
	TinhDoCao = asin(sin(phi) * sin(delta) + cos(phi) * cos(delta) * cos(h));
	return TinhDoCao;
}
double TinhPhuongVi(double phi, double delta, double h, double altitude)
{
	double TinhPhuongVi;
	TinhPhuongVi = acos((cos(phi) * sin(delta) - sin(phi) * cos(delta)* cos(h)) / cos(altitude)));
	return TinhPhuongVi;
}
