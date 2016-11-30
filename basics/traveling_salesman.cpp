#include <bits/stdc++.h>
using namespace std;

/*
    Code Coet - Swapnil Jain 
    Enrollment - ISM2013004
*/

void subset(int n) {
	/* Function for printing sets. */
	for(int i = 0; i < n; ++i) {
		if(n & (1 << i)) printf("%d ", i+1);
	}
}

int main() {
	int v;
	cin >> v;

	int G[v][v]; /* Complete Graph */
	for(int i = 0; i < v; ++i) for(int j = 0; j < v; ++j) cin >> G[i][j];

	int n = v - 1; /* Neglecting Starting Vertex */
	int l = (1 << n); /* Total Subsets */

	int D[v][l]; /* Distance Matrix... D[vertices][subsets]... distance to vertex v from source s via subset S. */
	int P[v][l]; /* Parent Matrix */
	
	for(int i = 0; i < v; ++i) for(int j = 0; j < l; ++j) D[i][j] = 1e9;

	for(int i = 0; i < v; ++i) D[i][0] = G[0][i]; /* Distance from source to vertex i via empty set(0) ..D[i][0] */

	/*
	  Traveling Salesman Problem Simulation
	*/
	printf("\n---------------- ROUTING TABLE -----------------\n");
	printf("Vertex\tSubset\tDistance\n");
	for(int i = 1; i < l - 1; ++i) {  /* Leaving Final State */
		vector<int > vns; /* Vertex not present in subset */
		for(int b = 0; b < n; ++b) {
			if(!(i & (1 << b))) vns.push_back(b+1); /* b=0 ==> 1, b=1 ==> 2... */
		}

		for(typeof(vns.begin()) it = vns.begin(); it != vns.end(); it++) {
			for(int b = 0; b < n; ++b) {
				if(i & (1 << b)) {
					int val = G[b+1][*it] + D[b+1][i ^ (1 << b)];
					
					if(val < D[*it][i]) {
						D[*it][i] = val;
						P[*it][i] = b+1;
					}
					
					
					printf("%d\t", *it);
					subset(i);
					printf("\t");
					printf("%d\t%d\n", D[*it][i], P[*it][i]);
				}
			}
		}
	}

	/*
	  Evaluating minimum cost of travel.
	*/
	int minC = 1e9;
	for(int b = 0; b < n; ++b) {
		int val = G[b+1][0] + D[b+1][(l-1) ^ (1 << b)];

		if(D[0][l-1] > val) {
			D[0][l-1] = val;
			P[0][l-1] = b+1;
		}
		printf("0\t");
		subset(l-1);
		printf("\t%d\t%d\n", D[0][l-1], P[0][l-1]);
		minC = min(minC, D[0][l-1]);
	}

	printf("\n\nMinimum Cost of the Travel: %d\n", minC);
	
	/*
	  Computing route of traveling salesman.
	*/
	printf("\nTraveling Salesman Route: ");
	vector<int > path;
	int k = 0, sub = l-1;
	while(sub != 0) {
		path.push_back(k);

		k = P[k][sub];
		sub = (sub ^ (1 << (k-1)));
	}

	path.push_back(k);
	path.push_back(0);
	reverse(path.begin(), path.end());
	for(int i= 0; i < path.size(); i++) cout << path[i] << " "; cout << endl << endl;
	return 0;
}

/*
  Test Cases 

  2
  0 1
  3 0

  4 
  0 1 15 6
  2 0 7 3
  9 6 0 12
  10 9 8 0

  3
  0 1 2
  1 0 3
  4 2 0
*/
