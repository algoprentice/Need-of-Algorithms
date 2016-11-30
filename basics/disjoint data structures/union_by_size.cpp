#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int > 
#define mp make_pair

vector<int > DS;
vector<int > nsize; /* Will tell how many node under this node, including itself. */
int root(int u) {
	if(DS[u] == u) return u;
	
	return DS[u] = root(DS[u]);
}

int join(int x, int y) {
	/* Union by size, also done here, to create balance */
	
	int rx = root(x);
	int ry = root(y);

	if(rx == ry) return 0;
	
	if(nsize[rx] > nsize[ry]) swap(rx, ry);
	nsize[ry] += nsize[rx];
	
	DS[rx] = ry;
	return 1;
}

int main() {
	int n;
	cin >> n;

	DS.clear();
	DS.resize(n+1);
	nsize.resize(n+1, 1);
	for(int i = 1; i <= n; ++i) DS[i] = i;
	
	/* Main Computation Goes Here */
	for(;;) {
		int a, b;
		cin >> a >> b;
		join(a, b);
		cout << "D:";for(int i = 1; i <= n; ++i) cout << root(DS[i]) << " "; cout << endl;
		cout << "S:";for(int i = 1; i <= n; ++i) cout << nsize[i] << " "; cout << endl;
	}
	return 0;
}

