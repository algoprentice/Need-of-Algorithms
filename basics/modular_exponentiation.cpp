#include <bits/stdc++.h>
using namespace std;

/*
x^n % m
*/
long long f(long long x, long long n, long long m) { 
	long long res = 1;
	while(n > 0) {
		if(n & 1) {
			res *= x;
			res %= m;
		}
		x *= x;
		x %= m;
		n /= 2;
	}

	return res;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
	long long x, n, m;
	cin >> x >> n >> m;

	cout << f(x, n, m) << endl;
	}
	return 0;
}
