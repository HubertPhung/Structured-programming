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

void GiaiPTBacNhat(double a, double b);


/*=========================================
4. Ham main
===========================================*/
int main() { 
	double a, b;
	cout << "Phuong trinh bac nhat 1 an co dang ax + b = 0";
	cout << "\nNhap a va b lan luot la : "; cin >> a; cout << ":"; cin >> b;
	GiaiPTBacNhat( a, b);

	_getch();
	return 0;
}

/*=========================================
5. Dinh nghia ham
===========================================*/
void GiaiPTBacNhat(double a, double b)
{

	if (a ==0 && b == 0){
		cout << "Phuong trinh vo so nghiem";
	}
	else if (a == 0 && b != 0){
		cout << "\nPhuong trinh vo nghiem";
	}
	else if (a != 0){
		cout << "Nghiem cua phuong trinh la : " << -b / a;
	}
	return;
}
