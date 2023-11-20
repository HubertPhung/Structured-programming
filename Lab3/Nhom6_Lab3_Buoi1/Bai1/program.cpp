/*================================
1. Nap thu vien
==================================*/
#include<iostream>
#include<conio.h>
#include<math.h>
#include<iomanip>
using namespace std;
/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/


/*=========================================
3. Khai bao nguyen mau ham
===========================================*/
int GiaiThua(int n);

/*=========================================
4. Ham main
===========================================*/

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "n! = " << GiaiThua(n);
    _getch();
    return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/

int GiaiThua(int n)
{
    int x = 1;
    for (int i = 1; i <= n; i++) {
        x = x * i;
    }
    return x;
}

