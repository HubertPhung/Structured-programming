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
double TinhKhoangCach(double xa, double ya, double xb, double yb);
/*=========================================
4. Ham main
===========================================*/
int main()
{
	//Nhap toa do 2 diem A B
	int xa, ya, xb, yb;
	cout << "\nNhap toa do diem A = "; cin >> xa; cout << ":"; cin >> ya;
	cout << "\nNhap toa do diem B = "; cin >> xb; cout << ":"; cin >> yb;
	cout << "\nKhoang cach giua hai diem A va B bang = " << TinhKhoangCach(xa, ya, xb, yb);

}

/*=========================================
5. Dinh nghia ham
===========================================*/

double TinhKhoangCach(double xa, double ya, double xb, double yb)
{
	double d;
	d = sqrt((xa - xb) * (xa - xb) + (yb - ya) * (yb - ya));
	return d;
}