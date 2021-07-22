#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {

	map<T, list<T>> adjList;

public:

	void addEdge(T x, T y, bool bidirectional) {
		adjList[x].push_back(y);
		if (bidirectional) adjList[y].push_back(x);
	}

	bool isCycle__helper(T node, map<T, bool>&visited, map<T, bool>&inStack) {

		visited[node] = true;
		inStack[node] = true;

		for (T nbr : adjList[node]) {

			if (inStack[nbr]) return true;

			// if the cycle's in the deeper branch (recursively)
			else if (!visited[nbr]) {
				bool nbrFoundCycle = isCycle__helper(nbr, visited, inStack);

				if (nbrFoundCycle) return true;
			}

		}

		// while going back, stack's elements will be "popped out", i.e, false
		inStack[node] = false;
		return false;
	}

	bool isCylic() {
		map<T, bool> visited;
		map<T, bool> inStack;


		// WHY DO WE EVEN NEED THIS:
		// check for cycle in each dfs tree
		// for (auto p : adjList) {
		// 	T node = p.first;
		// 	if (!visited[node]) {
		// 		bool cyclePresent = isCycle__helper(node, visited, inStack);

		// 		if (cyclePresent) return true;
		// 	}
		// }
		// return false;

		return isCycle__helper(0, visited, inStack);
	}
};

int main() {
	Graph<int> g;
	g.addEdge(0, 2, false);
	g.addEdge(0, 1, false);
	g.addEdge(2, 3, false);
	g.addEdge(2, 4, false);
	g.addEdge(3, 0, false);
	g.addEdge(4, 5, false);
	g.addEdge(1, 5, false);

	if (g.isCylic()) cout << "Cycle's Present";
	else cout << "Cycle's not present";
}