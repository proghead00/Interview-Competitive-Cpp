#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>> adjList;

public:
	void addEdge(T x, T y, bool bidirectional = true) {
		adjList[x].push_back(y);
		if (bidirectional) adjList[y].push_back(x);
	}

	void bfs(T src) {
		map<T, bool> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {

			T node = q.front();
			cout << node << " ";
			q.pop();

			for (T nbr : adjList[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}

	void print() {
		// iterate over the map
		for (auto p : adjList) {
			cout << p.first << "-->";

			// p.second => Linked List
			for (auto entry : p.second) {
				cout << entry << ",";
			}
			cout << endl;
		}
	}

};

int main() {

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(3, 4);

	g.bfs(0);
	cout << endl;
	g.print();
}
