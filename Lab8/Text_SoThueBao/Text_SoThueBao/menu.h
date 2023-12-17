void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, DSThueBao dstb, int& n);
void ChayChuongTrinh();

void XuatMenu() {
	cout << "\n=======================CHON CHUC NANG=======================";
	cout << "\n[1] Nhap co dinh danh sach thue bao (it nhat 5 so thue bao)";
	cout << "\n[2] Xuat thong tin cac thue bao ra man hinh";
	cout << "\n[3] Tim nhung thue bao co ten trung voi ten";
	cout << "\n[4] Sap xep thue bao tang dan theo ma vung";
	cout << "\n[0] Thoat khoi chuong trinh";
	cout << "\n============================================================";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("cls");
		XuatMenu();
		cout << "\nNhap so menu [0] - [4] : ";
		cin >> stt;
	} while (stt <0||stt>soMenu);
	return stt;
}

void XuLyMenu(int menu, DSThueBao dstb, int& n) {
	ThueBao p;
	string ten;
	switch (menu)
	{
	case 1:
		cout << "\n[1] Nhap co dinh danh sach thue bao (it nhat 5 so thue bao)" << endl;
		cout << "\nNhap so thue bao can nhap : ";
		cin >> n;
		NhapDSThueBao(dstb, n);
		break;
	case 2:
		cout << "\n[2] Xuat thong tin cac thue bao ra man hinh." << endl;
		XuatDSThueBao(dstb, n);
		break;
	case 3:
		
		cout << "\n[3] Tim nhung thue bao co ten trung voi ten." << endl;
		XuatDSThueBao(dstb, n);
		cout << "\nNhap ten can tim: ";
		cin.ignore();
		getline(cin, ten);
		Tim_SDT_Ten(dstb, n, ten);
		break;
	case 4:
		cout << "\n[4] Sap xep thue bao tang dan theo ma vung.";
		cout << "\nChua Sap Xep : ";
		XuatDSThueBao(dstb, n);
		Sap_MaVung(dstb, n);
		cout << "\nDa Sap Xep : ";
		XuatDSThueBao(dstb, n);
		break;
	default:
		cout << "\nThoat khoi chuong trinh";
		break;
	}
	if (menu > 0) {
		cout << "\nNhap phim bat ky de tiep tuc ";
		_getch();
	}

}
void ChayChuongTrinh() {
	int soMenu = 4, n=5,
		menu;
	DSThueBao dstb = {
		{100001, "Phung Nguyen Hoai Bo","Da Lat","098.8752291",{13,3,2007}},
		{100002, "Vu The Huynh","Dam Rong","051.2650120",{1,5,2010}},
		{100003, "Phan Khanh Vuong","Don Duong","045.0364722",{1,1,2006}},
		{100004, "Ngo Van Chuong","Dam Rong","049.141213",{1,5,2004}},
		{100005, "Nguyen Ngoc Truong Dan","Dong Nai","051.2052157",{1,3,2017}},
	};

	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dstb, n);
	} while (menu > 0);
}