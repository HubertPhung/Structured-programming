
#pragma once
#define MAX 100

struct ThietBi {
	string maTB;
	string tenTB;
	int nam;
	int tgbh;
	double giaTB;
};

typedef ThietBi DanhSachTB[MAX];
int TimTheoMa(DanhSachTB dstb, int n, string maTim);
void Nhap1TB(ThietBi& tb, DanhSachTB dstb, int n);
void NhapDSTB(DanhSachTB dstb, int n);
void Xuat1TB(ThietBi tb);
void XuatTieuDe();
void XuatDSTB(DanhSachTB dstb, int n);
double TinhTongTrongKhoang(DanhSachTB dstb, int n, int x, int y);
int TimTheoMa(DanhSachTB dstb, int n, string maTim);
void HoanVi(ThietBi& tb1, ThietBi& tb2);
void SapXep(DanhSachTB dstb, int n);
int TimTheoNam(DanhSachTB dstb, int n, int nam);
void Xoa(DanhSachTB dstb, int& n, int nam);


void Nhap1TB(ThietBi& tb, DanhSachTB dstb, int n) {

	
	cout << "\nNhap MaTB: ";
	cin >> tb.maTB;
	
	cout << "Nhap TenTB: ";
	cin.ignore();
	getline(cin, tb.tenTB);
	cout << "Nhap nam: ";
	cin >> tb.nam;
	cout << "Nhap Thoi gian bao hanh: ";
	cin >> tb.tgbh;
	cout << "Nhap Gia Tien: ";
	cin >> tb.giaTB;
}

void NhapDSTB(DanhSachTB dstb, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin thiet bi " << i + 1;
		Nhap1TB(dstb[i], dstb, i);
	}
}

void Xuat1TB(ThietBi tb) {
	cout << "\n" << setiosflags(ios::left)
		<< setw(10) << tb.maTB
		<< setw(25) << tb.tenTB
		<< setw(10) << tb.nam
		<< setw(15) << tb.tgbh
		<< setw(10) << tb.giaTB;

}

void XuatTieuDe() {
	cout << "\n" << setiosflags(ios::left)
		<< setw(10) << "Ma TB"
		<< setw(25) << "Ten TB"
		<< setw(10) << "Nam"
		<< setw(15) << "Thoi gian BH"
		<< setw(10) << "Gia TB";
}

void XuatDSTB(DanhSachTB dstb, int n) {
	XuatTieuDe();
	for (int i = 0; i < n; i++) {
		Xuat1TB(dstb[i]);
	}
}


double TinhTongTrongKhoang(DanhSachTB dstb, int n, int x, int y) {

	double kq = 0;

	for (int i = 0; i < n; i++) {
		if (dstb[i].nam >= x && dstb[i].nam <= y) kq += dstb[i].giaTB;
	}
	return kq;
}

int TimTheoMa(DanhSachTB dstb, int n, string maTim) {

	int temp = -1;
	for (int i = 0; i < n; i++) {
		if (maTim.compare(dstb[i].maTB) == 0) temp = i;
	}
	return temp;
}

void HoanVi(ThietBi& tb1, ThietBi& tb2) {
	ThietBi tb;
	tb = tb1;
	tb1 = tb2;
	tb2 = tb;
}

void SapXep(DanhSachTB dstb, int n) {
	int dk;
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++) {
			dk = (dstb[i].nam < dstb[j].nam) || (dstb[i].nam == dstb[j].nam && dstb[i].tenTB.compare(dstb[j].tenTB) == 1);
			if (dk) HoanVi(dstb[i], dstb[j]);
		}
}


int TimTheoNam(DanhSachTB dstb, int n, int nam) {
	int temp = -1;

	for (int i = 0; i < n; i++) {
		if (nam == dstb[i].nam) temp = i;
	}
	return temp;
}

void Xoa(DanhSachTB dstb, int& n, int nam) {
	int vitri = -1;

	while (1) {
		vitri = TimTheoNam(dstb, n, nam);
		if (vitri == -1) break;

		for (int i = vitri; i < n - 1; i++) {
			dstb[i] = dstb[i + 1];
		}
		n--;
	}

}
