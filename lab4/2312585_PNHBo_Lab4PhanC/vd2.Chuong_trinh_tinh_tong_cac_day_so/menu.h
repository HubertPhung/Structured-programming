/*=================================================================================
* Khai báo nguyên mẫu các hàm xử lý trong menu
==================================================================================*/
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu);
void ChayChuongTrinh();

/*=================================================================================
* Định nghĩa các hàm xử lý trong menu
==================================================================================*/

// Định nghĩa hàm  xuất danh sách chức năng ra màn hình
// Input : không có
// Output : không có
void  XuatMenu() {
	cout << endl << "======== CHON CHUC NANG ========";
	cout << endl << "1. Tinh tong R";
	cout << endl << "2. Tinh tong S";
	cout << endl << "3. Tinh tong T";
	cout << endl << "0. Thoat khoi chuong trinh";
	cout << endl << "================================";
}

// Định nghĩa hàm chọn một menu trong danh sách
// Input : soMenu = số lương menu có thể chọn
// Output : số thứ tự me nu người dùng nhập vào
int ChonMenu(int soMenu) {
	int stt;	// Khai báo biến menu được chọn
	do {
		// Xóa toàn bộ màn hình console
		system("cls");

		// Gọi hàm xuát danh sách chức năng (menu)
		XuatMenu();

		// Thông báo cho người dùng chọn menu
		cout << endl << "Nhap mot so de chon menu : ";

		// Chờ người dùng nhập/chọn menu
		cin >> stt;
	} while (stt < 0 || stt > soMenu);

	return stt;
}

// Định nghĩa hàm xử lý menu tùy thuộc vào chức năng 
// do người dùng chọn chức năng là gì.
// Input : menu = Số thứ tự menu do người chọn
// Outut : không có
void XuLyMenu(int menu, int unsigned n) {
	double sum;
	switch (menu)
	{
	// Trường hợp tính tổng  R
	case 1:
		// Gọi hàm tính tổng  R
		sum = TinhTongR(n);
		// Xuất kết quả 
		cout << endl << "R = " << sum;
		break;
	// Trường hợp tính tổng S
	case 2:
		// Gọi hàm tính tổng S
		sum = TinhTongS(n);
		// Xuất kết quả
		cout << endl << "S = " << sum;
		break;
	// Trường hợp tính tổng T
	case 3:
		// Gọi hàm tính tổng T
		sum = TinhTongT(n);
		// Xuất kết quả
		cout << endl << "T = " << sum;
		break;

	default:
		cout << endl << "Thoat khoi chuong trinh";
		break;
	}
	if (menu > 0) {
		// Yêu cầu người dùng nhấn một phím để tiếp tục 
		cout << endl << endl << " Nhan mot phim bat ky de tiep tuc";

		// Chờ người dùng nhấn phím 
		_getch();
	}
}

void ChayChuongTrinh(unsigned int n) {
	int menu, // Lưu số thứ tự menu được chọn
		soMenu = 3; // Lưu số lượng menu chức năng
	// Lặp lại việc chọn và xử lý menu cho tới khi
	//người dùng chọn chức năng 0. Thoát Chương trình
	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, n);
	} while (menu > 0);
}


