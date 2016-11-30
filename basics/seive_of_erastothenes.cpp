#include <bits/stdc++.h>
using namespace std;

vector<int > primes;
vector<bool > is_prime;

void create_primes(int n) {
	is_prime.resize(n + 1, 1);
	is_prime[1] = 0;
	
	/* i*i because it will search until upper_limit all possible factors*/
	for(int i = 2; i * i <= n; ++i) {  
		if(is_prime[i]) {
			for(int k = i * 2; k <= n; k += i) is_prime[k] = false;
		}
	}

	for(int i = 2; i <= n; ++i) {
		if(is_prime[i]) primes.push_back(i);
	}

	int total = primes.size();
	for(int i = 0; i < total; ++i) cout << primes[i] << " "; cout << endl;
}

int main() {
	int upper_limit;
	cin >> upper_limit;
	create_primes(upper_limit);
	return 0;
}

