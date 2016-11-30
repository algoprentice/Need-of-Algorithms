#include <bits/stdc++.h>
using namespace std;

int fi(int n) {
	int re = n;
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0) re -= re/i;
		while(n % i == 0) n /= i;
	}

	if(n > 1) re -= re/n;
	return re;
}

int main() {
	int n;
	cin >> n;

	int re = fi(n);
	cout << re << endl;
	return 0;
}

