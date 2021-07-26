#include <bits/stdc++.h>
using namespace std;

#define inf 999999
// #cities = N = 4 -> 1111 --> (2^4)-1 ==> thus, 2^N states

const int n = 4; // here, n=4
int dp[1 << n][n];


// adj matrix:
int adjMatrix[1 << n][n] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};

int visitedALL = (1 << n) - 1;

//-----------------------------------------------

int tsp(int mask, int currCity) {

	// if all cities have been visited:
	if (mask == visitedALL) {
		// return cost from curr city to the src one (0th)
		return adjMatrix[currCity][0];
	}

	if (dp[mask][currCity] != -1)
		return dp[mask][currCity];

	// else, try all possible options ==> Go to unvisited cities
	int ans = inf;
	for (int choice = 0; choice < n; choice++) {

		// check if currCity is visited or not
		if ((mask & (1 << choice)) == 0) {
			int subprob = adjMatrix[currCity][choice] + tsp(mask | (1 << choice), choice);
			ans = min(ans, subprob);
		}
	}


	return dp[mask][currCity] = ans;
}

//-----------------------------------------------
int main() {

	memset(dp, -1, sizeof dp);

	// for (int i = 0; i < 16; i++) {
	// 	for (int j = 0; j < 4; j++)
	// 		dp[i][j] = -1;
	// }

	cout << tsp(1, 0); // INITIALLY, mask = 0001 || currCity = 0 (src)

}

