#include <bits/stdc++.h>
using namespace std;

void compute(vector<int > &z, string &s) {
	int l = 0, r = 0, n = s.length();
	z[0] = 0;

	for(int k = 1; k < n; ++k) {
		if(k > r) {
			l = r = k;
			while(r < n && s[r] == s[r - l]) r++;  //Comparing at initial stage, creating z-box
			z[k] = r - l;
			r--;
		} else {
			int k1 = k - l;
			if(z[k1] < r-k+1) {
				z[k] = z[k1];       //If index in range of z-box [l, r] just copy
			} else {
				l = k;
				while(r < n && s[r] == s[r - l]) r++;  
				z[k] = r - l;    //If index out of range, check ahead if match or not.
				r--;
			}
		}
	}
}

int main() {
	string s;
	cin >> s;

	vector<int > z(s.length());
	compute(z, s);
	for(int i = 0; i < s.length(); ++i) cout << z[i] << " "; cout << endl;
	return 0;
}

