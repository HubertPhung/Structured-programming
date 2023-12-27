void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, DSThueBao dstb, int& n);

void XuatMenu() {
	cout << "\n===================Menu=====================";
	cout << "\n1. Nhap danh sach thue bao";
	cout << "\n2. Xem danh sach thue bao";
	cout << "\n3. Tim so dien thoai khi biet ten";
	cout << "\n4. Sap xep cac thue bao tang dan theo ma vung";
	cout << "\n5. Doc danh sach tu file(tao file.txt it nhat 10 thue bao, doc tu file da tao)";

	cout << "\n6. Xoa theo tat ca thue bao theo ten thue bao(tenTb duoc nhap tu ban phim)";

	cout << "\n7. Cap nhat thong tin thue bao theo ma thue bao";

	cout << "\n8. Sap xep danh sach tang theo ten tb, neu ten tb trung nhau thi giam theo so dien thoai(khong tinh ma vung)";

	cout << "\n9. In bang thong ke so thue bao theo ma vung.";
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
	
	string ten;
	string fileName;
	string tenTb;

	switch (menu) {
	case 0:
		cout << "\nThoat khoi chuong trinh";
		break;
	case 1:
		cout << "\n1. Nhap danh sach thue bao";
		cout << "\nNhap n = ";
		cin >> n;
		Nhap_DS_ThueBao(dstb, n);
		break;
	case 2:
		cout << "\n2. Xuat danh sach thue bao";
		Xuat_DS_ThueBao(dstb, n);
		break;
	case 3:
		Xuat_DS_ThueBao(dstb, n);
		cout << "\n3. Tim so dien thoai khi biet ten";
		
		cout << "\nNhap ten can tim: ";
		getline(cin, ten);
		Tim_SDT_Ten(dstb, n, ten);
		break;
	case 4:
		Xuat_DS_ThueBao(dstb, n);
		cout << "\n4. Sap xep cac thue bao tang dan theo ma vung";
		Sap_MaVung(dstb, n);
		Xuat_DS_ThueBao(dstb, n);
		break;
	case 5:
		cout << "\n5. Doc danh sach tu file(tao file.txt it nhat 10 thue bao, doc tu file da tao)";
		cout << "\nNhap ten file: ";
		getline(cin, fileName);
		
		DocFile(dstb, n, fileName);
		Xuat_DS_ThueBao(dstb, n);
		break;
	case 6:
		Xuat_DS_ThueBao(dstb, n);
		cout << "\n6. Xoa theo tat ca thue bao theo ten thue bao(tenTb duoc nhap tu ban phim)";
		cout << "\nNhap tenTb: ";
		getline(cin, tenTb);
		XoaTheoTenTB(dstb, n, tenTb);
		Xuat_DS_ThueBao(dstb, n);
	
		break;
	case 7:
		Xuat_DS_ThueBao(dstb, n);
		cout << "\n7. Cap nhat thong tin thue bao theo ma thue bao";

		CapNhat(dstb, n);
		Xuat_DS_ThueBao(dstb, n);
		
		break;
	case 8:
		Xuat_DS_ThueBao(dstb, n);
		cout << "\n8. Sap xep danh sach tang theo ten tb, neu ten tb trung nhau thi giam theo so dien thoai(khong tinh ma vung)";

		SapXepTheoSDT(dstb, n);
		Xuat_DS_ThueBao(dstb, n);
		break;
	case 9:
		Xuat_DS_ThueBao(dstb, n);
		cout << "\n9. In bang thong ke so thue bao theo ma vung.";
		TK(dstb, n);
		break;

	default:
		break;
	}
	_getch();
}