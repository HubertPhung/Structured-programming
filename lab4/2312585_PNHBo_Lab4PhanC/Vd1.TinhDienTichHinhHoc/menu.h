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
	cout << endl << "1. Tinh dien tich hinh vuong";
	cout << endl << "2. Tinh dien tich hinh chu nhat";
	cout << endl << "3. Tinh dien tich hinh tam giac";
	cout << endl << "4. Tinh dien tich hinh tron";
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
void XuLyMenu(int menu) {
	// Khai báo các biến 
	double a, b, c, dienTich;
	switch (menu)
	{
	// Trường hợp tính diện tích hình vuông
	case 1:
		// Thông báo người dùng nhập độ dài cạnh
		cout << endl << "Nhap do dai canh hinh vuong"; 
		cin >> a;

		// Gọi hàm tính diện tích hình vuông
		dienTich = DienTichHinhVuong(a);

		// Xuất kết quả
		cout << endl << "Dien tich hinh vuong canh" << a << " la " << dienTich;

		break;
	// Trường hợp tính diện tích hình chữ nhật
	case 2:
		// Thông báo người dùng nhập chiều dài & chiều rộng
		cout << endl << "Nhap chieu dai hinh chu nhat ";
		cin >> a;
		cout << endl << "Nhap chieu rong hinh chu nhat";
		cin >> b;

		// Gọi hàm tính diện tích HCN
		dienTich = DienTichHinhChuNhat(a, b);

		// Xuất kết quả		
		cout << endl << "Dien tich hinh chu nhat "
			<< "co chieu dai = " << a
			<< " co chieu rong = " << b
			<< " la " << dienTich;

		break;
	// Trường hợp tính diện tích hình tam giác 
	case 3:
		// Thông báo người dùng nhập chiều dài 3 cạnh
		cout << endl << "Nhap do dai canh a : ";
		cin >> a;
		cout << endl << "Nhap do dai canh b : ";
		cin >> b;
		cout << endl << "Nhap do dai canh c : ";
		cin >> c;
		// Gọi hàm tính diện tích hình tam giác 
		dienTich = DienTichTamGiac(a, b, c);

		// Xuất kết quả
		cout << endl << "Dien tich hinh tam giac "
			<< "co 3 canh a = " << a << " b = " << b << " c = " << c << " la " << dienTich;
		break;
	// Trường hợp tính diện tích hình tròn
	case 4:
		// Thông báo người dùng nhập độ dài bán kính
		cout << endl << "Nhap do dai ban kinh : ";
		cin >> a;
		
		// Gọi hàm tính diện tích hình tròn
		dienTich = DienTichHinhTron(a);

		//Xuất kết quả
		cout << endl << "Dien tich hinh tron ban kinh " << a << " la " << dienTich;
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
	int menu, // Lưu số thứ tự menu được chọn
		soMenu = 4; // Lưu số lượng menu chức năng
	// Lặp lại việc chọn và xử lý menu cho tới khi
	//người dùng chọn chức năng 0. Thoát Chương trình
	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu);
	} while (menu > 0);
}

