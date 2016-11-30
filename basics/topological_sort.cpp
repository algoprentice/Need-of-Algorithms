#include <bits/stdc++.h>
using namespace std;

vector<vector<int > > G;
vector<int > color;

int dfs(int u, vector<int > &ans) {
	color[u] = 1;
	for(vector<int >::iterator it = G[u].begin(); it != G[u].end(); it++) {
		if(color[*it] == 1)  //Cycle
			return -43;
		else if(color[*it] == 0)  {//Unvisited 
			int response = dfs(*it, ans);
			if(response == -43) 
				return response;
		}
	}
	
	color[u] = 2;  //Leaving vertex with color 2 in cycle since they were already checked in some other path.
	ans.push_back(u);
	return 1;
}

void topo(int v) {
	vector<int > ans;
	for(int i = 1; i <= v; ++i) {
		if(color[i] == 0) {
			int response = dfs(i, ans);
			if(response == -43)
				return;
		}
	}

	reverse(ans.begin(), ans.end());
	for(vector<int >::iterator it = ans.begin(); it != ans.end(); it++) cout << *it << " "; cout << endl;
	return;
}

int main() {
	int edge, vertex; //Index 1.
	cin >> vertex >> edge;

	G.resize(vertex + 1);
	color.resize(vertex + 1, 0);

	while(edge--) {
		int pr, ch;
		cin >> pr >> ch;
		G[pr].push_back(ch);
	}

	topo(vertex);
	return 0;
}

