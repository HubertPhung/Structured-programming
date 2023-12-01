/*=================================================================================
* Khai báo nguyên mẫu các hàm xử lý trong menu
==================================================================================*/
void XuatMenu(unsigned int n);
int ChonMenu(int soMenu, unsigned int n);
void XuLyMenu(int menu, unsigned int n);
void ChayChuongTrinh();

/*=================================================================================
* Định nghĩa các hàm xử lý trong menu
==================================================================================*/

// Định nghĩa hàm  xuất danh sách chức năng ra màn hình
// Input : không có
// Output : không có
void  XuatMenu(unsigned int n) {
	cout << "\n============= CHUONG TRINH SO NGUYEN TO =============\n";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Kiem tra so nguyen to";
	cout << "\n2. Xuat cac so nguyen to tu 1 .. " << n;
	cout << "\n3. Dem so luong SNT tu 1 .. " << n;
	cout << "\n4. Tinh tong cac uoc so nguyen to cua " << n;
	cout << "\n5. Phan tich " << n << " thanh tich cac thua so nguyen to";
	cout << "\n======================================================\n";
}

// Định nghĩa hàm chọn một menu trong danh sách
// Input : soMenu = số lương menu có thể chọn
// Output : số thứ tự me nu người dùng nhập vào
int ChonMenu(int soMenu, unsigned int n) {
	int stt;	// Khai báo biến menu được chọn
	do {
		// Xóa toàn bộ màn hình console
		system("cls");

		// Gọi hàm xuát danh sách chức năng (menu)
		XuatMenu(n);

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
	switch (menu)
	{
	case 1:
		cout << "\n1. Kiem tra so nguyen to";
		if (KtraSoNguyenTo(n))
			cout << "\n" << n << " la so nguyen to";
		else
			cout << "\n" << n << " khong phai la so nguyen to";
		break;
	case 2:
		cout << "\n2. Xuat cac so nguyen to tu 1 .. " << n;
		XuatSo(n);
		break;
	case 3:
		cout << "\n3. Dem so luong SNT tu 1 .. " << n;
		cout << "\nCo " << DemSo(n) << " so nguyen to trong pham vi [1.." << n << "].";
		break;
	case 4:
		cout << "\n4. Tinh tong cac uoc so nguyen to cua " << n;
		cout << "\nTong cac uoc so nguyen to cua " << n << " la : " << TongUocSo(n);
		break;
	case 5:
		cout << "\n5. Phan tich " << n << " thanh tich cac thua so nguyen to";
		PhanTich(n);
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
		soMenu = 5; // Lưu số lượng menu chức năng
	// Lặp lại việc chọn và xử lý menu cho tới khi
	//người dùng chọn chức năng 0. Thoát Chương trình
	do {
		menu = ChonMenu(soMenu, n);
		XuLyMenu(menu, n);
	} while (menu > 0);
}


