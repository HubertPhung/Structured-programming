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
void Loikhuyen(double w, double h);
/*=========================================
4. Ham main
===========================================*/
int main()
{
	/*
	* w la khoi kuong co the (kg)
	* h la chieu cao (m)
	* t la tuoi 
	*/
	double w, h, t;
	cout << "Nhap tuoi cua ban : "; cin >> t;
	cout << "\nNhap khoi luong co the (kg)  : "; cin >> w;
	cout << "\nNhap chieu cao con nguoi (m) : "; cin >> h;
	cout << "\nTuoi cua ban la " << t << " tuoi " << "," << " khoi luong " << w << " kg " << "," << " chieu cao " << h << " m ";
	cout << "\nChi so khoi co the cua ban la: " << TinhChiSoBMI(w, h);
	cout << "\nChi so co the ban dang :"; Loikhuyen( w, h);

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
void Loikhuyen(double w, double h) {
	double BMI = TinhChiSoBMI( w, h);

	if (BMI < 15) {
		cout << "Trạng thái cơ thể: Đói khát";
	}
	else if (BMI < 17.5) {
		cout << "Trạng thái cơ thể: Biếng ăn";
	}
	else if (BMI < 18.5) {
		cout << "Trạng thái cơ thể: Thiếu cân";
	}
	else if ((BMI >= 18.5) && (BMI < 25)) {
		cout << "Trạng thái cơ thể: Lý tưởng";
	}
	else if ((BMI >= 25) && (BMI < 30)) {
		cout << "Trạng thái cơ thể: Thừa cân";
	}
	else if ((BMI >= 30) && (BMI < 40)) {
		cout << "Trạng thái cơ thể: Béo phì";
	}
	else if (BMI >= 40) {
		cout << "Trạng thái cơ thể: Trẻ em bị béo phì";
	}


	
	
}