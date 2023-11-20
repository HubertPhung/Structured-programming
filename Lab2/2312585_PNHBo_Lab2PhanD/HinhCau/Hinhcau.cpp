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

double TheTichKC(double r);
double DienTichMC(double r);

/*=========================================
4. Ham main
===========================================*/
int main()
{
	int r;
	cout << "Nhap ban kinh hinh cau R: "; cin >> r;
	cout << "\nThe tich khoi cau la: " << TheTichKC(r);
	cout << "\nDien tich mat cau: " << DienTichMC(r);

	_getch();
	return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/

double TheTichKC(double r) // The tich khoi cau
{
	double v;
	v = 4 / 3 * PI * r * r * r;
	return v;
}
double DienTichMC(double r) // Dien tich mat cau
{
	double s;
	s = 4 * PI * r * r;
	return s;
}