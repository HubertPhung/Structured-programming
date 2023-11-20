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
double TinhBieuThuc(double x, double y, char k);


/*=========================================
4. Ham main
===========================================*/
int main() {
    double x, y;
    char k;
    cout << "Nhap so thuc x khac 0 : "; cin >> x;
    cout << "\nNhap so thuc y khac 0 : "; cin >> y;
    cout << "\nNhap ky tu k (+, -, *, /) : "; cin >> k;
    cout << "Ket qua cua bieu thuc " << x << " " << k << " " << y << " la: ";
    cout << TinhBieuThuc(x, y, k) << endl;

	_getch();
	return 0;
}

/*=========================================
5. Dinh nghia ham
===========================================*/
double TinhBieuThuc(double x, double y, char k)
{
    x != 0;
    y != 0;
	switch (k)
	{
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default: // Nếu k không thuộc {+, -, *, /},
        cout << "Ky tu khong nam trong +, -, *, /" << endl;
        return 0;
	}
}
