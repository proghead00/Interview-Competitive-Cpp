#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int> > &matrix, vector<vector<bool> > &visited, int i, int j, int m, int n) {

    visited[i][j] = true;

    int currSize = 1;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int xx = i + dx[k];
        int yy = j  + dy[k];

        if (xx >= 0 and xx<m and yy >= 0 and yy < n and matrix[xx][yy] == 1 and !visited[xx][yy]) {
            int subcomponent = dfs(matrix, visited, xx, yy, m, n);
            currSize += subcomponent;
        }
    }
    return currSize;
}


int lasrgestIsland(vector<vector<int> > matrix) {

    int m = matrix.size(); // rows
    int n = matrix[0].size(); // cols

    vector<vector<bool> > visited(m, vector<bool>(n, false));

    int largest = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] and matrix[i][j] == 1) {

                int size = dfs(matrix, visited, i, j, m, n);
                if (size > largest) {
                    largest = size;
                }

            }

        }
    }
    return largest;
}


int main() {
    vector<vector<int> > grid = {
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 0}
    };

    cout << lasrgestIsland(grid) << endl;


    return 0;
}