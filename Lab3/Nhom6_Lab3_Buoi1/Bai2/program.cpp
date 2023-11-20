/*==================================================
1. Nap thu vien
==================================================*/
#include<iostream>
#include<conio.h>
using namespace std;

/*==================================================
2. Khai bao hang va kieu du lieu, bien toan cuc
==================================================*/

/*==================================================
3. Khai bao nguyen mau ham
==================================================*/
int KiemTraNT(int n);
int DemSoNguyenTo(int n);
/*==================================================
4. Ham main
==================================================*/
int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "So luong cac so nguyen to nho hon n: " << DemSoNguyenTo(n);


	_getch();
	return 1;
}

/*==================================================
5. Dinh nghia ham
==================================================*/
/* Kiem tra so n la so nguyen to hay khong?
Buoc 1:
	Input: n --> int
	Output:
		1: n la so nguyen to
		0: n khong phai la so nguyen to
Buoc 2: Mo ta thuat toan
	B2.0: if (n<=1)
			return 0;
	B2.1: kq=1;
	B2.2: i:2 --> n-1
			if(n%i==0)
				kq=0;
				break;
	B2.3: Tra ve kq;
*/
int KiemTraNT(int n)
{
	if (n <= 1)
		return 0;

	int kq = 1;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			kq = 0;
			break;
		}
	}
	return kq;
}

int DemSoNguyenTo(int n) {
	int x = 0;
	for (int i = 2; i < n; i++) {
		
		if (KiemTraNT(i)) {
			x++;
		}
	}
	return x;
}