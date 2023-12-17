#define MAX 100

struct SinhVien {
	string maSo;
	string hoTenLot;
	string ten;
	string gioiTinh;
	double DTB;
	string lop;
	string xepLoai;
};

typedef SinhVien DanhSachSV[MAX];
void NhapDSSV(DanhSachSV dssv, int n);
void XuatDSSV(DanhSachSV dssv, int n);
void Nhap1SV(SinhVien& sv);
void Xuat1SV(SinhVien sv);
void XuatTieuDe();

void Nhap1SV(SinhVien& sv)
{
	cout << "\nNhap MaSo:";
	cin >> sv.maSo;

	cout << "\nNhap HoTen lot : ";
	cin.ignore();
	getline(cin, sv.hoTenLot);

	cout << "\nNhap ten :";
	cin.ignore();
	getline(cin, sv.ten);

	cout << "\nNhap gioi tinh (Nam la M, Nu la F) : ";
	cin >> sv.gioiTinh;

	cout << "\nDTB :";
	cin >> sv.DTB;

	cout << "Lop : ";
	cin >> sv.lop;

}

void Xuat1SV(SinhVien sv) {
	cout << "\n" << setiosflags(ios::left)
		<< setw(10) << sv.maSo
		<< setw(25) << sv.hoTenLot
		<< setw(25) << sv.ten
		<< setw(10) << sv.gioiTinh
		<< setw(10) << sv.DTB
		<< setw(10) << sv.lop
		<< setw(10) << sv.xepLoai << endl;
}


void XuatTieuDe()
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< setw(10) << "MSSV"
		<< setw(25) << "Ho"
		<< setw(25) << "Ten"
		<< setw(10) << "Gioi tinh"
		<< setw(10) << "DTB"
		<< setw(10) << "Lop"
		<< setw(8) << "XLoai";

}


void NhapDSSV(DanhSachSV dssv, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin sinh vien:" << i + 1;
		Nhap1SV(dssv[i]);
	}
}

void XuatDSSV(DanhSachSV dssv, int n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat1SV(dssv[i]);
	}
}

void HoanVi(SinhVien& a, SinhVien& b)
{
	SinhVien c = a;
	a = b;
	b = c;
}

void SapXepDS_GiamDTB(DanhSachSV dssv, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dssv[i].DTB < dssv[j].DTB)
				HoanVi(dssv[i], dssv[j]);
		}
	}
}

void SapXepDS_TangTen(DanhSachSV dssv, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (dssv[i].ten.compare(dssv[j].ten) == 1)
				HoanVi(dssv[i], dssv[j]);
			else if (dssv[i].ten.compare(dssv[j].ten)==0)
				if (dssv[i].hoTenLot.compare(dssv[j].hoTenLot)==1)
					HoanVi(dssv[i], dssv[j]);
		}
	}
}


void XepLoai(DanhSachSV dssv, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (dssv[i].DTB < 4)
			(dssv[i].xepLoai, "Kem");
		else if (dssv[i].DTB < 5.5)
			(dssv[i].xepLoai, "Yeu");
		else if (dssv[i].DTB < 7)
			(dssv[i].xepLoai, "TB");
		else if (dssv[i].DTB < 8.5)
			(dssv[i].xepLoai, "Kha");
		else if (dssv[i].DTB <= 10)
			(dssv[i].xepLoai, "Gioi");
	}
}
