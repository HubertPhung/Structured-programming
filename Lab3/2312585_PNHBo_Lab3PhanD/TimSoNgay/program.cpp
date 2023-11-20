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


/*=========================================
4. Ham main
===========================================*/
int main() {
    
    _getch();
    return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/
/* Dinh nghia ham giai phuong trinh bac 2
*  InPut: min : ham so nho nhat co the nhap
*         max : ham so lon nhat co the nhap
*  OutPut: Mot so nguyen nam trong doan [min..max].
*/

int NhapSoTrongMien(int min, int max)
{
    int so;

    do
    {
        cout << endl << "Nhap mot so trong doan [" << min << ".." << max << "]";
        cin >> so;
    } while (so < min || so > max);
    return so;
}
/* Dinh nghia ham giai phuong trinh bac 2
*  InPut: min : ham so nho nhat co the nhap
*         max : ham so lon nhat co the nhap
*  OutPut: Mot so nguyen nam trong doan [min..max].
*/

