#include <bits/stdc++.h>
using namespace std;

void f(string &text, vector<long long > &hash, vector<long long > &power) {
	int n = text.size();
	hash.resize(n, 0);
	power.resize(n, 0);

	hash[0] = text[0] - 'a';
	power[0] = 1;

	for(int i = 1; i < n; ++i) {
		hash[i] = hash[i-1] * 33 + (text[i] - 'a');
		power[i] = power[i-1] * 33;
	}

	return;
}

void findo(string &text, string &pattern, vector<long long > &hash, vector<long long> &power) {
	int lt = text.size(), lp = pattern.size();
	
	if(lp > lt) return;

	long long patternHash = pattern[0] - 'a';
	for(int i = 1; i < lp; ++i)
		patternHash = (patternHash * 33) + (pattern[i] - 'a');
	
	long long textHash = hash[lp - 1];
	if(textHash == patternHash) cout << "0\n";

	for(int i = 1; i <= lt - lp; ++i) {
		textHash = hash[i + lp - 1] - hash[i - 1] * power[lp];
		if(textHash == patternHash)
			cout << i << endl;
	}
}

int main() {
	string text, pattern;
	cin >> text >> pattern;

	vector<long long > hash, power;
	f(text, hash, power);
		
	int n = text.size();
	for(int i = 0; i < n; ++i) printf("%d: %lld %lld\n", i, hash[i], power[i]);
	findo(text, pattern, hash, power);
	return 0;
}

