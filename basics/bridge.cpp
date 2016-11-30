#include <bits/stdc++.h>
using namespace std;

void bridge(vector<vector<int > > &G, int n, int u, vector<int > &vtime, vector<int > &ltime, vector<int > &used, int timer, int pa = -1) {
	used[u] = true;
	vtime[u] = ltime[u] = timer++;

	for(vector<int >::iterator it = G[u].begin(); it != G[u].end(); it++) {
		if(*it != pa) {
			if(used[*it]) {
				ltime[u] = min(ltime[u], vtime[*it]);
			} else {
				bridge(G, n, *it, vtime, ltime, used, timer, u);
				if(vtime[u] < ltime[*it]) {
					cout << "Bridge: " << u << " " << *it << endl;
				}
				ltime[u] = min(ltime[u], ltime[*it]);
			}
		}
	}

	return;
}

int main() {
	int n, e;
	cin >> n >> e;

	vector<vector<int > > G(n);
	while(e--) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	/*
	    vtime - time when visited
		ltime - minimum vtime of adj. vertices
		used - whether visited or not
	*/
	vector<int > vtime(n, -1), ltime(n, -1), used(n, 0);
	int timer = 1;

	int src = 0;
//	vtime[src] = 1;
//	ltime[src] = 1;
//	used[src] = 1;

	bridge(G, n, src, vtime, ltime, used, timer);
	return 0;
}

