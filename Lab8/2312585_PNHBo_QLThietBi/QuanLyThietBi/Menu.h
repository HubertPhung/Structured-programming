
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, DanhSachTB dstb, int& n);
void ChayChuongTrinh();


void  XuatMenu() {
	cout << endl << "================================= CHON CHUC NANG ==================================";
	cout << endl << "1. Nhap danh sach thiet bi";
	cout << endl << "2. Xuat danh sach thiet bi";
	cout << endl << "3. Tinh tong gia tien cua tat ca thiet bi co nam nhap [x, y]";
	cout << endl << "4. Tim vi tri thiet bi theo ma thiet bi";
	cout << endl << "5. Sap xep danh sach thiet bi giam theo nam nhap, neu nam nhap trung sap tang theo ten thiet bi";
	cout << endl << "6. Xoa tat ca thiet bi co nam nhap x";
	cout << endl << "7. Chen thiet bi tb sau thiet bi co ma thiet bi la y cho truoc";
	cout << endl << "8. In bang thong ke so thiet bi theo nam nhap";
	cout << endl << "0. Thoat chuong trinh";
	cout << endl << "====================================================================================";
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
void XuLyMenu(int menu, DanhSachTB dstb, int& n) {
	int kq;
	ThietBi tb;
	string maTim;
	string maY;
	switch (menu) {
	case 1:
		cout << "\nNhap danh sach thiet bi";
		NhapDSTB(dstb, n);
		break;
	case 2:
		cout << "\nXuat danh sach thiet bi: \n";
		XuatDSTB(dstb, n);
		break;
	case 3:
		XuatDSTB(dstb, n);
		int x;
		int y;
		cout << "\nNhap nam x (x < y): ";
		cin >> x;
		cout << "\nNhap nam y: ";
		cin >> y;
		cout << "\nTong gia tien all cac thiet bi trong [x,y]: " << TinhTongTrongKhoang(dstb, n, x, y);

		break;
	case 4:
		cout << endl << "4. Tim vi tri thiet bi theo ma thiet bi: ";
		XuatDSTB(dstb, n);
		cout << "\nNhap ma tim: ";
		cin >> maTim;
		kq = TimTheoMa(dstb, n, maTim);
		cout << "Vi tri thiet bi can tim: " << kq + 1 << endl;
		break;
	case 5:
		XuatDSTB(dstb, n);
		cout << endl << "5. Sap xep danh sach thiet bi giam theo nam nhap, neu nam nhap trung sap tang theo ten thiet bi";
		SapXep(dstb, n);
		XuatDSTB(dstb, n);
		break;
	case 6:
		XuatDSTB(dstb, n);
		cout << endl << "6. Xoa tat ca thiet bi co nam nhap x: ";
		cout << "\nNhap nam thiet bi can tim: ";
		int nam;
		cin >> nam;
		Xoa(dstb, n, nam);
		XuatDSTB(dstb, n);
		break;
	case 7:

		cout << endl << "7. Chen thiet bi tb sau thiet bi co ma thiet bi la y cho truoc";

		break;
	case 8:
		
		cout << endl << "8. In bang thong ke so thiet bi theo nam nhap";
		
		break;
	default:
		cout << endl << "Thoat khoi chuong trinh";
		break;
	}
	if (menu > 0) {
		cout << endl << endl << " Nhan mot phim bat ky de tiep tuc";
		_getch();
	}
}

void ChayChuongTrinh() {
	int menu, soMenu = 8;
	int n;
	cout << "\nNhap so thiet bi: ";
	cin >> n;
	DanhSachTB dstb = {
		{"A001","Dien Thoai",2021,2,10.5},
		{"A002", "May quat", 2020, 1, 200},
		{"A003", "May tinh Dell", 2021, 10, 30.75},
		{"A004", "Tu lanh", 2022, 5, 50},
		{"A005", "May Tinh HP", 2020, 1, 200}
	};
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dstb, n);
	} while (menu > 0);
}


