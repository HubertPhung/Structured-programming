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
	cout << endl << "================================= CHON CHUC NANG ==================================";
	cout << endl << "1. Doi sang he nhi phan (b=2)";
	cout << endl << "2. Doi sang he bat phan (b=8)";
	cout << endl << "3. Doi sang he thap luc phan (b=16)";
	cout << endl << "4. Doi sang he co so 7 (b=7)";
	cout << endl << "5. Doi sang he co so b bat ky (2 <= b <= 16)";
	cout << endl << "0. Thoat khoi chuong trinh";
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
void XuLyMenu(int menu, int unsigned n) {
	switch(menu){
	case 1:
		cout << "\n1. Doi sang he nhi phan (b = 2)";
		cout << endl << n << "_10  =  ";
		DoiCoSo(n, BIN);
		cout << "_2";
		break;
	case 2:
		cout << "\n2. Doi sang he bat phan (b = 8)";
		cout << endl << n << "_10  =  ";
		DoiCoSo(n, OCT);
		cout << "_8";
		break;
	case 3:
		cout << "\n3. Doi sang he thap luc phan (b = 16)";
		cout << endl << n << "_10  =  ";
		DoiCoSo(n, HEX);
		cout << "_16";
		break;
	case 4:
		cout << "\n4. Doi sang he co so (b = 7)";
		cout << endl << n << "_10  =  ";
		DoiCoSo(n, SEV);
		cout << "_7";
	case 5:
		int b;
		cout << "Nhap he co so can doi : "; cin >> b;
		cout << "\n5. Doi sang he co so bat ky (2 <= b <= 16) ";
		cout << endl << n << "_10 = ";
		DoiCoSo(n, b);
		cout << "_" << b;
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
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, n);
	} while (menu > 0);
}


