/*================================
1. Nap thu vien
==================================*/
#include<iostream>
#include<conio.h>
#include<math.h>
#include<string>
using namespace std;
/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/


/*=========================================
3. Khai bao nguyen mau ham
===========================================*/

int XuatSo(unsigned int n);
void DemSo(unsigned int n);
void DemSoLuongn(unsigned int n);
void DaoNguocSo(unsigned int n);
void TinhTongCacSon(unsigned int nn);
void ChuSoDauTien(unsigned int n);
string DoiSangSoNhiPhan(unsigned int n);
int SoHoanHao(unsigned int n);
void XuatSoHoanHao(unsigned int n);
int TimMaxm(unsigned int n);

/*=========================================
4. Ham main
===========================================*/
int main() {
    int n;
    cout << "Nhap so nguyen n : "; cin >> n;
    XuatSo(n);
    cout << "\nSo luong cac so chia het cho 3 nhung khong chia het cho 4 la : "; DemSo(n);
    cout << "\nDem So luong chu so nguyen la :"; DemSoLuongn(n);
    cout << "\nSo " << n << " sau khi dao nguoc la : "; DaoNguocSo(n);
    cout << "\nTong cac chu so nguyen trong " << n << " la: "; TinhTongCacSon(n);
    cout << "\nChu so dau tien trong " << n << " la: "; ChuSoDauTien(n);
    cout << "\nDoi so nguyen cua " << n << "sang so nhi phan la: " << DoiSangSoNhiPhan(n);
    cout << "\nSo nguyen n = ";
    if (SoHoanHao(n))
        cout << n << " la so hoan hao";
    else
        cout << n << " khong phai la so hoan hao";
    cout << "\nCac so hoan hao trong pham vi [1.." << n << "] la: "; XuatSoHoanHao(n);
    cout << TimMaxm(n);
    _getch();
    return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/

//a. Xuất các số từ 1 tới n, các số cách nhau 1 dấu Tab và mỗi dòng chứa 10 số

int XuatSo(unsigned int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << "\t";
        if (i % 10 == 0) { cout << endl; }
    }
    return n;
}
//b. Đếm số lượng các số chia hết cho 3 nhưng không chia hết cho 4 trong đoạn [1..n].

void DemSo(unsigned int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if ((i % 3 == 0) && (i % 4 != 0)) {
            s = s + 1;
        }
    }
    cout << s;
}

//c. Đếm số lượng chữ số của n. Ví dụ: n = 12345 thì số lượng chữ số là 5

void DemSoLuongn(unsigned int n) {
    int dem = 0;
    int temp = n;
    while (temp > 0) {
        temp /= 10;
        dem++;
    }
    cout << dem;
}

//d. Đảo ngược số n. Ví dụ: n = 12345 thì sau khi đảo ngược, n = 54321

void DaoNguocSo(unsigned int n) {
    int daonguoc = 0;
    int temp = n;
    while (temp > 0) {
        daonguoc = daonguoc * 10 + temp % 10;
        temp /= 10 ;
    }
    cout << daonguoc;
}

//e. Tính tổng các chữ số trong n. Ví dụ: n = 12345 thì tổng các chữ số là 
    //1 + 2 + 3 + 4 + 5 = 15

void TinhTongCacSon(unsigned int n) {
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        sum = sum + temp % 10;
        temp /= 10;
    }
    cout << sum;
}

//f. Cho biết chữ số đầu tiên trong n. Ví dụ: n = 12345 thì chữ số đầu tiên là 1.
void ChuSoDauTien(unsigned int n) {
    int temp = n;
    while (temp >= 10) {
        temp /= 10;
    }
    cout << temp;
}

//g.Đổi số n sang hệ nhị phân.Ví dụ : n = 123410 tương ứng với 100110100102.
string DoiSangSoNhiPhan(unsigned int n) {
    int temp = n;
    string NhiPhan = "";
    while (temp > 0) {
        int rem = temp % 2;
        NhiPhan = to_string(rem) + NhiPhan;
        temp /= 2;
    }
    return NhiPhan;

}


//h.Kiểm tra số n có phải là số hoàn hảo(còn gọi là số hoàn chỉnh, số hoàn thiện) ?
//Biết rằng, số hoàn hảo là số có tổng các ước bằng hai lần chính nó.Ví dụ : 6, 28 là
//số hoàn chỉnh vì 6 = (1 + 2 + 3 + 6) / 2, 28 = (1 + 2 + 4 + 7 + 14 + 28) / 2.
int SoHoanHao(unsigned int n) {
    int temp = n;
    int sum = 0;
    for (int i = 1; i <= temp / 2; i++) {
        if (temp % i == 0)
            sum += i;
    }
    if (sum == temp) return true;
    return false;
}


//i.Xuất tất cả các số hoàn chỉnh trong phạm vi[1..n].Ví dụ : Với n = 30 thì xuất 6, 28.
void XuatSoHoanHao(unsigned int n) {
    int temp = n;
    for (int i = 1; i <= temp; i++) {
        if (SoHoanHao(i))
            cout << i << "  ";
    }
}


//j.Tìm số nguyên m lớn nhất sao cho tổng 1 + 2 + … + m ≤ n.
int TimMaxm(unsigned int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s = s + i;
        if (s > n) {
            s = s - i;
        }
    }
    cout << "\nSo nguyen m lon nhat khi tong 1+2+…+m <=" << n << " m la: " << s << endl;
    return 0;
}