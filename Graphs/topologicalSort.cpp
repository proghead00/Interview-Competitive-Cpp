#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
	map<T, list<T>> adjList;

public:
	void addEdge(T x, T y, bool bidirectional = true) {
		adjList[x].push_back(y);
		if (bidirectional) adjList[y].push_back(x);
	}

	void print() {
		// iterate over the map
		for (auto p : adjList) {
			cout << p.first << " --> ";

			// p.second => Linked List
			for (T entry : p.second) {
				cout << entry << ",";
			}
			cout << endl;
		}
	}

// -------------------------------------------------------------------------------------------------------------------

	// WITH DFS:
	void dfsHelper(T node, map<T, bool>&visited, list<T> &output_ordering) {
		visited[node] = true;

		for (T nbr : adjList[node]) {
			if (!visited[nbr]) {
				dfsHelper(nbr, visited, output_ordering);
			}
		}

		// 1 LINE FOR TOPOLOGICAL SORT:
		// at this point, all the children of the current node have been visited
		// thus, we can add current node to list
		output_ordering.push_front(node);
	}

	void topologicalSort__DFS() {
		map<T, bool> visited;
		list<T> output_ordering;

		for (auto p : adjList) {
			// p => pair of (node, list of nodes)
			T node = p.first;

			if (!visited[node]) {
				dfsHelper(node, visited, output_ordering);
			}
		}

		for (T element : output_ordering) {
			cout << element << " --> ";
		}

	}



// -------------------------------------------------------------------------------------------------------------------

	// WITH BFS => KAHN'S ALGORITHM:

	void topologicalSort__BFS() {
		queue<T> q;
		map<T, bool> visited;
		map<T, int> indegree;

		for (auto p : adjList) {
			// p => pair(node, list)
			T node = p.first;
			visited[node] = false;
			indegree[node] = 0;
		}

		for (auto p : adjList) {
			T x = p.first;

			// increase indegree when there's an edge:
			for (T y : adjList[x]) indegree[y]++;
		}

		// find out all the nodes with 0 indegree
		for (auto p : adjList) {
			T node = p.first;

			if (indegree[node] == 0)
				q.push(node);
		}

		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << " --> ";

			for (T nbr : adjList[node]) {
				indegree[nbr]--;

				if (indegree[nbr] == 0)
					q.push(nbr);

			}
		}
	}
};

int main() {
	Graph<string> g;

	g.addEdge("English", "Programming Logic", false);
	g.addEdge("Maths", "Programming Logic", false);
	g.addEdge("Programming Logic", "HTML", false);
	g.addEdge("Programming Logic", "Python", false);
	g.addEdge("Programming Logic", "Java", false);
	g.addEdge("Programming Logic", "JS", false);
	g.addEdge("Python", "Web Dev", false);
	g.addEdge("HTML", "CSS", false);
	g.addEdge("CSS", "JS", false);
	g.addEdge("JS", "Web Dev", false);
	g.addEdge("Java", "Web Dev", false);
	g.addEdge("Python", "Web Dev", false);

	// integer nodes example:
	// g.addEdge(1, 3, false);
	// g.addEdge(1, 2, false);
	// g.addEdge(2, 4, false);
	// g.addEdge(3, 4, false);

	g.print();
	cout << endl;
	g.topologicalSort__BFS();
}
// Maths --> English --> Programming Logic --> Java --> Python --> HTML --> CSS --> JS --> Web Dev -->