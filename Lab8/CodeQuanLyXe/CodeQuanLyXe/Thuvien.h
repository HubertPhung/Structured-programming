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

void Nhap1Xe(ThongTinXe& tt) {
	cout << "\nNhap ban so xe : ";
	cin.ignore();
	getline(cin, tt.banSoXe);

	cout << "\nNhap ten xe : ";
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
		Nhap1Xe(dsqlxe[i]);
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
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i -1; j++) {
			if (dsqlxe[j].hangSX<dsqlxe[j + 1].hangSX || dsqlxe[j].hangSX == dsqlxe[j + 1].hangSX && dsqlxe[j].giaMua > dsqlxe[j + 1].giaMua)
			{
				HoanVi(dsqlxe[j], dsqlxe[j + 1]);
			}
		}
}


//7. Xóa tất cả xe theo năm sản xuất
void XoaXeTheoNamSX(DSQuanLyXe dsqlxe, int &n, int namXoa) {
	int temp = n;
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

int thongKeXeTheoHang(DSQuanLyXe dsqlxe, int n) {
	int soLuongXeTheoHang = 0; 
	int tongSoLuong = 0;

	for (int i = 0; i < n; i++) {
		soLuongXeTheoHang = 1;
		for (int j = i + 1; j < n; j++) {
			if (dsqlxe[i].hangSX == dsqlxe[j].hangSX) {
				soLuongXeTheoHang++;
			}
		}
	}
	return soLuongXeTheoHang;
}
void inThongKeHangSX(DSQuanLyXe dsqlxe, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Hang " << dsqlxe[i].hangSX << " : " << thongKeXeTheoHang(dsqlxe, n) << " xe" << endl;
		
	}
}