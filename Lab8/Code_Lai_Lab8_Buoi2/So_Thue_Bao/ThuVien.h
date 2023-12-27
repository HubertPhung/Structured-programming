#define MAX 100

struct NgayHopDong
{
	unsigned int ngay; 
	unsigned int thang;
	unsigned int nam;
};

struct ThueBao
{
	unsigned int maSoTB;
	string hoTen;
	string diaChi;
	string sdt;
	NgayHopDong ntn;
};

typedef ThueBao DanhSachTB[MAX];

void XuatTieuDe() {
	cout << endl;
	cout << setiosflags(ios::left);
	cout << setw(10) << "Ma So"
		<< setw(25) << "Ho va Ten"
		<< setw(20) << "Dia Chi"
		<< setw(12) << "SDT"
		<< setw(15) << "Ngay Hop Dong";
}


void Nhap1TB(ThueBao& tb) {
	cout << "\nNhap ma so thue bao : ";
	cin >> tb.maSoTB;

	cout << "\nNhap ho va ten : ";
	cin.ignore();
	getline(cin, tb.hoTen);

	cout << "\nNhap dia chi : ";
	cin.ignore();
	getline(cin, tb.diaChi);

	cout << "\nNhap so dien thoai : ";
	cin.ignore();
	getline(cin, tb.sdt);

	cout << "\nNhap ngay hop dong : ";
	cin >> tb.ntn.ngay;
	cout << "/";
	cin >> tb.ntn.thang;
	cout << "/";
	cin >> tb.ntn.nam;
}

void Xuat1TB(ThueBao tb) {
	cout << setiosflags(ios::left);
	cout << setw(10) << tb.maSoTB
		<< setw(25) << tb.hoTen
		<< setw(20) << tb.diaChi
		<< setw(12) << tb.sdt
		<< setw(15) << tb.ntn.ngay << "/" << tb.ntn.thang << "/" << tb.ntn.nam;
}

void NhapDSTB(DanhSachTB dstb, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nNhap so thue bao thu " << i + 1 << " : ";
		Nhap1TB(dstb[i]);
	}
}

void XuatDSTB(DanhSachTB dstb, int n) {
	XuatTieuDe();
	for (int i = 0; i < n; i++) {
		cout << endl;
		Xuat1TB(dstb[i]);
	}
}

