/*================================
1. Nap thu vien
==================================*/
#include<iostream>
#include <cmath>
using namespace std;

/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/


/*=========================================
3. Khai bao nguyen mau ham
===========================================*/
int XuatUocSo(int n);
int DemSo(int n);
int TinhTong(int n);
double CanBac2(double n);
int TimSoLN(int n);


/*=========================================
4. Ham main
===========================================*/
int main()
{
    int n;
    cout << "Nhap N>0 : ";
    cin >> n;
    XuatUocSo(n);
    DemSo(n);
    TinhTong(n);
    CanBac2(n);
    TimSoLN(n);

    return 0;
}



/*=========================================
5. Dinh nghia ham
===========================================*/
//a. Xuất tất cả các ước số của n. Ví dụ: Các ước số của n = 12 là 1, 2, 3, 4, 6, 12.
int XuatUocSo(int n) {
    cout << "Uoc So cua " << n << " la :";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << "\t";
        }
    }
    return 0;
}

//b. Đếm số lượng các ước số của n. Ví dụ: Số lượng ước số của n = 12 là 6.
int DemSo(int n) {
    int S = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            S++;
        }
    }
    cout << "\nSo luong cua so uoc la : " << S;
    return 0;
}
//c. Tính tổng các ước số của n. Ví dụ: Tổng các ước số của n = 12 là 28
int TinhTong(int n) {
    int S = 0;
    if (n <= 0) {
        cout << " Nhap gia tri lon hon 0 ";
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                S = S + i;
            }
        }
    }
    cout << "\nTinh tong cua cac uoc so la : " << S;
    return 0;
}

//d. Tính căn bậc 2 của n (không sử dụng hàm sqrt)
double CanBac2(double n) {
    double S = 1;
    double X = n;
    double SaiSo = 0.00001;
    while (fabs(S * S - X) / X >= SaiSo) {
        S = (X / S - S) / 2 + S;
    }
    cout << "\nCan bac 2 cua " << X << " la : " << S << endl;
    return 0;
}

//e. Tìm số lớn nhất nhỏ hơn hoặc bằng n mà là lũy thừa của 2. Ví dụ: n = 1234 thì 
//xuất 1024.
int TimSoLN(int n) {
    int S = 1;
    while (S * 2 <= n) {
        S *= 2;
    }
    cout << "So lon nhat nho hon hoac bang " << n << " ma la luy thua cua 2 la : " << S << endl;
    return 0;
}