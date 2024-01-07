
void XuatMenu() {
	cout << "\n===================CHON CHUC NANG====================";
	cout << "\n[1] Thoat chuong trinh";
	cout << "\n[2] Nhap danh sach xe.";
	cout << "\n[3] Xuat danh sach xe.";
	cout << "\n[4] Tinh tong gia mua cua tat ca xe co nam san xuat \nthuoc[x, y](x, y la nam đuoc nhap).";
	cout << "\n[5] Tim xe cuoi cung theo hang san xuat.";
	cout << "\n[6] Sap xep danh sach xe giam theo hang xe, neu hang \nxe trung sap tang theo gia mua.";
	cout << "\n[7] Xoa tat ca xe theo nam san xuat.";
	cout << "\n[8] In bang thong ke so xe theo hang san xuat";
	cout << "\n=====================================================";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("cls");
		XuatMenu();
		cout << "\nNhap so menu : ";
		cin >> stt;
	} while (stt<1||stt>soMenu);
	return stt;
}

void XuLyMenu(int menu, DSQuanLyXe dsqlxe, int &n) {
	int x, y;
	string tenHang;
	int namXoa;
	switch (menu)
	{
	case 1:
		cout << "\n[1] Thoat chuong trinh";
		
		break;
	case 2:
		cout << "\n[2] Nhap danh sach xe.";
		cout << "\nNhap so xe can nhap : ";
		cin >> n;
		NhapDSXe(dsqlxe, n);
		break;
	case 3:
		cout << "\n[3] Xuat danh sach xe.";
		XuatDSXe(dsqlxe, n);
		break;
	case 4:
		cout << "\n[4] Tinh tong gia mua cua tat ca xe co nam san xuat thuoc[x, y](x, y la nam duoc nhap).";
		XuatDSXe(dsqlxe, n);
		cout << "\nNhap nam san xuat trong khoang [x,y]";
		cout << "\nNhap nam x : ";
		cin >> x;
		cout << "\nNhap nam y : ";
		cin >> y;
		cout << "\ntTong gia xe cac nam trong khoang [x,y] la :" << TongGiaXeCoNamXY(dsqlxe, n, x, y) << " Trieu Dong";
		break;
	case 5:
		cout << "\n[5] Tim xe cuoi cung theo hang san xuat.";
		XuatDSXe(dsqlxe, n);
		cout << "\nNhap Ten hang san xuat : ";
		cin.ignore();
		getline(cin, tenHang);
		TimXeTheoHang(dsqlxe, n, tenHang);
		
		break;
	case 6:
		cout << "\n[6] Sap xep danh sach xe giam theo hang xe, neu hang xe trung sap tang theo gia mua.";
		XuatDSXe(dsqlxe, n);
		SapXepXeTheoHang(dsqlxe, n);
		XuatDSXe(dsqlxe, n);
		break;
	case 7:
		cout << "\n[7] Xoa tat ca xe theo nam san xuat.";
		XuatDSXe(dsqlxe, n);
		cout << "\nNhap Nam San Xuat Can Xoa : ";
		cin >> namXoa;
		XoaXeTheoNamSX(dsqlxe, n, namXoa);
		XuatDSXe(dsqlxe, n);
		break;
	case 8:
		cout << "\n[8] In bang thong ke so xe theo hang san xuat";
		XuatDSXe(dsqlxe, n);
		cout << endl;
		inThongKeHangSX(dsqlxe, n);
		break;
	default:
		break;
	}
	if (menu > 1) {
		cout << "\nNhap phim bat ki de tiep tuc ";
		_getch();
	}
}

void ChayChuongTrinh() {
	int soMenu = 8,
		menu, n=10;
	
	DSQuanLyXe dsqlxe = {
		{"40E164641","Future",2001,"Honda",20},
		{"49B164642","Ex",2011,"Yamaha",31},
		{"48A164643","Winner",2018,"Honda",40},
		{"47E164644","AB",2020,"Honda",50},
		{"46D164645","Future",2001,"Honda",16},
		{"45E164646","Vision",2023,"Honda",34},
		{"44E164647","Future",2002,"Honda",11},
		{"43F164648","Z1000",2016,"Kawasaki",100},
		{"42E164649","Future",2003,"Honda",21},
		{"41E164640","Future",2004,"Honda",8}
	};
	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dsqlxe, n);
	} while (menu > 1);
}