#include <bits/stdc++.h>
using namespace std;

int R, C;

// coordinate = (dx,dy)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void print(char input[][50]) {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << input[i][j];
        }
        cout << endl;
    }

}


void floodFill(char input[][50], int i, int j, char ch, char color) {
    // ch => character to be replaced
    // color => character to be added


    // base case: matrix bounds
    if (i<0 or j<0 or i >= R and j >= C) {
        return;
    }

    // figure boundary condition
    if (input[i][j] != ch) return;

    input[i][j] = color;

    // print(input);
    // cout << endl;

    for (int k = 0; k < 4; k++) {
        floodFill(input, i + dx[k], j + dy[k], ch, color);
    }

}

int main() {

    cin >> R >> C;

    char input[15][50];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> input[i][j];
        }
    }

    print(input);
    floodFill(input, 8, 13, '.', 'R');
    // floodFill(input, 0, 0, '.', '!');
    print(input);


}