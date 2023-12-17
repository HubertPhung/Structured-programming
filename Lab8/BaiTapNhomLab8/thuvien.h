
#define MAX 100

struct ThietBi {
	string maTB;
	string tenTB;
	int nam;
	int tgbh;
	double giaTB;
};


typedef ThietBi DanhSachTB[MAX];
void Nhap1TB(ThietBi& tb) {
	cout << "\nNhap MaTB: ";
	cin >> tb.maTB;

	cout << "\nNhap TenTB: ";
	cin.ignore();
	getline(cin, tb.tenTB);
	cout << "\nNhap nam: ";
	cin >> tb.nam;
	cout << "\nNhap Thoi gian bao hanh: ";
	cin >> tb.tgbh;
	cout << "\nNhap Gia Tien: ";
	cin >> tb.giaTB;
}

void NhapDSTB(DanhSachTB dstb, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin thiet bi";
		Nhap1TB(dstb[i]);
	}
}

void Xuat1TB(ThietBi tb) {
	cout << "\n" << setiosflags(ios::left)
		<< setw(10) << tb.maTB
		<< setw(25) << tb.tenTB
		<< setw(10) << tb.nam
		<< setw(10) << tb.tgbh
		<< setw(10) << tb.giaTB;

}

void XuatDSTB(DanhSachTB dstb, int n) {
	
	for (int i = 0; i < n; i++) {
		
		Xuat1TB(dstb[i]);
	}
}


double TinhTongTrongKhoang(DanhSachTB dstb, int n) {
	int x, y;
	double kq = 0;
	cout << "Nhap nam x (x < y): ";
	cin >> x;
	cout << "Nhap nam y: ";
	cin >> y;
	for (int i = 0; i < n; i++) {
		if (dstb[i].nam > x && dstb[i].nam < y) kq += dstb[i].giaTB;
	}
	return kq;
}

int TimTheoMa(DanhSachTB dstb, int n){
	string x;
	int temp = -1;
	cout << "\nNhap Ma thiet bi can tim: ";
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (x.compare(dstb[i].maTB) == 0) temp = i;
	}
	return temp;
}

void HoanVi(ThietBi &tb1, ThietBi &tb2) {
	ThietBi tb;
	tb = tb1;
	tb1 = tb2;
	tb2 = tb;
}

void SapXep(DanhSachTB dstb, int n) {
	int dk, dk2;
	for(int i = 0; i < n -1; i++)
		for (int j = i; j < n; j++) {
			dk = (dstb[i].nam < dstb[j].nam);
			if (dk) HoanVi(dstb[i], dstb[j]);
			else if (dstb[i].nam == dstb[j].nam) {
				dk2 = (dstb[i].tenTB.compare(dstb[j].tenTB) == 1);
				if(dk2)	HoanVi(dstb[i], dstb[j]);
			}
		}
	XuatDSTB(dstb, n);
}


int TimTheoNam(DanhSachTB dstb, int n, int nam) {
	int temp = -1;

	for (int i = 0; i < n; i++) {
		if (nam == dstb[i].nam) temp = i;
	}
	return temp;
}

void Xoa(DanhSachTB dstb, int& n) {
	int vitri = -1;
	cout << "\nNhap nam thiet bi can tim: ";
	int nam;
	cin >> nam;
	while (1) {
		vitri = TimTheoNam(dstb, n, nam);
		if (vitri == -1) break;
		
		for (int i = vitri; i < n - 1; i++) {
			dstb[i] = dstb[i + 1];
		}
		n = n - 1;
	}
	XuatDSTB(dstb, n);
}

void Chen(DanhSachTB dstb, int &n, ThietBi tb) {
	int vitri = TimTheoMa(dstb, n);
	if (vitri != -1)
	{
		dstb[vitri + 1] = tb;
		for (int i = vitri + 2; i < n + 1; i++) {
			dstb[i] = dstb[i + 1];
		}
		n++;
	}
	XuatDSTB(dstb, n);
}

void ThongKe(DanhSachTB dstb, int n) {
	DanhSachTB thongKe;
	int x = 0;
	cout << "\nNhap nam thiet bi can tim: ";
	int nam;
	cin >> nam;
	int vitri;
	while (1) {
		vitri = TimTheoNam(dstb, n, nam);
		if (vitri == -1) break;
		thongKe[x] = dstb[vitri];
		for (int i = vitri; i < n - 1; i++) {
			dstb[i] = dstb[i + 1];
		}
		n--;
		x++;
	}
	XuatDSTB(thongKe, x);
}