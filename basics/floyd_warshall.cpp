#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int G[n][n], D[n][n], P[n][n];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> G[i][j];
			if(G[i][j] == -1) {
				D[i][j] = INT_MAX;
				P[i][j] = -1;
			} else {
				D[i][j] = G[i][j];
				P[i][j] = i;
			}
		}
	}
		
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[k][j];
				}
			}
		}
	}

	
	cout << "\nD\n";
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << D[i][j] << " ";
		} cout << endl;
	}
	
	cout << "\nP\n";
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << P[i][j] << " ";
		} cout << endl;
	}

	int src, dest;
	cin >> src >> dest;

	int idx = dest;
	
	cout << dest << " ";
	while(idx != -1 && idx != src) {
		cout << P[src][idx] << " ";
		idx = P[src][idx];
	} cout << endl;

	return 0;
}

