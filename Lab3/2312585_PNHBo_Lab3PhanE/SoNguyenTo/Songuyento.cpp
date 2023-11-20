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
bool KtraSoNguyenTo(int n);
int XuatSo(int n);
int DemSo(int n);
int TongUocSo(int n);
int PhanTich(int n);
/*=========================================
4. Ham main
===========================================*/
int main() {
    int n;
    cout << "N: ";
    cin >> n;
    KtraSoNguyenTo(n);
    if (KtraSoNguyenTo(n) == true)cout << n << " la so nguyen to";
    cout << n << " khong phai la so nguyen to";
    cout << endl;
    XuatSo(n);
    cout << endl;
    cout << "\nSo nguyen to tu 1 den n la : " << DemSo(n);
    TongUocSo(n);
    PhanTich( n);
    return 0;
}

/*=========================================
5. Dinh nghia ham
===========================================*/
//a. Kiểm tra n có phải là số nguyên tố (sử dụng vòng lặp for)
bool KtraSoNguyenTo(int n) {
    if (n < 2) {
        return false;
    }
    else {
        int c = 0;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                c++;
            }
        }
        if (c == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}
//b.Xuất ra màn hình các số nguyên tố trong phạm vi từ 1 tới n, các số cách nhau 1
//dấu Tab.Mỗi dòng chứa 5 số.

int XuatSo(int n) {
    int S = 0;
    if (n < 2) {
        cout << "k phai snt";
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (KtraSoNguyenTo(i)) {
                S++;
                cout << i << "\t";
                if (S % 5 == 0) {
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
//c.Đếm số lượng số nguyên tố trong phạm vi từ 1 tới n.
int DemSo(int n) {
    int S = 0;
    for (int i = 1; i <= n; i++) {
        if (KtraSoNguyenTo(i) == true) {
            S++;
        }
    }
    return S;
}

//d. Tính tổng các ước số nguyên tố của n. Ví dụ: n = 30 có các ước 1, 2, 3, 5, 6, 10, 
//15, 30. Tổng các ước số nguyên tố là 2 + 3 + 5 = 10
int TongUocSo(int n) {
    int S = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0 && KtraSoNguyenTo(i)) {
                S = S + i;
            }
        }
        cout << "\nTinh tong cua cac uoc so la : "<< S; return S;
}
 
//e. Phân tích n thành tích các thừa số nguyên tố. Ví dụ: n = 12 = 2.2.3, n = 30 = 
//2.3.5.
int PhanTich(int n) {
    cout << "\nPhan tich " << n << " thanh tich cac thua so nguyen to: ";

    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            cout << i;
            n /= i;

            if (n > 1) {
                cout << " * ";
            }
        }
    }

    cout << endl;

    return 0;
}