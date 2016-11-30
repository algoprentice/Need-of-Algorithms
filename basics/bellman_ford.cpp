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
	int src = 0;
	d[src] = 0;

	for(int j = 1; j < n; ++j) {
		for(int i = 0; i < e; ++i) {
			if(d[G[i][1]] > d[G[i][0]] + G[i][2]) {
				d[G[i][1]] = d[G[i][0]] + G[i][2];
			}
		}
	}

	bool neg = 0;
	for(int i = 0; i < e; ++i) {
		if(d[G[i][1]] > d[G[i][0]] + G[i][2]) {
			neg = 1;
			break;
		}
	}
	
	if(neg)
		cout << "Negative Cycle\n";
	else {
		for(int i = 0; i < n; ++i) printf("V: %d D: %d\n", i, d[i]);
	}

	return 0;
}
