#include <iostream>
#include <vector>
using namespace std;

bool minHeap = false;
bool compare(int a, int b)
{
    if (minHeap)
        return a < b;
    else
        return a > b;
}

void heapify(vector<int> &v, int idx)
{

    int left = 2 * idx;
    int right = 2 * idx + 1;

    int minIdx = idx;
    int last = v.size() - 1;

    if (left <= last and compare(v[left], v[idx])) // then that node exists and is smaller than the current node
        minIdx = left;

    if (right <= last and compare(v[right], v[minIdx])) // then that node exists and is smaller than the current node
        minIdx = right;

    if (minIdx != idx)
    {
        swap(v[idx], v[minIdx]);
        heapify(v, minIdx);
    }
}

void buildHeapOptimised(vector<int> &v)
{
    // first non leaf node:  (v.size()-1)/2
    for (size_t i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i);
    }
}

void print(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";

    cout << endl;
}

int main()
{
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);

    buildHeapOptimised(v); //O(n)
    print(v);
}
