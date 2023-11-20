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
void GiaiPhuongTrinhBacHa(float a, float b, float c);
float NhapMotSoKhacKhong();
/*=========================================
4. Ham main
===========================================*/
int main() {
    float a, b, c;
    a = NhapMotSoKhacKhong();
    cout << "\nNhap he so b : ";
    cin >> b;
    cout << "\nNhap he so c : ";
    cin >> c;
    GiaiPhuongTrinhBacHa(a, b, c);

    _getch();
    return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/
/* Dinh nghia ham nhap mot so khac khong tu ban phim
*  InPut:  Khong co   
*  OutPut: Mot so thuc khac 0
*/
float NhapMotSoKhacKhong()
{
    float so;

    do
    {
        cout << endl << "Nhap so thuc (khac 0) : ";
        cin >> so;
    } while (so == 0);
    return so;
}
/* Dinh nghia ham giai phuong trinh bac 2
*  InPut:
*       a : He so a
*       b : He so b
*       c : He so c
*  OutPut: khong co, chi xuat ra nghiem cua phuong trinh
*/

void GiaiPhuongTrinhBacHa(float a, float b, float c)
{
    double delta,
        x;
    delta = b * b - a * a * c;

    if (delta == 0.0)
    {
        x = -b / (2 * a);
        cout << endl << "Phuong trinh co nghiem kep x = " << x;
    }

    else if (delta < 0)
    {
        cout << endl << "Phuong trinh vo nghiem";
    }

    else
    {
        cout << endl << "Phuong trinh co 2 nghiem phan biet : ";
        x = (-b + sqrt(delta)) / (2 * a);
        cout << "x1 = " << setprecision(5) << x;
        x = (-b - sqrt(delta)) / (2 * a);
        cout << " va x2 = " << setprecision(5) << x;

    }
    return;
}