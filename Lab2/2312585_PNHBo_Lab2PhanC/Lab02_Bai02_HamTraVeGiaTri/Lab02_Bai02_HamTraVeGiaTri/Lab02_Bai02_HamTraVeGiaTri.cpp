//===========================================================================
// Nạp các thư viện vào chương trình
//===========================================================================
#include <iostream>
#include <conio.h>

using namespace std;

//===========================================================================
// Định nghĩa hằng số và các kiểu dữ liệu mới
//===========================================================================

//===========================================================================
// Khai báo nguyên mẫu các hàm
//===========================================================================

int NhapSoNguyen();
int TinhTong(unsigned int n);

//===========================================================================
// Định nghĩa hàm MAIN
//===========================================================================

int main()
{
	// Khai báo biến để lưu số được nhập từ bàn phím
	int x, y, z;

	// Gọi hàm nhập số nguyên và lưu kết quả vào 2 biến
	x = NhapSoNguyen();
	y = NhapSoNguyen();

	// Xuất tổng của 2 số vừa nhập
	cout << x << " + " << y << " = " << x + y;

	// Sử dụng lời gọi hàm trong biểu thức
	z = (x + y) * NhapSoNguyen();
	cout << endl << "z = " << z;

	// Khai báo biến để lưu kết quả
	int KetQua = 0;

	// Gọi hàm tính tổng các số từ 1 tới 50
	KetQua = TinhTong(50);

	//Xuất ra kết quả màn hình
	cout << endl << "1 + 2 + ... + 50 = " << KetQua;

	// Khai báo một biến số nguyên không âm
	unsigned int m;
			
	// Nhập giá trị cho biến m từ bàn phím
	cout << endl << " Nhap mot so nguyen khong am : ";
	cin >> m;

	// Gọi hàm tính tổng các số từ 1 tới m
	KetQua = TinhTong(m);

	// Xuất kết quả ra màn hình
	cout << endl << "1 + 2 + ... +"
		<< m << " = " << KetQua;

	// Dừng chương trình và chờ nhấn 1 phím để kết thúc
	_getch();

	// Trả về giá trị 1
	return 1;
}

//===========================================================================
// Định nghĩa các hàm xử lý
//===========================================================================

// Định nghĩa hàm nhập một số nguyên từ bàn phím
// input : không có
// Output : Giá trị được nhập từ bàn phím
int NhapSoNguyen()
{
	int so;		// Khai báo biến để lưu giá trị nhập vào
	// Xuất thông báo để người dùng biết
	cout << endl << "Nhap mot so nguyen :";

	// Chờ người dùng nhập một số nguyên
	cin >> so;

	// Gán giá trị sao cho hàm và trở về nơi gọi hàm
	return so;
}
// Định nghĩa hàm tính tổng các số từ 1 tới n
// Input :
//		n: Một số nguyên dương
// Output: Tổng các số từ 1 tới n
int TinhTong(unsigned int n)
{
	// Khai báo biến để lưu kết quả
	int sum = 0;

	// Tính Tổng 1 + 2 + ... + n
	sum = n * (n + 1) / 2;

	// Gán giá trị sum cho hàm và trở về nơi gọi hàm
	return sum;
}