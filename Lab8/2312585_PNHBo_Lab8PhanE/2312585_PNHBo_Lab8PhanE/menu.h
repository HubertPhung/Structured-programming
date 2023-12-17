void XuatMenu() {
	cout << "\n=========================================CHON CHUC NANG=============================================";
	cout << "\n1. Nhap vao mot danh sach sinh vien.";
	cout << "\n2. In ra danh sach sinh vien(co dinh dang va canh le).";
	cout << "\n3. Sap xep va xuat danh sach sinh vien(DSSV) giam dan theo diem trung binh";
	cout << "\n4. Sap xep va xuat DSSV tang dan theo ten, neu trung ten, sep tang theo ho va ten lot.";
	cout << "\n5. Tim va xuat thong tin cua sinh vien co ten(tenSv, duoc nhap tu ban phim) cho truoc.";
	cout << "\n6. Xuat DSSV cua lop(lop duoc nhap tu ban phim) cho truoc.Sap tang theo ten.";
	cout << "\n7. Xuat DSSV co kha nang khong duoc tot nghiep.";
	cout << "\n8. Tim thong tin sinh vien theo ma so(maSo duoc nhap tu ban phim) cho truoc.";
	cout << "\n9. Tinh ty le(phan tram) so sinh vien dat loai gioi tro len.Biet rang, sinh vien dat";
	cout << "\n10. Xep loai hoc luc cua sinh vien dua vao diem trung binh ";
	cout << "\n=====================================================================================================";
}

int ChonMenu(int soMenu) {
	int stt;
	do {
		system("cls");
		XuatMenu();
		cout << "\nNhap so menu can chon";
		cin >> stt;
	} while (stt<0 || stt >soMenu);
	return stt;
}

void XuLyMenu(int menu, DanhSachSV dssv, int n ) {
	DanhSachSV sv;
	switch (menu)
	{
	case 1:
		cout << "\n1. Nhap vao mot danh sach sinh vien.";
		NhapDSSV(dssv, n);
		break;
	case 2:
		cout << "\n2. In ra danh sach sinh vien(co dinh dang va canh le).";
		XuatDSSV(dssv, n);
		break;
	case 3:
		cout << "\n3. Sap xep va xuat danh sach sinh vien(DSSV) giam dan theo diem trung binh";
		cout << "\nBang diem hien hanh:\n";
		XuatDSSV(dssv, n);
		SapXepDS_GiamDTB(dssv, n);
		cout << "\nSau khi sap xep:\n";
		XuatDSSV(dssv, n);
		break;
	case 4:
		cout << "\n4. Sap xep va xuat DSSV tang dan theo ten, neu trung ten, sep tang theo ho va ten lot.";
		cout << "\nHien hanh:\n";
		XuatDSSV(dssv, n);
		SapXepDS_TangTen(dssv, n);
		cout << "\nSau khi sap xep:\n";
		XuatDSSV(dssv, n);
		break;
	case 5:
		cout << "\n5. Tim va xuat thong tin cua sinh vien co ten(tenSv, duoc nhap tu ban phim) cho truoc.";
		
		break;
	case 6:
		cout << "\n6. Xuat DSSV cua lop(lop duoc nhap tu ban phim) cho truoc.Sap tang theo ten.";
		break;
	case 7:
		cout << "\n7. Xuat DSSV co kha nang khong duoc tot nghiep.";
		
		break;
	case 8:
		cout << "\n8. Tim thong tin sinh vien theo ma so(maSo duoc nhap tu ban phim) cho truoc.";
		
		break;
	case 9:
		cout << "\n9. Tinh ty le(phan tram) so sinh vien dat loai gioi tro len.Biet rang, sinh vien dat";
		break;
	case 10:
		cout << "\n10. Xep loai hoc luc cua sinh vien dua vao diem trung binh ";
		cout << "\nBang diem hien hanh:\n";
		XuatDSSV(dssv, n);
		cout << "\nBang diem sau khi xep loai:\n";
		XepLoai(sv, n);
		XuatDSSV(dssv, n);
		break;
	default:
		cout << "\nThoat khoi chuong trinh ";
		break;
	}
	if (menu > 0) {
		cout << endl << "Nhap mot so de tiep tuc";
		_getch();
	}
}

void ChayChuongTrinh() {
	int menu,
		soMenu = 10;
	DanhSachSV dssv = {
		{"2345538", "Nguyen Van", "Hung","M", 5.7,"CTK47A"},
		{"2312575","Pham Chau Ky","Anh","M",5.5, "CTK47B"},
		{"2312694","Nguyen Hoai","Nam","M",7.8, "CTK46A"},
		{"2312663","Do Dang Dieu","Linh","F",2.7, "CTK44A"},
		{"2312660","Dinh Thi Mai","Lanh","F",8, "CTK47C"},
		{"2312609","Nguyen Thi Ngoc","Hien","F",5.5, "CTK43A"},
		{"2312571","Nguyen Minh","Anh","F",9.9,"CTK47A"},
		{"2312555","Tran Nguyen Tuan","Anh","M",1.1,"CTK45A"},
		{"2312999","Phung Nguyen Hoai","Bo","M", 5.5,"CTK40A"}
	};
	int n;
	cout << "\nNhap so luong sinh vien : ";
	cin >> n;
	do {
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, dssv, n);
	} while (menu > 0);
}
