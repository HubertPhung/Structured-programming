/*=================================================================================
* Khai báo nguyên mẫu các hàm xử lý trong menu
==================================================================================*/
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, DanhSachTB dstb, int &n);
void ChayChuongTrinh();

/*=================================================================================
* Định nghĩa các hàm xử lý trong menu
==================================================================================*/

// Định nghĩa hàm  xuất danh sách chức năng ra màn hình
// Input : không có
// Output : không có
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
	cout << endl << " Thoat chuong trinh";
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
		cout << "Tong gia tien all cac thiet bi trong [x,y]: " << TinhTongTrongKhoang(dstb, n);
		
		break;
	case 4:
		cout << endl << "4. Tim vi tri thiet bi theo ma thiet bi";

		kq = TimTheoMa(dstb, n);
		Xuat1TB(dstb[kq]);
		break;
	case 5:
		cout << endl << "5. Sap xep danh sach thiet bi giam theo nam nhap, neu nam nhap trung sap tang theo ten thiet bi";

		SapXep(dstb, n);
		
		break;
	case 6:
		cout << endl << "6. Xoa tat ca thiet bi co nam nhap x: ";

		Xoa(dstb, n);
		break;
	case 7:
		cout << endl << "7. Chen thiet bi tb sau thiet bi co ma thiet bi la y cho truoc";

		Nhap1TB(tb);
		Chen(dstb, n, tb);

		break;
	case 8:
		cout << endl << "8. In bang thong ke so thiet bi theo nam nhap";

		ThongKe(dstb, n);

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

void ChayChuongTrinh() {
	int menu, soMenu = 8;
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	DanhSachTB dstb = {
		{"DT12045","Dien Thoai",2021,2,10.5},
		{"MQ43210", "May quat", 2020, 1, 200},
		{"MT23452", "May tinh Dell", 2021, 10, 30.75},
		{"TL44432", "Tu lanh", 2022, 5, 50},
		{"MT12332", "May Tinh HP", 2020, 1, 200}
	};
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dstb, n);
	} while (menu > 0);
}


