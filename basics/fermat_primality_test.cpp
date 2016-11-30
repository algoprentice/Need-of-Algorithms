#include <bits/stdc++.h>
using namespace std;

long long modulo(long long a, long long b, long long m) {
	long long r = 1;
	while(b) {
		if(b & 1) {
			r *= a;
			r %= m;
		}

		a *= a;
		a %= m;
		b /= 2;
	}

	return r;
}

bool fermat(long long p, long long itr = 4) {
	if(p == 1) return 0;
	
	while(itr--) {
		long long a = rand() % (p-1) + 1;
		if(modulo(a, p-1, p) != 1) return false;	
	}

	return true;
}

int main() {
	for(;;) {
		long long n;
		cin >> n;
		cout << fermat(n) << endl;
	}
	return 0;
}

