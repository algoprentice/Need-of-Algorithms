/*
For [any E V E N] integer n (n ≥ 4) there exist two prime numbers p1 and p2 such that p1 + p2 = n. 
In a problem we might need to find the number of essentially different pairs (p1, p2), 
satisfying the condition in the conjecture for a given even number n (4 ≤ n ≤ 2 15). 
(The word ‘essentially’ means that for each pair (p1, p2) we have p1 ≤p2.)
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool > is_prime;
void sieve() {
	int limit = 100000;

	is_prime.resize(limit + 1, true);
	is_prime[1] = false;

	for(int i = 2; i * i <= limit; ++i) {
		if(is_prime[i]) {
			for(int j = 2*i; j <= limit; j += i) {
				is_prime[j] = false;
			}
		}
	}
	
//	for(int i = 2; i <= limit; ++i) if(is_prime[i]) cout << i << " "; cout << endl;
	return;
}

int main() {
	sieve();

	int n;
	cin >> n;
	
	int cnt = 0;
	for(int i = 2; i <= ceil(n/2.0); ++i) {
		if(is_prime[i] && is_prime[n-i]) {
			cout << i << " " << (n-i) << endl;
			cnt++;
		}
	}
	
	cout << cnt << endl;
	return 0;
}
