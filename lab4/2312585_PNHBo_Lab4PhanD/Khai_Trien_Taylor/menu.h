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
	cout << "\n=========== SIN - COS - TAN =============\n";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tinh sin(x)";
	cout << "\n2. Tinh cos(x)";
	cout << "\n3. Tinh e^x";
	cout << "\n=========================================\n";
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
void XuLyMenu(int menu, int deg) {
	double kq;
	switch (menu) {
	case 1:
		cout << "\n1. Tinh sin(x)";
		kq = TinhSin(deg);
		cout << "\nSin(" << deg << ") = " << kq;
		break;
	case 2:
		cout << "\n2. Tinh cos(x)";
		kq = TinhCos(deg);
		cout << "\nCos(" << deg << ") = " << kq;
		break;
	case 3:
		cout << "\n3. Tinh e^x";
		kq = TinhE(deg);
		cout << "\ne^" << deg << " = " << kq;
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



