#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, e;
	cin >> n >> e;

	int G[e][3];
	for(int i = 0; i < e; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		G[i][0] = a;
		G[i][1] = b;
		G[i][2] = w;
	}

	/*
	    - Relaxing each edge v-1 times.
		- At vth iteration if there is still any change then 
		  negative cycle exist.
	*/
	vector<int > d(n, 1e9);
	vector<int > p(n, -1);
	
	int src = 0;
	d[src] = 0;

	for(int j = 1; j < n; ++j) {
		for(int i = 0; i < e; ++i) {
			if(d[G[i][1]] > d[G[i][0]] + G[i][2]) {
				d[G[i][1]] = d[G[i][0]] + G[i][2];
				p[G[i][1]] = G[i][0];
			}
		}
	}

	int neg = 0;
	for(int i = 0; i < e; ++i) {
		if(d[G[i][1]] > d[G[i][0]] + G[i][2]) {
			p[G[i][1]] = G[i][0];
			neg = G[i][1];
			break;
		}
	}
	
	if(!neg)
		cout << "No negative cycle.\n";
	else {
		vector<int > path;
		for(int curr = neg; ; curr = p[curr]) {
			path.push_back(curr);
			if(curr == neg && path.size() > 1) break;
		}

		reverse(path.begin(), path.end());
		cout << "Negative Cycle: ";
		for(int i = 0; i < path.size(); ++i)
			cout << path[i] << " "; 
		cout << endl;
	}

	return 0;
}
