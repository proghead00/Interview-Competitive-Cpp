#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
	map < T, list< pair <T, int> > > adjList;

public:
	void addEdge(T u, T v, int dist, bool bidirectional = true) {
		adjList[u].push_back({v, dist});

		if (bidirectional)
			adjList[v].push_back({u, dist});
	}

	void print() {
		for (auto j : adjList) {
			// j.first ==> key || j.second ==> lisr
			cout << j.first << " --> ";

			for (auto nbr : j.second)
				cout << "(" << nbr.first << "," << nbr.second << ") ";

			cout << endl;
		}
	}

	void dijkstra(T src) {

		map<T, int> dist;

		// set all dist to infinity initially
		for (auto j : adjList)
			dist[j.first] = INT_MAX;

		set <pair<int, T>> s; //  (distance, "city") ==> 1st parameter is distance because it'll automatically sort it a/c to the distance

		dist[src] = 0;
		s.insert({0, src}); // distance of 0th node is 0

		while (!s.empty()) {

			// find the pair at the front
			auto p = *(s.begin()); // pair (distance, "city")

			T node = p.second; // name of the "city"
			int nodeDist = p.first;

			// since distance has been finalized, erase it:
			s.erase(s.begin()); // erase the beginning node

			// iterate over the nbrs of the curr node
			for (auto nbrPair : adjList[node]) {

				if (nodeDist + nbrPair.second < dist[nbrPair.first]) {

					// UPDATION IS NOT POSSIBLE IN PQ/ SET --> HENCE, REMOVE OLD PAIR AND INSERT THE NEW PAIR TO SIMUKATE UPDATION
					T dest = nbrPair.first;
					auto f = s.find({dist[dest], dest});
					if (f != s.end()) {
						s.erase(f);
					}

					// insert the updated value w/ the new dist
					dist[dest] = nodeDist + nbrPair.second;
					s.insert({dist[dest], dest});
				}

			}
		}

		for (auto d : dist) {
			cout << d.first << " --> " << d.second << endl;
		}
	}
};

int main() {
	Graph<string> g;
	g.addEdge("Amritsar", "Delhi", 1);
	g.addEdge("Amritsar", "Jaipur", 4);
	g.addEdge("Jaipur", "Delhi", 2);
	g.addEdge("Jaipur", "Mumbai", 8);
	g.addEdge("Bhopal", "Agra", 2);
	g.addEdge("Mumbai", "Bhopal", 3);
	g.addEdge("Agra", "Delhi", 1);

	// Graph <int> g;

	// g.addEdge(1, 2, 1);
	// g.addEdge(1, 3, 4);
	// g.addEdge(2, 3, 1);
	// g.addEdge(3, 4, 2);
	// g.addEdge(1, 4, 7);

	g.dijkstra("Amritsar");
}