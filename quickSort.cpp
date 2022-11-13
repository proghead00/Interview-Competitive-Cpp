#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int h) {

    int pivot = v[h];
    int i = l;

    for (int j = l; j < h; j++) {
        if (v[j] < pivot) {
            swap(v[i], v[j]);
            i++;
        }
    }

    swap(v[i], v[h]);
    return i;
}

void quick(vector<int> &v, int l, int h) {

    if (l >= h) return;

    int pv = partition(v, l, h);

    quick(v, l, pv - 1);
    quick(v, pv + 1, h);
}

int main() {
    vector<int> v = {4, 2, 5, 12, 1, 67, 6, 312, 0};
    quick(v, 0, v.size() - 1);

    for (auto x : v) cout << x << " ";

}
