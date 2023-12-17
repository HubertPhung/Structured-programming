#define MAX 100

struct NgayThangNam{
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
};

struct ThueBao{
	unsigned int maThueBao;
	string hoTen;
	string diaChi;
	string soDT;
	NgayThangNam ngayHopDong;
	string ten;
};

typedef ThueBao DSThueBao[MAX];

void XuatTieuDe() {
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << "MaThueBao"
		<< setw(25) << "Ho va Ten"
		<< setw(25) << "Dia Chi"
		<< setw(13) << "So DT"
		<< setw(10) << "NgayHopDong";
}

void Nhap1ThueBao(ThueBao& p) {
	cout << "\nNhap Ma Thue Bao : ";
	cin >> p.maThueBao;
	
	cout << "\nNhap Ho va Ten : ";
	cin.ignore();
	getline(cin, p.hoTen);

	cout << "\nNhap Dia Chi : ";
	cin.ignore();
	getline(cin, p.diaChi);

	cout << "\nNhap So Dien Thoai : ";
	cin.ignore();
	getline(cin, p.soDT);

	cout << "\nNhap Ngay/Thang/Nam Hop Dong : ";
	cin >> p.ngayHopDong.ngay;
	
	cin >> p.ngayHopDong.thang;
	
	cin >> p.ngayHopDong.nam;

}

void Xuat1ThueBao(ThueBao p) {
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << p.maThueBao
		<< setw(25) << p.hoTen
		<< setw(25) << p.diaChi
		<< setw(13) << p.soDT
		<< setw(1) << p.ngayHopDong.ngay<<"/"
		<< setw(1) << p.ngayHopDong.thang<<"/"
		<< setw(1) << p.ngayHopDong.nam;
}

void NhapDSThueBao(DSThueBao dstb, int& n) {
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thue bao thu " << i + 1 << ": ";
		Nhap1ThueBao(dstb[i]);
	}
}

void XuatDSThueBao(DSThueBao dstb, int n) {
	XuatTieuDe();
	for (int i = 0; i < n; i++) {
		Xuat1ThueBao(dstb[i]);
	}
}

void Tim_SDT_Ten(DSThueBao dstb, int n, string ten) {
	
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (ten.compare(dstb[i].hoTen) == 0) {
			Xuat1ThueBao(dstb[i]);
			dem++;
		}
	}
	if (dem == 0) cout << "\nTrong danh sach khong co thue bao nao co ten la " << ten;
}


void HoanVi(ThueBao& a, ThueBao& b) {
	ThueBao t;
	t = a;
	a = b;
	b = t;
}

void Sap_MaVung(DSThueBao dstb, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dstb[i].soDT.substr(0, 3).compare(dstb[j].soDT.substr(0, 3)) == 1)
				HoanVi(dstb[i], dstb[j]);
		}
	}
}