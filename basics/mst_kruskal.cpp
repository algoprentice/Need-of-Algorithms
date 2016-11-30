#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int > 
#define mp make_pair

struct Edge {
	int a, b, w;
};

bool com(const Edge &x, const Edge &y) {
	if(x.w < y.w) return true;
	return false;
}

vector<int > DS;
int root(int u) {
	if(DS[u] == u) return u;
	
	return DS[u] = root(DS[u]);
}

int join(int x, int y) {
	int rx = root(x);
	int ry = root(y);

	if(rx == ry) return 0;
	DS[rx] = ry;
	return 1;
}

int main() {
	int n;
	cin >> n;

	DS.clear();
	DS.resize(n+1);
	for(int i = 1; i <= n; ++i) DS[i] = i;

	int e; 
	cin >> e;

	Edge G[e];
	for(int i = 0; i < e; ++i) {
		cin >> G[i].a >> G[i].b >> G[i].w;
	}

	sort(G, G + e, com);

	long long sum = 0;
	for(int i = 0; i < e; ++i) {
		if(join(G[i].a, G[i].b)) {
			sum += G[i].w;
			printf("%d - %d::%d\n", G[i].a, G[i].b, G[i].w);
		}
	}

	cout << sum << endl;
	return 0;
}

