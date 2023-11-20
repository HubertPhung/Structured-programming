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
int XuatUocChung_BoiChung(int m, int n);
int TimUCLN(int m, int n);
int TimUCNN(int m, int n);
int KtraTongMvaN(int m, int n);

/*=========================================
4. Ham main
===========================================*/
int main()
{
    int n, m;
    cout << "Nhap n :"; cin >> n;
    cout << "\nNhap m : "; cin >> m;

    XuatUocChung_BoiChung(m, n);
    TimUCLN(m, n);
    TimUCNN(m, n);
    KtraTongMvaN(m, n);

    return 0;
}



/*=========================================
5. Dinh nghia ham
===========================================*/
//a.Xuất ra màn hình các ước chung của m và n.Ví dụ : 6 và 8 có các ước chung 1, 2.
int XuatUocChung_BoiChung(int m, int n) {
    int max = 0;
    for (int i = 1; i <= m && i <= n; ++i) {
        if (m % i == 0 && n % i == 0) {
            max = i;
        }
    }
    cout << "Uoc chung cua " << m << " va " << n << " la: ";
    for (int i = 1; i <= max; ++i) {
        if (max % i == 0) {
            cout << i << " ";
        }
    }
    return 0;
}

//b.Tìm ước chung lớn nhất của m và n.Ví dụ : 12 và 16 có ước chung lớn nhất là 4.
int TimUCLN(int m, int n) {
    int max = 0;
    int s;
    for (int i = 1; i <= m && i <= n; ++i) {
        if (m % i == 0 && n % i == 0) {
            max = i;
        }
    }

    cout << "Uoc chung lon nhat cua " << m << " va " << n << " la: " << max << endl;
    return 0;
}
   


//c.Tìm bội chung nhỏ nhất của m và n.Ví dụ : 12 và 16 có bội chung nhỏ nhất là 48.
int TimUCNN(int m, int n) {
    int max = 0;
    int min;
    for (int i = 1; i <= m && i <= n; ++i) {
        if (m % i == 0 && n % i == 0) {
            max = i;
        }
    }
    min = (m * n) / max;
    cout << "Uoc chung nho nhat cua " << m << " va " << n << " la: " << min << endl;
    return 0;
}
//d.Kiểm tra tổng các ước của m có bằng n không ?
int KtraTongMvaN(int m, int n) {
    int s = 0;
    for (int i = 1; i <= m; ++i) {
        if (m % i == 0) {
            s = s + i;
        }
    }

    if (s > n) {
        cout << "Tong cac uoc cua m = " << m << " la " << s << " va lon hon n = " << n << endl;
    }
    else if (s < n) {
        cout << "Tong cac uoc cua m = " << m << " la " << s << " va nho hon n = " << n << endl;
    }
    else {
        cout << "Tong cac uoc cua m = " << m << " la " << s << " va bang n = " << n << endl;
    }

    return 0;
}