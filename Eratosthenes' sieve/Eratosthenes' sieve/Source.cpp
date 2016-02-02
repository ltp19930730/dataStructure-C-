//author:Tianpei Luo
//Eratosthenes' sieve 
//date: 1/25/2016
#include<iostream>
#include<math.h>
#include <time.h>
#include<cstdint>
#include<vector>
using namespace std;
bool isPrime(int n) {
	if (n % 2 == 0)
		return false;
	for (int i = 3; i < n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}
int main() {
	for (int i = 2; i <= 11; i++)
		if (isPrime(i)) cout << i << ',';
}