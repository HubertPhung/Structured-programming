void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, ThueBao a[MAX], int& n);

void XuatMenu() {
	cout << "\n===================Menu=====================";
	cout << "\n1. Nhap danh sach thue bao";
	cout << "\n2. Xem danh sach thue bao";
	cout << "\n3. Tim so dien thoai khi biet ten";
	cout << "\n4. Sap xep cac thue bao tang dan theo ma vung";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n===========================================================";
}

int ChonMenu(int soMenu) {
	int stt;
	for (;;) {
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so thuoc khoang [0.." << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		cin.ignore();
		if (stt >= 0 && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, DSThueBao dstb, int& n) {
	switch (menu) {
	case 0:
		system("CLS");
		cout << "\nThoat khoi chuong trinh";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap danh sach thue bao";
		Nhap_DS_ThueBao(dstb, n);
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat danh sach thue bao";
		Xuat_DS_ThueBao(dstb, n);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim so dien thoai khi biet ten";
		Tim_SDT_Ten(dstb, n);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Sap xep cac thue bao tang dan theo ma vung";
		Sap_MaVung(dstb, n);
		Xuat_DS_ThueBao(dstb, n);
		break;
	default:
		break;
	}
	_getch();
}