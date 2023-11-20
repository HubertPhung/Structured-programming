/*================================
1. Nap thu vien
==================================*/
#include <iostream>
using namespace std;

/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/

/*=========================================
3. Khai bao nguyen mau ham
===========================================*/
double TimMax4(double a, double b, double c, double d);

/*=========================================
4. Ham main
===========================================*/

int main() {
	double a, b, c, d;
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
	cout << "Nhap c: ";
	cin >> c;
	cout << "Nhap d: ";
	cin >> d;

	cout << "So lon nhat trong 4 so: " << TimMax4(a, b, c, d);


	return 0;
}

/*=========================================
5. Dinh nghia ham
===========================================*/


double TimMax4(double a, double b, double c, double d) {
	double x = a < b ? b : a;
	double y = c < d ? d : c;
	return x < y ? y : x;
}