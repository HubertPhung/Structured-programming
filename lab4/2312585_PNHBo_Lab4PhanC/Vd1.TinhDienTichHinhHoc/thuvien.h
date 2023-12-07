/*=================================================================================
* Định nghĩa các hằng số và kiểu dữ liệu mới
==================================================================================*/
#define PI 3.1415926

/*=================================================================================
* Khai báo nguyên mẫu các hàm xử lý
==================================================================================*/
double DienTichHinhVuong(double Canh);
double DienTichHinhChuNhat(double dai, double rong);
double DienTichTamGiac(double a, double b, double c);
double DienTichHinhTron(double banKinh);


/*=================================================================================
* Định nghĩa các hàm xử lý
==================================================================================*/

// Định nghĩa hàm tính diện tích hình vuông
// Input : canh = Độ dài cạnh hình vuông
// Output : Diện tích hình vuông
double DienTichHinhVuong(double canh) {
	return canh * canh;
}

// Định nghĩa hàm tính diện tích hình chữ nhật
// Input : dai = kích thước chiều dài của HCN
//		   rong = kích thước chiều rộng của HCN
//Output : Diện tích HCN

double DienTichHinhChuNhat(double dai, double rong) {
	return dai * rong;
}

// Định nghĩa hàm tính diện tích tam giác
// input : a = Độ dài cạnh a
//		   b = Độ dài cạnh b
//		   c = Độ dài cạnh c
// Output : Diện tích hình tam giác
double DienTichTamGiac(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return  sqrt(p * (p - a) - (p - b) * (p - c));
}

// Định nghĩa hàm tính diện tích hình tròn
// Input : banKinh = Độ dài bán kính hình tròn
// Output : Diện tích hình tròn
double DienTichHinhTron(double banKinh) {
	return PI * banKinh * banKinh;
}


