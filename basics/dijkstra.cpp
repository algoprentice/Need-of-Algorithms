#include <bits/stdc++.h>
using namespace std;

int n; //Starting from 1.
vector<vector<pair<int, int > > > G; //Undirected Weighted Graph

#define pii pair<int, int > 
#define mp make_pair

class comp {
	public:
	bool operator() (const pii &a, const pii &b) {
		if(a.second >= b.second) return true;
		return false;
	}
};

int main() {
	cin >> n;

	G.resize(n+1);
	int edge;
	cin >> edge;

	while(edge--) {
		int a, b, w;
		cin >> a >> b >> w;
		G[a].push_back(mp(b, w));
		G[b].push_back(mp(a, w));
	}

	vector<int > P(n + 1, -1);
	vector<int > D(n + 1, 1e9);

	int src = 0; //Source or root;
	D[src] = 0;

	priority_queue<pii, vector<pii >, comp > Q;
	Q.push(mp(D[src], src));

	while(!Q.empty()) {
		pii temp = Q.top(); Q.pop();
		int d = temp.first;
		int u = temp.second;

		if(d > D[u]) continue;


		for(typeof(G[u].begin()) it = G[u].begin(); it != G[u].end(); it++) {
			temp = *it;
			int v = temp.first;
			int w = temp.second;

			if(D[v] > w + D[u]) {
				D[v] = w + D[u];
				Q.push(mp(D[v], v));
				P[v] = u;
			}
		}
	}

	for(int i = 0; i < n; ++i) 
		printf("%d -> %d :: %d\n", P[i], i, D[i]);

	return 0;
}

