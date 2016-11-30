#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int > 
#define mp make_pair

vector<int > DS;
vector<int > ranka;
int root(int u) {
	if(DS[u] == u) return u;
	
	return DS[u] = root(DS[u]);
}

int join(int x, int y) {
	int rx = root(x);
	int ry = root(y);

	if(rx == ry) return 0;
	
	if(ranka[rx] > ranka[ry]) swap(rx, ry);
	if(ranka[rx] == ranka[ry]) ranka[ry]++;
	
	DS[rx] = ry;
	return 1;
}

int main() {
	int n;
	cin >> n;

	DS.clear();
	DS.resize(n+1);
	ranka.resize(n+1, 0);
	for(int i = 1; i <= n; ++i) DS[i] = i;
	
	/* Main Computation Goes Here */
	for(;;) {
		int a, b;
		cin >> a >> b;
		join(a, b);
		cout << "D:";for(int i = 1; i <= n; ++i) cout << root(DS[i]) << " "; cout << endl;
		cout << "R:";for(int i = 1; i <= n; ++i) cout << ranka[i] << " "; cout << endl;
	}
	return 0;
}

