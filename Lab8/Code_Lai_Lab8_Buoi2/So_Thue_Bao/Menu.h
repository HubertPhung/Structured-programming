
void XuatMenu() {
	cout << "\n=============================CHON CHUC NANG=================================";
	cout << "\n[1] Nhap co dinh danh sach thue bao (it nhat 5 thue bao).";
	cout << "\n[2] Xuat thong tin cac thue bao ra man hinh.";
	cout << "\n[3] Tim nhung thue bao co ten trung voi ten(tenTb duoc nhap tu ban phim) cho truoc.";
	cout << "\n[4] Sap xep cac thue bao tang dan theo ma vung.";
	cout << "\n[5] Doc danh sach tu file(tao file.txt it nhat 10 thue bao, doc tu file da tao)";
	cout << "\n[6] Xoa theo tat ca thue bao theo ten thue bao(tenTb duoc nhap tu ban phim) .";
	cout << "\n[7] Cap nhat thong tin thue bao theo ma thue bao.";
	cout << "\n[8] Sap xep danh sach tang theo ten tb, neu ten tb trung nhau thi giam theo \n\tso dien thoai(khong tinh ma vung).";
	cout <<	"\n[9] In bang thong ke so thue bao theo ma vung.";
	cout << "\n[0] Thoat chuong trinh.";
	cout << "\n============================================================================";
}

int ChonMenu(int soMenu) {
	int stt;

	do {
		system("cls");
		XuatMenu();
		cout << "\nNhap so menu : ";
		cin >> stt;
	} while (stt<0 || stt>soMenu);
	return stt;
}

void XuLyMenu(int menu, DanhSachTB dstb , int& n, MaVungThongKe thongKe) {
	string tenTb;
	int timMaSo;
	switch (menu)
	{
	case 1:
		cout << "\n[1] Nhap co dinh danh sach thue bao (it nhat 5 thue bao).";
		NhapCoDinh(dstb, n);
		cout << "\nDa Nhap Co Dinh.";
		break;
	case 2:
		cout << "\n[2] Xuat thong tin cac thue bao ra man hinh.";
		XuatDSTB(dstb, n);
		break;
	case 3:
		XuatDSTB(dstb, n);
		cout << "\n[3] Tim nhung thue bao co ten trung voi ten(tenTb duoc nhap tu ban phim) cho truoc.";
		cout << "\nNhap Ten TB can tim : ";
		cin.ignore();
		getline(cin, tenTb);
		TimSDT_Ten(dstb, n, tenTb);
		break;
	case 4:
		cout << "\n[4] Sap xep cac thue bao tang dan theo ma vung.";
		cout << "\nHien hanh : ";
		XuatDSTB(dstb, n);
		cout << "\nDa Sap xep : ";
		SapTangTBTheoMaVung(dstb, n);
		XuatDSTB(dstb, n);
		break;
	case 5:
		cout << "\n[5] Doc danh sach tu file(tao file.txt it nhat 10 thue bao, doc tu file da tao)";
		
		break;
	case 6:
		cout << "\n[6] Xoa theo tat ca thue bao theo ten thue bao(tenTb duoc nhap tu ban phim) .";
		XuatDSTB(dstb, n);
		cout << "\nNhap Ten TB can xoa : ";
		cin.ignore();
		getline(cin, tenTb);
		XoaTbTheoTen(dstb, n, tenTb);
		XuatDSTB(dstb, n);
		break;
	case 7:
		cout << "\n[7] Cap nhat thong tin thue bao theo ma thue bao.";
		XuatDSTB(dstb, n);
		cout << "\nNhap Ma So Thue Bao Can Cap Nhat : ";
		cin >> timMaSo;
		CapNhat(dstb, n, timMaSo);
		XuatDSTB(dstb, n);
		break;
	case 8:
		cout << "\n[8] Sap xep danh sach tang theo ten tb, neu ten tb trung nhau thi giam theo \n\tso dien thoai(khong tinh ma vung).";
		cout << "\nHien hanh : ";
		XuatDSTB(dstb, n);
		cout << "\nDa Sap Xep : ";
		SapXepDS(dstb, n);
		XuatDSTB(dstb, n);
		break;
	case 9:
		cout << "\n[9] In bang thong ke so thue bao theo ma vung.";
		XuatDSTB(dstb, n);
		cout << "\nThong ke theo ma vung : ";
		thongKeTheoMaVung(dstb, n, thongKe);
		break;
	default:
		cout << "\n[0] Thoat chuong trinh.";
		break;
	}
	if (menu > 0) {
		cout << "\nNhan phim bat ky de tiep tuc. ";
		_getch();
	}
}

void ChayChuongTrinh() {
	int menu,
		soMenu = 9, n;
	DanhSachTB dstb;
	MaVungThongKe thongKe = {};
	NhapCoDinh(dstb, n);
	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dstb , n, thongKe);
	} while (menu > 0);
}