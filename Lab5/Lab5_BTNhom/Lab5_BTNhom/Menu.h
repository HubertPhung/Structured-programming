//Khai bao nguyen mau
void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int chon, DaySo a, int& n);


//Dinh nghia ham
void XuatMenu()
{
	cout << "\n========================Menu===================";
	cout << "\n1. Tim phan tu max trong day";
	cout << "\n15. Tinh tong";
	cout << "\n3. Kiem tra day chua so chan hay khong?";
	cout << "\n0. Thoat chuong trinh";

	cout << "\n===============================================";
}

int ChonMenu(int somenu)
{
	int chon;
	do {

		cout << "\nNhap chon [0..." << somenu << "]=";
		cin >> chon;
		if (0 <= chon && chon <= somenu)
			break;

	} while (1);
	return chon;
}

void XuLyMenu(int chon, DaySo a, int& n)
{
	int kq;
	switch (chon)
	{
	case 1:
		cout << "\n1. Tim phan tu max trong day";
		cout << "\nMang la:";
		XuatMang(a, n);
		kq = TimMax(a, n);
		cout << "\nPhan tim max:" << kq;
		break;
	case 15:
		kq = TinhTong(a, n);
		cout << "\n15. Tong cac chu so co 2 so la " << kq;
		
		break;
	case 3:
		cout << "\n3. Kiem tra day chua so chan hay khong?";

		break;
	case THOAT:
		cout << "\n0. Thoat chuong trinh";

		break;
	default:
		break;
	}
	_getch();
}