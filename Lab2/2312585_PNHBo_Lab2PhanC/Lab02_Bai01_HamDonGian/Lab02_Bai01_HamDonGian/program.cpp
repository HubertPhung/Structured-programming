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

void Thongbao();
void XuatKyTu (short ma);
void XuatPhuongTrinh(float a, float);
//===========================================================================
// Định nghĩa hàm MAIN
//===========================================================================
int main()
{
	// Gọi hàm thông báo
	Thongbao();

	// Gọi hàm xuất ký tự
	XuatKyTu(157);				// Dùng giá trị làm đối số

	// Khai báo kiểu số nguyên tên là dollar và ma
	short dollar = 36, ma;
	XuatKyTu(dollar);			// Dùng tên biến làm đối số

	// Nhập mã ASCII từ bàn phím rồi truyền vào hàm
	cout << endl << "Nhập 1số trong đoạn [30..255] :";
	cin >> ma;
	XuatKyTu(ma);				// Dùng tên biến làm đối số

	// Dừng tham gia vào chương trình và chờ nhấn 1 phím để kết thúc
	_getch();

	// Trả về giá trị 1
	return 1;

	// Gọi hàm xuất phương tình
	XuatPhuongTrinh(2.3, 5);	// Dùng giá trị làm đối số
	// Khai báo biến số thực
	float p, q = 10;
	XuatPhuongTrinh(7.5, q);	// Dùng cả giá trị và biến

	// Nhập giá trị thực từ bàn phím, lưu vào biến p
	cout << endl << "Nhap mot so thuc : ";
	cin >> p;

	XuatPhuongTrinh(p, q);		// Dùng tên biến làm đối số

}

//===========================================================================
// Định nghĩa các hàm xử lý
//===========================================================================

// Định nghĩa hàm xuất một thông báo ra màn hình
void Thongbao()
{
	cout << endl << "Bạn phải hoàn thành bài tập này.";
}
// Định nghĩa hàm xuất ký tự có mã ASCII cho trước
// Input
//		ma : Mã ASCII của ký tự
// Output: không có
void XuatKyTu(short ma)
{
	char KyTu = (char)ma;
	cout << endl << ma << "<=>" << KyTu;
}

// Định nghĩa hàm xuất ra phương trình bậc nhất ax + b = 0
// Input:
//		a : Hệ số a
//		b : Hệ số b
// Output : Không có
void XuatPhuongTrinh(float a, float b)
{
	cout << endl << a << "* x +" << b << " = 0";
}