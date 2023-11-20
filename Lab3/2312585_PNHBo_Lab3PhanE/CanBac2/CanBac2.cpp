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
double CanBacHai(double n);
/*=========================================
4. Ham main
===========================================*/
int main()
{
    int n;
    cout << "Nhap n : ";
    cin >> n;
    cout << "\nCan bac hai cua " << n << " la : " << CanBacHai(n);

	_getch();
	return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/

double CanBacHai(double n) {
    double t = n;
    double S = pow(10, -15);
    for (int i = 1; i <= n; i++) {
        if ((n / t == t) || abs(t - n / t) <= t * S) {
            return t;
        }
        else t = (t + n / t) / 2;
    }
}

