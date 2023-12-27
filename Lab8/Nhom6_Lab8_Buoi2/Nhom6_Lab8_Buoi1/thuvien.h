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
	

	do {
		cout << "\nNhap ma so thue bao(gom 7 chu so): ";
		cin.ignore();
		cin >> p.maThueBao;
	} while (p.maThueBao / 1000000 < 1 || p.maThueBao / 1000000 >= 10);

	cout << "\nHo va ten: ";
	cin.ignore();
	getline(cin ,p.hoTen);

	cout << "\nDia chi: ";
	getline(cin ,p.diaChi);

	cout << "\nSo DT: ";
	getline(cin ,p.soDT);

	
	do {
		cout << "\nNhap ngay hop dong: ";
		cin >> p.ntn.ngay;
	} while (p.ntn.ngay > 31 || p.ntn.ngay <= 0);
	
	do {
		cout << "\nNhap thang hop dong: ";
		cin >> p.ntn.thang;
	} while (p.ntn.ngay > 12 || p.ntn.thang <= 0);
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
	for (int i = hoTen.length() - 1; i >= 0; i--) {
		if (hoTen[i] == ' ' || hoTen[i] == '_') {
			return hoTen.substr(i + 1);
		}
		
	}
	return hoTen;
}


void Tim_SDT_Ten(DSThueBao dstb, int n, string ten) {
	
	int dem = 0;
	
	for (int i = 0; i < n; i++) {
		if (ten.compare(TimTen(dstb[i].hoTen)) == 0) {
			Xuat_1_ThueBao(dstb[i]); cout << endl;
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
	cout << endl << "Nhap thong tin thue bao can thay doi: ";
	Nhap_1_ThueBao(dstb[timthuebao]);
}



///////////////////////////////////////////////////////////////////////

string TimSDT(string sdt) {
	int viTri = sdt.find('.');
	if (viTri != -1) {
		return sdt.substr(viTri + 1);
	}
	else {
		return "";
	}
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
//void ThongKe(DSThueBao dstb, int n) {
//	map<string, int> thongKe;
//	int x = 0;
//	for (int i = 0; i < n; i++) {
//		x = dstb[i].soDT.length() - TimSDT(dstb[i].soDT).length() - 1;
//		thongKe[dstb[i].soDT.substr(0, x)]++;
//	}
//
//	for (const auto& pair : thongKe) {
//		cout << setiosflags(iostream::left) << "\n" << setw(20) << pair.first << pair.second;
//	}
//}

///////////////////////////////////////////////////////////////////////////
struct ThongKe1
{
	string ma;
	int soluong;
};

typedef ThongKe1 DSThongKe[MAX];

void TK(DSThueBao dstb, int n)
{
	DSThongKe dstk = {};
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		string maVung = dstb[i].soDT.substr(0, dstb[i].soDT.find('.'));
		int d = -1;

		for (int j = 0; j < k; j++)
		{
			if (maVung == dstk[j].ma)
			{
				dstk[j].soluong++;
				d = j;
				break;
			}
		}

		if (d == -1)
		{
			dstk[k++] = { maVung, 1 };
		}
	}

	cout<<endl << setiosflags(ios::left) << setw(20) << "Ma" << "So Luong\n";
	for (int i = 0; i < k; i++)
	{
		cout << setiosflags(ios::left) << setw(20) << dstk[i].ma << dstk[i].soluong << endl;
	}
}