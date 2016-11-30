#include <bits/stdc++.h>
using namespace std;

void prefix(string &s, int n, vector<int > &P) {
	P[0] = 0;
	int i = 0, j = 1;

	while(j < n) {
		if(s[i] == s[j]) {
			i += 1;
			P[j] = i;
			j += 1;
		} else {
			if(i == 0) {
				P[j] = 0;
				j += 1;
			} else {
				i = P[i - 1];
			}
		}
	}

	return;
}

void match(string &t, vector<int > &f, string &p) {
	int lt = t.size(), lp = p.size();
	int p_ptr = 0, t_ptr = 0;
	
	while(t_ptr < lt) {
		if(t[t_ptr] == p[p_ptr]) {
			t_ptr += 1;
			p_ptr += 1;
			if(p_ptr == lp) {
				cout << (t_ptr - lp) << endl;
				p_ptr = f[lp - 1];
			}
		} else {
			if(p_ptr != 0) 
				p_ptr = f[p_ptr - 1];
			else 
				t_ptr += 1;
		}
	}

	return;
}

int main() {
	string text, pattern;
	cin >> text >> pattern;

	int n = pattern.size();
	vector<int > f(n, 0);

	prefix(pattern, n, f);
	for(int i = 0; i < n; ++i) cout << f[i] << " "; cout << endl;
	
	match(text, f, pattern);
	return 0;
}

