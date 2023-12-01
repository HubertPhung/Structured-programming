/*=================================================================================
* Định nghĩa các hằng số và kiểu dữ liệu mới
==================================================================================*/
#define		BIN			2	
#define		OCT			8
#define		HEX			16
#define		SEV			7


/*=================================================================================
* Khai báo nguyên mẫu các hàm xử lý
==================================================================================*/
void Xuat(int so);
unsigned int TimLuyThua(unsigned int b, unsigned int n);
void DoiCoSo(unsigned int n, unsigned int b);

/*=================================================================================
* Định nghĩa các hàm xử lý
==================================================================================*/

//Định nghĩa hàm void Xuat(int so) để xuất 1 chữ số (hoặc chữ cái nếu so>9) ra 
//màn hình.

void Xuat(int so)
{
    if ((so >= 0) && (so <= 9)) cout << so;
    else {
        switch (so) {
        case 10: cout << "A";
        case 11: cout << "B";
        case 12: cout << "C";
        case 13: cout << "D";
        case 14: cout << "E";
        case 15: cout << "F";
        }
    }
    return;
}
//Định nghĩa hàm unsigned int TimLuyThua(unsigned int b, unsigned int n) để
//tìm số nguyên lớn nhất nhỏ hơn hoặc bằng n và là lũy thừa của b.
unsigned int TimLuyThua(unsigned int b, unsigned int n)
{
    unsigned int v = b, i = 1;
    while (v <= n) // Lap cho den khi v lon hon n hoac bang b
    {
        for (int j = 1; j <= i; j++)
            v = v * b;
    }
    return v;
}
/*Định nghĩa hàm void DoiCoSo(unsigned int n, unsigned int b) để thực hiện việc
đổi cơ số.
o B1. Gán v = TimLuyThua(b, n).
o B2. Kiểm tra n < v hay n >= v.
+ Nếu n < v, gọi hàm Xuat(0);
+ Nếu n >= v, gán so = n / v rồi gọi hàm Xuat(so). Cập nhật n = n – so * v.
o B3. Gán v = v / b. Nếu v > 0 thì quay lại B2. Ngược lại thì dừng thuật toán.
Ví dụ: Cho n = 12609, b = 8, ta tính được v = 4096 = 84
. Các bước đổi được tóm tắt*/
void DoiCoSo(unsigned int n, unsigned int b) {
    unsigned int v = TimLuyThua(b, n);
    unsigned int so;
    // lap lai cho den khi v bang 0
    while (v > 0) {
        // Kiem tra n < v hay n >= v
        if (n < v) {
            Xuat(0); // Neu n < v, goi ham Xuat(0)
        }
        else if (n >= v) { // Neu n >= v
            so = n / v;
            Xuat(so);
            n = n - so * v; // Cap nhat n = n - so * v
        }
        v = v / b; // Cap nhat v = v / b
    }
}