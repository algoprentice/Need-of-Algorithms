#include <bits/stdc++.h>
using namespace std;

int n; //Starting from 1.
vector<vector<pair<int, int > > > G; //Undirected Weighted Graph

#define pii pair<int, int > 
#define mp make_pair

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

	vector<bool > V(n + 1, 0);
	vector<int > P(n + 1, -1);
	vector<int > D(n + 1, 1e9);

	int src = 1; //Source or root;
	D[src] = 0;

	set<pii > Q;
	Q.insert(mp(D[src], src));
	int vertex = 0; // MST will have n vertices and n-1 edges.

	while(!Q.empty()) {
		pii temp = *(Q.begin()); Q.erase(Q.begin());
		int d = temp.first;
		int u = temp.second;

		V[u] = 1;
		vertex++;

		for(typeof(G[u].begin()) it = G[u].begin(); it != G[u].end(); it++) {
			temp = *it;
			int v = temp.first;
			int w = temp.second;

			if(!V[v] && D[v] > w) {
				Q.erase(mp(D[v], v));
				D[v] = w;
				Q.insert(mp(D[v], v));
				P[v] = u;
			}
		}
	}

	if(vertex == n) {
		for(int i = 1; i <= n; ++i) 
			printf("%d - %d :: %d\n", P[i], i, D[i]);
	} else {
		printf("MST does not exist!!\n");
	}

	return 0;
}

