#define MAX 100


struct NgayThangNam {
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
};

struct ThueBao {
	unsigned int maThueBao;
	string hoTen;
	string diaChi;
	string soDT;
	NgayThangNam ntn;
};

typedef ThueBao DSThueBao [MAX];


void XuatTieuDe();
void Nhap_1_ThueBao(ThueBao& p);
void Nhap_DS_ThueBao(DSThueBao dstb, int& n);
void Xuat_1_ThueBao(ThueBao p);
void Xuat_DS_ThueBao(DSThueBao dstb, int n);
void Tim_SDT_Ten(DSThueBao dstb, int n);
void Sap_MaVung(DSThueBao dstb, int n);



void XuatTieuDe() {
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(8) << "Ma So"
		<< setw(26) << "Ho va Ten"
		<< setw(36) << "Dia Chi"
		<< setw(14) << "So DT"
		<< setw(11) << "Ngay HD";
}

void Nhap_1_ThueBao(ThueBao& p) {
	cout << "\nNhap ma so thue bao(gom 7 chu so): ";
	cin.ignore();
	cin >> p.maThueBao;

	cout << "\nHo va ten: ";
	cin.ignore();
	getline(cin ,p.hoTen);

	cout << "\nDia chi: ";
	cin.ignore();
	getline(cin ,p.diaChi);

	cout << "\nSo DT: ";
	cin.ignore();
	getline(cin ,p.soDT);

	cout << "\nNhap ngay hop dong: ";
	cin >> p.ntn.ngay;

	cout << "\nNhap thang hop dong: ";
	cin >> p.ntn.thang;

	cout << "\nNhap nam hop dong: ";
	cin >> p.ntn.nam;
}

void Nhap_DS_ThueBao(DSThueBao dstb, int& n) {
	cout << "\nNhap n = ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thue bao thu " << i + 1 << ':';
		Nhap_1_ThueBao(dstb[i]);
	}
}

void Xuat_1_ThueBao(ThueBao p) {
	cout << setiosflags(ios::left)
		<< setw(8) << p.maThueBao
		<< setw(26) << p.hoTen
		<< setw(36) << p.diaChi
		<< setw(14) << p.soDT
		<< setw(2) << p.ntn.ngay
		<< "/"
		<< setw(2) << p.ntn.thang
		<< "/"
		<< setw(5) << p.ntn.nam;
}

void Xuat_DS_ThueBao(DSThueBao dstb, int n) {
	XuatTieuDe();
	for (int i = 0; i < n; i++) {
		cout << endl;
		Xuat_1_ThueBao(dstb[i]);
		
	}
}

void Tim_SDT_Ten(DSThueBao dstb, int n) {
	string ten;
	cout << "\nNhap ten can tim: ";
	getline(cin , ten);
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (ten.compare(dstb[i].hoTen) == 0) {
			Xuat_1_ThueBao(dstb[i]);
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
