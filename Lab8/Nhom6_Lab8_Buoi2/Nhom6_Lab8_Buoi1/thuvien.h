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



void DocFile(DSThueBao dstb, int& n, string filename)
{
	//fstream io(filename);
	//ofstream out(filename);	
	ifstream in(filename);
	n = 0;

	if (!in)
	{
		cout << "\nLoi mo file";
		return;
	}
	ThueBao tb;
	while (!in.eof())
	{
		in >> tb.maThueBao;
		in >> tb.hoTen;
		in >> tb.diaChi;
		in >> tb.soDT;
		in >> tb.ntn.ngay;
		in >> tb.ntn.thang;
		in >> tb.ntn.nam;
		dstb[n++] = tb;
	}
	
	in.close();
}


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

string TimTen(string hoTen) {
	int viTri = 0;
	int doDai = 0;
	for (int i = hoTen.length() - 1; i >= 0; i--) {
		if (hoTen[i] == ' ' || hoTen[i] == '_') {
			viTri = i;
			break;
		}
		doDai++;
	}
	return hoTen.substr(viTri + 1, doDai);
}

void Tim_SDT_Ten(DSThueBao dstb, int n, string ten) {
	
	int dem = 0;
	
	for (int i = 0; i < n; i++) {
		if (ten.compare(TimTen(dstb[i].hoTen)) == 0) {
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

///////////////////////////////////////////////////////////////////////
void XoaTheoTenTB(DSThueBao dstb, int& n, string tenTb) {
	for (int i = 0; i < n; i++) {
		if (TimTen(dstb[i].hoTen).compare(tenTb) == 0) {
			for (int j = i; j < n - 1; j++) {
				dstb[j] = dstb[j + 1];
			}
			n--;
		}
	}
}


/////////////////////////////////////////////////////
int TimMaThueBao(DSThueBao dstb, int n)

{
	int temp;
	int vitri = -1;
	cout << "\nNhap ma thue bao: ";
	cin >> temp;
	for (int i = 0; i < n; i++)
	{
		
		if (dstb[i].maThueBao == temp)
			vitri = i;
	}
	return vitri;
}

void CapNhat(DSThueBao dstb, int n) {
	
	int timthuebao = TimMaThueBao(dstb, n);
	if (timthuebao == -1)
	{
		cout << "\nKo co ma thue bao ban can tim"; return;
	}
	cout << endl << timthuebao;
	ThueBao tb;
	Nhap_1_ThueBao(tb);
	dstb[timthuebao] = tb;
}



///////////////////////////////////////////////////////////////////////

string TimSDT(string sdt) {

	int viTri;
	int doDai = 0;
	for (int i = 0; i < sdt.length() - 1; i++) {
		if (sdt[i] == '.')
		{
			viTri = i; 
			break;
		}
		doDai++;
	}
	return sdt.substr(viTri + 1, sdt.length() - (doDai));
}


void SapXepTheoSDT(DSThueBao dstb, int n) {
	
	int dk;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			dk = (TimTen(dstb[i].hoTen).compare(TimTen(dstb[j].hoTen))) == 1 || (TimTen(dstb[i].hoTen).compare(TimTen(dstb[j].hoTen)) == 0)  && (TimSDT(dstb[i].soDT).compare(TimSDT(dstb[j].soDT)) == -1);
			if (dk)
				HoanVi(dstb[i], dstb[j]);
		}
	
}

///////////////////////////////////////////////////////////
void ThongKe(DSThueBao dstb, int n) {
	map<string, int> thongKe;
	int x = 0;
	for (int i = 0; i < n; i++) {
		x = dstb[i].soDT.length() - TimSDT(dstb[i].soDT).length() - 1;
		thongKe[dstb[i].soDT.substr(0, x)]++;
	}

	for (const auto& pair : thongKe) {
		cout << setiosflags(iostream::left) << "\n" << setw(20) << pair.first << pair.second;
	}
}