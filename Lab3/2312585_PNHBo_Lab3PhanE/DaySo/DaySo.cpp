/*================================
1. Nap thu vien
==================================*/
#include<iostream>
#include<conio.h>
using namespace std;
/*=========================================
2. Dinh nghia hang va kieu du lieu moi
===========================================*/



/*=========================================
3. Khai bao nguyen mau ham
===========================================*/

int DaySo_a_for(int n);
int DaySo_a_while(int n);
int DaySo_a_do_while(int n);
int DaySo_b_for(int n);
int DaySo_b_while(int n);
int DaySo_b_do_while(int n);
int DaySo_c_for(int n);
int DaySo_c_while(int n);
int DaySo_c_do_while(int n);
int DaySo_d_for(int n);
int DaySo_d_while(int n);
int DaySo_d_do_while(int n);
int DaySo_e_for(int n);
int DaySo_e_while(int n);
int DaySo_e_do_while(int n);

/*=========================================
4. Ham main
===========================================*/
int main()
{
	int n;
	cout << "Nhap vào N: "; 
	cin >> n;
	cout << endl << "a) for" << endl;
	DaySo_a_for(n);
	cout << endl << "a) while" << endl;
	DaySo_a_while(n); 
	cout << endl << "a) do while" << endl;
	DaySo_a_do_while(n); 
	cout << endl << "b) for" << endl;
	DaySo_b_for(n); 
	cout << endl << "b) while" << endl;
	DaySo_b_while(n); 
	cout << endl << "b) do while" << endl;
	DaySo_b_do_while(n); 
	cout << endl << "c) for" << endl;
	DaySo_c_for(n); 
	cout << endl << "c) while" << endl;
	DaySo_c_while(n); 
	cout << endl << "c) do while" << endl;
	DaySo_c_do_while(n); 
	cout << endl << "d) for" << endl;
	DaySo_d_for(n); 
	cout << endl << "d) while" << endl;
	DaySo_d_while(n); 
	cout << endl << "d) do while" << endl;
	DaySo_d_do_while(n); 
	cout << endl << "e) for" << endl;
	DaySo_e_for(n); 
	cout << endl << "e) while" << endl;
	DaySo_e_while(n); 
	cout << endl << "e) do while" << endl;
	DaySo_e_do_while(n);
	_getch();
	return 1;
}

/*=========================================
5. Dinh nghia ham
===========================================*/

int DaySo_a_for(int n) {
	double s = 0;
	for (int i = 1; i <= n; i++) {
		s = s + ((double)1 / i);
	}
	cout << "N = " << n << " | S = " << s  << endl;

	return 0;
}

int DaySo_a_while(int n) {
	double s = 0;
	int i = 1;
	while (i <= n) {
		s = s + ((double)1 / i);
		i++;
	}
	cout << "N = " << n << " | S = " << s  << endl;

	return 0;
}

int DaySo_a_do_while(int n) {
	double s = 0;
	int i = 1;
	do {
		s = s + ((double)1 / i);
		i++;
	} while (i <= n);
	cout << "N = " << n << " | S = " << s <<  endl;

	return 0;
}

int DaySo_b_for(int n) {
	double s = 0;
	for (int i = 1; i <= n; i++) {
		s = s + ((i + (double)1) / (i * i));
	}
	cout << "N = " << n << " | S = " << s <<  endl;

	return 0;
}

int DaySo_b_while(int n) {
	double s = 0;
	int i = 1;
	while (i <= n) {
		s = s + ((i + (double)1) / (i * i));
		i++;
	}
	cout << "N = " << n << " | S = " << s <<  endl;

	return 0;
}

int DaySo_b_do_while(int n) {
	double s = 0;
	int i = 1;
	do {
		s = s + ((i + (double)1) / (i * i));
		i++;
	} while (i <= n);
	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_c_for(int n) {
	double s = 0;
	for (int i = 1; i <= n; i++) {
		s = s + (((((double)-1) * i) * i) / i + (double)1);
	}
	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_c_while(int n) {
	double s = 0;
	int i = 1;
	while (i <= n) {
		s = s + (((((double)-1) * i) * i) / i + (double)1);
		i++;
	}
	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_c_do_while(int n) {
	double s = 0;
	int i = 1;
	do {
		s = s + (((((double)-1) * i) * i) / i + (double)1);
		i++;
	} while (i <= n);

	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_d_for(int n) {
	double s = 0;
	for (int i = 1; i <= n; i++) {
		s = s + ((double)1 / (i * (i + 1)));
	}
	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_d_while(int n) {
	double s = 0;
	int i = 1;
	while (i <= n) {
		s = s + ((double)1 / (i * (i + 1)));
		i++;
	}
	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_d_do_while(int n) {
	double s = 0;
	int i = 1;
	do {
		s = s + ((double)1 / (i * (i + 1)));
		i++;
	} while (i <= n);

	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_e_for(int n) {
	double s1 = 1;
	double s = 0;
	for (int i = 1; i <= n; i++) {
		s1 = s1 * i;
		s = s + s1;
	}
	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_e_while(int n) {
	double s1 = 1;
	double s = 0;
	int i = 1;
	while (i <= n) {
		s1 = s1 * i;
		s = s + s1;
		i++;
	}
	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}

int DaySo_e_do_while(int n) {
	double s1 = 1;
	double s = 0;
	int i = 1;
	do {
		s1 = s1 * i;
		s = s + s1;
		i++;
	} while (i <= n);

	cout << "N = " << n << " | S = " << s << endl;

	return 0;
}
