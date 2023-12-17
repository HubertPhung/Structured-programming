#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomX() {
	srand(time(NULL));
	int unsigned X = rand() % (50 - 2 + 1) + 2;
	return X;
}
int RandomY() {
	srand(time(NULL));
	int unsigned Y = rand() % (50 - 9 + 1) + 9;
	return Y;
}
int RandomZ() {
	srand(time(NULL));
	int unsigned Z = rand() % (50 - 5 + 1) + 5;
	return Z;
}
char RandomK(char K) {
	srand(time(NULL));
	int unsigned K = rand() % (50 - 5 + 1) + 5;
	return K;
}

int main() {
	char k;
	cout << RandomX<<" + "<< RandomY<< " "
	return 0;
}