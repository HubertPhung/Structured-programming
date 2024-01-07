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
	do {
		cout << "\nNhap ma so thue bao : ";
		cin >> tb.maSoTB;
	} while (tb.maSoTB / 1000000 < 1 || tb.maSoTB / 1000000 >= 10);

	cout << "\nNhap ho va ten : ";
	cin.ignore();
	getline(cin, tb.hoTen);

	cout << "\nNhap dia chi : ";
	getline(cin, tb.diaChi);

	cout << "\nNhap so dien thoai : ";
	getline(cin, tb.sdt);

	do {
		cout << "\nNhap ngay hop dong : ";
		cin >> tb.ntn.ngay;
	} while (tb.ntn.ngay > 31 || tb.ntn.ngay < 0);
	do {
		cout << "\nNhap thang hop dong : ";
		cin >> tb.ntn.thang;
	} while (tb.ntn.thang > 12 || tb.ntn.thang < 0);
	cout << "\nNhap nam hop dong : ";
	cin >> tb.ntn.nam;
}

void Xuat1TB(ThueBao tb) {
	cout << setiosflags(ios::left)
		<< setw(10) << tb.maSoTB
		<< setw(25) << tb.hoTen
		<< setw(20) << tb.diaChi
		<< setw(12) << tb.sdt
		<< setw(2) << tb.ntn.ngay
		<< "/"
		<< setw(2) << tb.ntn.thang
		<< "/"
		<< setw(5) << tb.ntn.nam;
}

void NhapCoDinh(DanhSachTB dstb, int& n) {
	dstb[0] = { 2312585, "Phung Nguyen Hoai A", "An Giang","091.8752291",{3,04,2005}};
	dstb[1] = { 2312586, "Phung Nguyen Hoai B", "Da Lat", "091.8752292", {3,12,2006} };
	dstb[2] = { 2312587, "Phung Nguyen Hoai C", "Can Tho", "093.8752293",{1,7,2007} };
	dstb[3] = { 2312588, "Phung Nguyen Hoai D", "Di Linh", "094.8752294",{3,4,2008} };
	dstb[4] = { 2312589, "Phung Nguyen Hoai E", "Bao Loc", "048.8752295",{9,9,2009} };
	dstb[5] = { 2312580, "Phung Nguyen Hoai E", "An Giang", "068.8752296",{3,4,2000} };
	n = 6;
}

void XuatDSTB(DanhSachTB dstb, int n) {
	XuatTieuDe();
	for (int i = 0; i < n; i++) {
		cout << endl;
		Xuat1TB(dstb[i]);
	}
}

//3. Tìm những thuê bao có tên trùng với tên (tenTb được nhập từ bàn phím) cho trước.
string TimTen(string hoTen) {
	for (int i = hoTen.length() - 1; i >= 0; i--)
		if (hoTen[i] == ' ' || hoTen[i] == '_') {
			return hoTen.substr(i + 1);
		}
	return hoTen;
}

void TimSDT_Ten(DanhSachTB dstb, int n, string tenTb) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (tenTb.compare(TimTen(dstb[i].hoTen)) == 0) {
			Xuat1TB(dstb[i]);
			cout << endl;
			dem++;
		}	
	}
	if (dem == 0)
		cout << "\n Khong co thue bao nao co ten la : " << tenTb;
}

//4. Sắp xếp các thuê bao tăng dần theo mã vùng.

void HoanVi(ThueBao& a, ThueBao& b) {
	ThueBao t;
	t = a;
	a = b;
	b = t;
}

void SapTangTBTheoMaVung(DanhSachTB dstb, int n) {
	for (int i = 0; i < n - 1; i++) 
		for (int j = i + 1; j < n; j++) {
			if (dstb[i].sdt.substr(0,dstb[i].sdt.find('.')).compare(dstb[j].sdt.substr(0, dstb[j].sdt.find('.'))) == 1) {
				HoanVi(dstb[i], dstb[j]);
			}
		}
}

//6. Xóa theo tất cả thuê bao theo tên thuê bao (tenTb được nhập từ bàn phím) .

void XoaTbTheoTen(DanhSachTB dstb, int& n, string tenTb) {
	int temp = n;
	for (int i = 0; i < n; i++) {
		if (tenTb.compare(TimTen(dstb[i].hoTen)) == 0) {
			for (int j = i; j < n - 1; j++) {
				dstb[j] = dstb[j + 1];
			}
			n--;
		}
	}
	if (n == temp) {
		cout << "\nThue Bao can xoa khong ton tai!!!";
	}
}

////7. Cập nhật thông tin thuê bao theo mã thuê bao.

int TimThueBao(DanhSachTB dstb, int n, int timMaSo) {
	int vitri = -1;
	for (int i = 0; i < n; i++) {
		if (timMaSo == dstb[i].maSoTB);
		return vitri = i;
	}
	return vitri;
}

void CapNhat(DanhSachTB dstb, int n, int timMaSo) {
	int timMaThueBao = TimThueBao(dstb, n, timMaSo);
	if (timMaThueBao == -1) {
			cout << "\nKhong Tim Thay Thue Bao Can Cap Nhat.";
			return;
		}
	if (timMaThueBao != -1) {
		cout << "\nNhap Thong Tin Can Cap Nhat : ";
		Nhap1TB(dstb[timMaThueBao]);
	}
}

//8. Sắp xếp danh sách tăng theo tên tb, nếu tên tb trùng nhau thì giảm theo số điện thoại (không tính mã vùng).
string TimSDT(string sdt) {
	int vitri = sdt.find('.');
	if (vitri != -1) {
		return sdt.substr(vitri + 1);
	}
	else
		return " ";
}
void SapXepDS(DanhSachTB dstb, int n) {
	int dk;
	for (int i = 0; i < n - 1; i++) 
		for (int j = i + 1; j < n; j++) {
			dk = (TimTen(dstb[i].hoTen)).compare(TimTen(dstb[j].hoTen)) == 1 || (TimTen(dstb[i].hoTen)).compare(TimTen(dstb[j].hoTen)) == 0 &&
				(TimSDT(dstb[i].sdt)).compare(TimSDT(dstb[j].sdt)) == -1;
			if (dk) {
				HoanVi(dstb[i], dstb[j]);
			}
		}
}

//
struct ThongKe
{
	int soLuongKhachHang;
	int maVung;
};

typedef ThongKe MaVungThongKe[MAX];

void thongKeTheoMaVung(DanhSachTB dstb, int n, MaVungThongKe thongKe) {
	for (int i = 0; i < n; ++i) {
		int maVung = stoi(dstb[i].sdt.substr(0, dstb[i].sdt.find('.')));
		thongKe[maVung].maVung = maVung;
		thongKe[maVung].soLuongKhachHang++;
	}
}

void inThongKeTheoMaVung(const MaVungThongKe thongKe, int n) {
	cout << "\nThong ke so luong khach hang theo ma vung:\n";
	for (int i = 0; i < n; ++i) {
		if (thongKe[i].soLuongKhachHang > 0) {
			cout << "Ma vung " << thongKe[i].maVung << ": " << thongKe[i].soLuongKhachHang << " khach hang\n";
		}
	}
}
