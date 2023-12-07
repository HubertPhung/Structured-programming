/*=================================================================================
* Nạp các tập tin thư viên hàm xây dựng sẵn
==================================================================================*/
#include <iostream>
#include <conio.h>
#include <math.h>
#include<string>


using namespace std;

/*=================================================================================
* Nạp các tập tin: thuvien.h, menu.h vào chương trình
==================================================================================*/
#include "Thuvien.h"
#include "menu.h"

/*=================================================================================
* Định nghĩa hàm main
==================================================================================*/
int main() {
	// Khai báo biến số nguyên dương n
	unsigned int n;
	// Nhập giá trị cho biến n
	cout << endl << "Nhap mot so nguyen duong : ";
	cin >> n;
	// Gọi hàm chạy chương trình 
	ChayChuongTrinh(n);

	return 1;
}