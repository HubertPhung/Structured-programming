// khai bao biem
#include <iostream>
using namespace std;
#define MAX 3600
#define SIXTY 60

// Khai bao nguyen mau
void DoiThoiGian(unsigned int n);


// Ham main
int main()
{
	int n;
	cout << "\nNhap gia tri n = ";
	cin >> n;
	DoiThoiGian(n);
	
	
	return 0;
}

// Dinh nghia ham
void DoiThoiGian(unsigned int n)
{
	int g, p, s;
	g = n / MAX;
	p = (n % MAX) / SIXTY;
	s = (n % MAX) % SIXTY;
	cout << "\nGio:Phut:Giay la: ";
	cout << g << ":" << p << ":" << s;
	return;

}

