#include <bits/stdc++.h>
using namespace std;

int combine(int a, int b) {
	return __gcd(a, b);
}

void build(vector<int > &t, int a[], int l, int r, int v = 1) {
	if(l == r) {
		t[v] = a[l];
		return;
	}

	int mid = l + (r - l)/2;
	build(t, a, l, mid, 2*v);
	build(t, a, mid + 1, r, 2*v + 1);
	t[v] = combine(t[2*v], t[2*v + 1]);
	return;
}

int f(vector<int > &t, int ql, int qr, int tl, int tr, int v = 1) {
	if(ql == tl && qr == tr)
		return t[v];
	
	int mid = tl + (tr - tl) / 2;

	if(max(mid+1, qr) > qr)
		return f(t, ql, min(qr, mid), tl, mid, 2*v);
	
	if(ql > min(qr, mid))
		return f(t, max(mid+1, ql), qr, mid+1, tr, 2*v + 1);

	return combine(f(t, ql, min(qr, mid), tl, mid, 2*v), f(t, max(mid+1, ql), qr, mid+1, tr, 2*v + 1));
}

void update(vector<int > &t, int tl, int tr, int pos, int val, int v = 1) {
	if(tl == tr) {
		t[v] = val;
		return;
	}

	int mid = tl + (tr - tl)/2;
	if(pos <= mid)
		update(t, tl, mid, pos, val, 2*v);
	else
		update(t, mid+1, tr, pos, val, 2*v+1);
	t[v] = combine(t[2*v], t[2*v + 1]);
	return;
}

int main() {
	int n;
	cin >> n;

	int a[n];
	for(int i = 0; i < n; ++i) cin >> a[i];
	vector<int > t(n * 4, 0);
	build(t, a, 0, n-1);

	for(int i = 0; i < n*4; ++i) cout << t[i] << " "; cout << endl;

	int q;
	cin >> q;

	while(q--) {
		char ch;
		cin >> ch;

		if(ch == 'u') {
			int p, v;
			cin >> p >> v;
			update(t, 0, n - 1, p, v);
			for(int i = 0; i < n*4; ++i) cout << t[i] << " "; cout << endl;
		} else {
			int l, r;
			cin >> l >> r;
			cout << f(t, l, r, 0, n - 1) << endl;
		}
	}
	return 0;
}
