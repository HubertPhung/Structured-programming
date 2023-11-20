// khai bao thu vien
#include <iostream>
#define PI 3.14	
using namespace std;

// Khai bao nguyen mau
double TinhChuViHinhTron(double r);
double TinhDienTichHinhTron(double r);


// Ham main
int main()
{
	// Tinh chu vi hinh tron
	double r, c, s;
	cout << "Tinh chu vi hinh tron";
	cout << "\nNhap ban kinh : ";
	cin >> r;
	c = TinhChuViHinhTron(r);
	cout << "Chu Vi Hinh Tron La : "<<c <<
	endl;
	//Tinh dien tich hinh tron
	cout << "\nTinh dien tich hinh tron";
	cout << "\nNhap ban kinh : ";
	cin >> r;
	s = TinhDienTichHinhTron(r);
	cout << "Dien Tich Hinh Tron La : " << s;

	return 0;
}

// Dinh nghia ham
// Tinh chu vi hinh tron
double TinhChuViHinhTron(double r)
{
	double c;
	c = (r * 2) * PI;
	return c;

}
// Tinh dien tich hinh tron
double TinhDienTichHinhTron(double r)
{
	double s;
	s = PI * r * r;
	return s;
}
	



