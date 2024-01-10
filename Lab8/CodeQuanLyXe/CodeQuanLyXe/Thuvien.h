
#define MAX 100

struct ThongTinXe
{
	string banSoXe;
	string tenXe;
	int namSX;
	string hangSX;
	double giaMua;
};

typedef ThongTinXe DSQuanLyXe[MAX];

void TieuDe() {
	cout << endl << setiosflags(ios::left)
		<< setw(12) << "Ban So Xe"
		<< setw(10) << "Ten Xe"
		<< setw(8) << "Nam SX"
		<< setw(10) << "Hang SX"
		<< setw(15) << "Gia Mua";
}

bool KtraBienSoXe(DSQuanLyXe dsqlxe, int n, string bsx) {
	for (int i = 0; i < n; i++) {
		if (dsqlxe[i].banSoXe.compare(bsx)==0)
			return false;
	}
	return true;
}


string NhapBSX(DSQuanLyXe dsqlxe, int n)
{
	string bx;
	do
	{
		cin >> bx;
		if (!KtraBienSoXe(dsqlxe, n, bx))
		{
			cout << endl << "Nhap lai: ";
		}
		else {
			return bx;
		}


	} while (true);
}

void Nhap1Xe(ThongTinXe& tt, DSQuanLyXe dsqlxe, int n) {
	cout << endl;
	cout << "\Nhap ban so xe : ";
	tt.banSoXe = NhapBSX(dsqlxe, n);
	cout << "\nNhap ten xe : ";
	cin.ignore();
	getline(cin, tt.tenXe);

	cout << "\nNhap nam san xuat : ";
	cin >> tt.namSX;

	cout << "\nNhap hang san xuat : ";
	cin.ignore();
	getline(cin, tt.hangSX);

	cout << "\nNhap gia mua : ";
	cin >> tt.giaMua;

}

void Xuat1Xe(ThongTinXe tt) {
	cout << setiosflags(ios::left)
		<< setw(12) << tt.banSoXe
		<< setw(10) << tt.tenXe
		<< setw(8) << tt.namSX
		<< setw(10) << tt.hangSX
		<< setw(5) << tt.giaMua<<"Trieu";
}

void NhapDSXe(DSQuanLyXe dsqlxe, int& n) {
	for (int i = 0; i < n; i++) {
		cout << "\Thong Tin Xe So : " << i + 1;
		Nhap1Xe(dsqlxe[i], dsqlxe , n);
	}
}

void XuatDSXe(DSQuanLyXe dsqlxe, int n) {
	TieuDe();
	for (int i = 0; i < n; i++) {
		cout << endl;
		Xuat1Xe(dsqlxe[i]);
	}
}

//4. Tính tổng giá mua của tất cả xe có năm sản xuất ∈ [𝒙, 𝒚] (x, y là năm được nhập). 

double TongGiaXeCoNamXY(DSQuanLyXe dsqlxe, int n, int x, int y) {
	int tong=0;
	for (int i = 0; i < n; i++) {
		if (dsqlxe[i].namSX >= x && dsqlxe[i].namSX <= y)
			tong += dsqlxe[i].giaMua;
	}
	return tong;
}

//5. Tìm xe cuối cùng theo hãng sản xuất.
void TimXeTheoHang(DSQuanLyXe dsqlxe, int &n, string tenHang) {
	for (int i = n -1; i >= 0; i--) {
	//for(int i = n; i > n - 1; i--)
		if (tenHang == dsqlxe[i].hangSX) {
			Xuat1Xe(dsqlxe[i]);
			break;
		}
	}
	
}


//6. Sắp xếp danh sách xe giảm theo hãng xe, nếu hãng xe trùng sắp tăng theo giá mua.

void HoanVi(ThongTinXe& a, ThongTinXe& b) {
	ThongTinXe t;
	t = a;
	a = b;
	b = t;
}

void SapXepXeTheoHang(DSQuanLyXe dsqlxe, int n) {
	/*for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i -1; j++) {
			if (dsqlxe[j].hangSX<dsqlxe[j + 1].hangSX || dsqlxe[j].hangSX == dsqlxe[j + 1].hangSX && dsqlxe[j].giaMua > dsqlxe[j + 1].giaMua)
			{
				HoanVi(dsqlxe[j], dsqlxe[j + 1]);
			}
		}*/

	for(int i = 0; i < n - 1 ; i ++)
		for (int j = i + 1; j < n; j++) {
			if (dsqlxe[i].hangSX<dsqlxe[j].hangSX || dsqlxe[i].hangSX == dsqlxe[j].hangSX && dsqlxe[i].giaMua > dsqlxe[j].giaMua)
			{
				HoanVi(dsqlxe[i], dsqlxe[j]);
			}
		}
}


//7. Xóa tất cả xe theo năm sản xuất
void XoaXeTheoNamSX(DSQuanLyXe dsqlxe, int &n, int namXoa) {
	for (int i = 0; i < n; i++) {
		if (namXoa == dsqlxe[i].namSX) {
			for (int j = i ; j < n-1; j++) {
				dsqlxe[j] = dsqlxe[j + 1];
			}
			n--;
		}
	}
}



//8. In bảng thống kê số xe theo hãng sản xuất.

struct HangSanXuat
{
	string Hang;
};

typedef HangSanXuat DanhSachHang[MAX];

int TimKiemHang(DanhSachHang dsh, int n, string item)
{
	for (int i = 0; i < n; i++)
		if (dsh[i].Hang.compare(item) == 0)
			return i;
	return -1;
}

inline void InBangThongKeTheoHang(DSQuanLyXe dsqlxe, int n, DanhSachHang dsh)
{
	int ma = 0;
	int a[MAX] = {0};
	//Lay ds hang khong trung lap
	for (int i = 0; i < n; i++)
		if (TimKiemHang(dsh, ma, dsqlxe[i].hangSX) == -1)
		{
			dsh[ma].Hang = dsqlxe[i].hangSX;
			ma++;
		}
	//Thong ke theo ma vung
	for (int j = 0; j < n; j++)
	{
		int index = TimKiemHang(dsh, ma, dsqlxe[j].hangSX);
		if (index != -1) {
			a[index]++;
		}
		/*for (int k = 0; k < ma; k++)
		{
			if (dsh[k].Hang.compare(dsqlxe[j].hangSX) == 0) 
				a[k]++;
		}*/
	}
	//in ra
	for (int i = 0; i < ma; i++)
	{
		cout << dsh[i].Hang << " " << a[i] << endl;
	}
}