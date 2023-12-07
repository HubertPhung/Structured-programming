/*=================================================================================
* Khai báo nguyên mẫu các hàm xử lý trong menu
==================================================================================*/
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, unsigned int n);
void ChayChuongTrinh(unsigned int n);

/*=================================================================================
* Định nghĩa các hàm xử lý trong menu
==================================================================================*/

// Định nghĩa hàm  xuất danh sách chức năng ra màn hình
// Input : không có
// Output : không có
void  XuatMenu() {
	cout << "\n============= CHUONG TRINH UOC SO =============\n";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Xuat cac so tu 1 tới n, cac so cach nhau 1 dau Tab và moi dong chua 10 so";
	cout << "\n2. Dem so luong cac so chia het cho 3 nhung khong chia het cho 4 trong doan [1..n].";
	cout << "\n3. Dem so luong chu so cua n. Vi du: n = 12345 thi so luong chu so la 5";
	cout << "\n4. Dao nguoc so n. Vi dụ: n = 12345 thi sau khi đao nguoc, n = 54321";
	cout << "\n5. Tinh tong cac chu so trong n. Vi du: n = 12345 thi tong cac chu so la 1 + 2 + 3 + 4 + 5 = 15";
	cout << "\n6. Cho biet chu so dau tien trong n. Vi dụ: n = 12345 thi chu so dau tien la 1.";
	cout << "\n7. Doi so n sang he nhi phan.Vi du : n = 123410 tuong ung voi 100110100102.";
	cout << "\n8. Kiem tra so n co phai la so hoan hao(con goi la so hoan chinh, so hoan thien)";
	cout << "\n9. Xuat tat ca cac so hoan chinh trong pham vi[1..n].Vi dụ : Voi n = 30 thi xuat 6, 28.";
	cout << "\n10. Tim so nguyen m lon nhat sao cho tong 1 + 2 + … + m <= n.";
	cout << "\n======================================================\n";
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
	int kq;
	switch (menu)
	{
	case 1:
		XuatSo(n);
		break;
	case 2:
		DemSo(n);
		break;
	case 3:
		DemSoLuongn(n);
		break;
	case 4:
		DaoNguocSo(n);
		break;
	case 5:
		TinhTongCacSon(n);
		break;
	case 6:
		ChuSoDauTien(n);
		break;
	case 7:
		cout << DoiSangSoNhiPhan(n);
		break;
	case 8:
		cout << SoHoanHao(n);
		break;
	case 9:
		XuatSoHoanHao(n);
		break;
	case 10:
		TimMaxm(n);
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
		soMenu = 10; // Lưu số lượng menu chức năng
	// Lặp lại việc chọn và xử lý menu cho tới khi
	//người dùng chọn chức năng 0. Thoát Chương trình
	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, n);
	} while (menu > 0);
}


