#define MAX 100
#define THOAT 0
typedef int DaySo[MAX];

//Khai bao nguyen mau ham
void NhapMang(DaySo a, int n);
void XuatMang(DaySo a, int n);
int TimMax(DaySo a, int n);

//Dinh nghia ham
//Nhap mang
void NhapMang(DaySo a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\na[" << i << "]=";
		cin >> a[i];
	}
}
//Xuat mang
void XuatMang(DaySo a, int n)
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}
//Tim max trong mang
/*Input: mang a, n
Output: max --> int
PP thu sai:
	max=a[0]
	i=1->n-1:
		if(a[i]>max): max=a[i];
*/
int TimMax(DaySo a, int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}
//// kiem tra so nguyen to
bool SoNT(int n) {
	if (n < 2) return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
//// Tong cac so nguyen to co 2 chu so la
int TinhTong(DaySo a, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 10 && a[i] < 100) {
			if (SoNT(a[i])) sum += a[i];
		}
	}
	return sum;
}




