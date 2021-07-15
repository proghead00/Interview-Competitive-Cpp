#include <iostream>
#include <unordered_map>
#include <cstring>
#include <list>
using namespace std;

class Graph {
	unordered_map < string, list < pair< string, int > > > l;

public:
	void addEdge(string x, string y, bool bidir, int wt) {
		l[x].push_back({y, wt});

		if (bidir) l[y].push_back({x, wt});
	}

	void print() {
		for (auto p : l) {
			string city = p.first;
			list<pair<string, int>> nbrs = p.second;

			cout << city << "--> ";
			for (auto nbr : nbrs) {
				string dest = nbr.first;
				int dist = nbr.second;

				cout << dest << " " << dist << " ; ";
			}
			cout << endl;
		}
	}
};

int main() {

	Graph g;

	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", false, 50);

	g.print();
}