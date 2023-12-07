/*=================================================================================
* Khai báo nguyên mẫu các hàm xử lý trong menu
==================================================================================*/
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int deg);
void ChayChuongTrinh();

/*=================================================================================
* Định nghĩa các hàm xử lý trong menu
==================================================================================*/

// Định nghĩa hàm  xuất danh sách chức năng ra màn hình
// Input : không có
// Output : không có
void  XuatMenu() {
	cout << endl << "=============== CHON CHUC NANG ===============";
	cout << "\n1. Tim và xuat ra so Fibonacci thu n.";
	cout << "\n2. Liet ke cac so Fibonacci nho hon hoac bang n";
	cout << "\n3. Liet ke n so Fibonacci dau tien";
	cout << "\n0. Thoat chuong trinh";
	cout << endl << "===============================================";
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
void XuLyMenu(int menu, int n) {
	switch (menu) {
	case 1:
		cout << "So Fibonacci thu " << n << " : " << TimSo(n);
		break;
	case 2:

		cout << "Cac so Fibonacci nho hon hoac bang n: ";
		LKSo(n);
		break;
	case 3:
		cout << n << " so Fibonacci dau tien: ";
		NSoDauTien(n);
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

void ChayChuongTrinh()
{
	int deg, menu, soMenu = 3;
	cout << "\nNhap vao do >> ";
	cin >> deg;


	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, deg);
	} while (menu > 0);

	cout << "\nCam on da su dung chuong trinh";
	_getch();
}




