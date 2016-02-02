#include<iostream>
#include <fstream>
#include<stdlib.h>
using namespace std;


int powermod(int x, int n, int m) {
	int prod = 1;
	if (n == 1) {
		return x%m;
	}
	while (n > 0) {
		if (n % 2 != 0) {
			prod = (prod*x) % m;
		}
		x = (x*x) % m;
		n = n / 2;
	}
	return prod*x;
}

bool Witness(int a, int n,int d,int s) {
	cout << d << "  " << s << endl;
	int x = powermod(a, d, n);
	int k = 0;
	if (x != 1 && x != n - 1) {
		return true;
	}
	for (int i = 1; i < s; i++) {
		x = (x*x) % n;	
		if (x == 1) {
			return false;
		}
		if (x == n - 1) {
			return true;
		}
	}
	return false;
}

bool Miller0Rabin(int n, int Testtimes) {
	if (n < 2){
		return false;
	}
	if (n != 2 && n % 2 == 0){
		return false;
	}
	int d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		d /= 2;
		s++;
	}


	for (int i = 1; i <= Testtimes; i++) {
		int a = rand() % (n - 2) + 2;
		//generate a random number from 1 to n-1
		if (!Witness(a, n,d,s)) {
			return false;
		}
	}
		return true;
	
}

int main() {
	fstream file;
	int testNum;
	int testTime = 5;
	file.open("hw2.dat");
	if (!file) {
		cout << "open file fail!!" << endl;
		return -1;
	}
	while (file >> testNum) {
	
		if (Miller0Rabin(testNum, testTime)) {
			cout << testNum << " is prime" << endl;
		}
		else {
			cout << testNum << " is not prime" << endl;
		}
	}

	return 0;
}