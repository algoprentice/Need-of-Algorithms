#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int >
#define mp make_pair

pii combine(pii a, pii b) {
	if(a.first == b.first)
		return mp(a.first, a.second + b.second);
	if(a.first < b.first)
		return a;
	else
		return b;
}

void build(vector<pii > &t, int a[], int l, int r, int v = 1) {
	if(l == r) {
		t[v] = mp(a[l], 1);
		return;
	}

	int mid = l + (r - l)/2;
	build(t, a, l, mid, 2*v);
	build(t, a, mid + 1, r, 2*v + 1);
	t[v] = combine(t[2*v], t[2*v + 1]);
	return;
}

pii f(vector<pii > &t, int ql, int qr, int tl, int tr, int v = 1) {
	if(ql == tl && qr == tr)
		return t[v];
	
	int mid = tl + (tr - tl) / 2;

	if(max(mid+1, qr) > qr)
		return f(t, ql, min(qr, mid), tl, mid, 2*v);
	
	if(ql > min(qr, mid))
		return f(t, max(mid+1, ql), qr, mid+1, tr, 2*v + 1);

	return combine(f(t, ql, min(qr, mid), tl, mid, 2*v), f(t, max(mid+1, ql), qr, mid+1, tr, 2*v + 1));
}

void update(vector<pii > &t, int tl, int tr, int pos, int val, int v = 1) {
	if(tl == tr) {
		t[v] = mp(val, 1);
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
	vector<pii > t(n * 4);
	build(t, a, 0, n-1);

	for(int i = 0; i < n*4; ++i) cout << t[i].first << " " << t[i].second << endl;

	int q;
	cin >> q;

	while(q--) {
		char ch;
		cin >> ch;

		if(ch == 'u') {
			int p, v;
			cin >> p >> v;
			update(t, 0, n - 1, p, v);
			for(int i = 0; i < n*4; ++i) cout << t[i].first << " " << t[i].second << endl;
		} else {
			int l, r;
			cin >> l >> r;
			pii temp = f(t, l, r, 0, n - 1);
			cout << temp.first << " " << temp.second << endl;
		}
	}
	return 0;
}
