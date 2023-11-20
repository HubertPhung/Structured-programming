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
double TimMax(double x, double y);
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

double TimMax(double x, double y) {
	return x < y ? y : x;
}
double TimMax4(double a, double b, double c, double d) {
	return TimMax(TimMax(a, b), TimMax(c, d));
}