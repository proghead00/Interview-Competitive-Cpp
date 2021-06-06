#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Point {
public:
	int x, y;

	Point() {

	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Compare {
public:
	bool operator()(const Point p1, const Point p2) {
		if (p1.x == p2.x)
			return p1.y < p2.y;
		return p1.x  < p2.x;
	}
};

int count_rectangles(vector<Point>points) {

	int ans = 0;


	// insert all points in the set
	set<Point, Compare> s;

	for (Point p : points) {
		s.insert(p);
	}

	// Brute force for two points; look up for the other two
	for (auto it = s.begin(); it != prev(s.end()); it++) {
		for (auto jt = next(it); jt != s.end(); jt++) {

			Point p1 = *it;
			Point p2 = *jt;

			if (p2.x == p1.x or p2.y == p1.y) {
				continue;
			}

			Point p3(p1.x, p2.y);
			Point p4(p2.x, p1.y);

			// lookup
			if (s.find(p3) != s.end() and s.find(p4) != s.end()) {
				ans++;
			}
		}
	}

	return ans / 2;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;

	int x, y;

	vector<Point> points;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		Point p(x, y);
		points.push_back(p);

	}
	cout << count_rectangles(points) << endl;

}