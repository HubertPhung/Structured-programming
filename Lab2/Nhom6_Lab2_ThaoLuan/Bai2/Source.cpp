/*================================
1. Nap thu vien
==================================*/
#include <iostream>
using namespace std;

/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/

/*=========================================
/*=========================================
3. Khai bao nguyen mau ham
===========================================*/
double Kelvin(double t);
double Fahrenheit(double t);
double Rankine(double t);
/*=========================================
4. Ham main
===========================================*/

int main() {
	double t;
	cout << "Nhap nhiet do(t): ";
	cin >> t;
	cout << "Chuyen qua do F " << Fahrenheit(t) << endl;
	cout << "Chuyen qua do K " << Kelvin(t) << endl;
	cout << "Chuyen qua do R " << Rankine(t);
	return 0;
}

/*=========================================
5. Dinh nghia ham
===========================================*/
double Kelvin(double t) {
	return t + 273.15;
}

double Fahrenheit(double t) {
	return (double)t * 9 / 5 + 32;
}

double Rankine(double t) {
	return (t + 273.15) * 9 / 5;
}
