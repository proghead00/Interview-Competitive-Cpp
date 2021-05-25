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

void heapify(vector<int> &v, int idx, int size)
{
    int minIdx = idx;
    int left = 2 * idx;
    int right = left + 1;
    int last = size - 1;

    if (left <= last and compare(v[left], v[idx]))
        minIdx = left;

    if (right <= last and compare(v[right], v[minIdx]))
        minIdx = right;

    if (minIdx != idx)
    {
        swap(v[idx], v[minIdx]);
        heapify(v, minIdx, size);
    }
}

void buildHeapOptimised(vector<int> &v)
{
    for (size_t i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i, v.size());
    }
}

void heapsort(vector<int> &v)
{
    buildHeapOptimised(v);
    int n = v.size();

    // remove n-1 elements from the heap
    while (n > 1)
    {
        swap(v[1], v[n - 1]);
        n--; // shrinking the size of the heap

        heapify(v, 1, n);
    }
}

int main()
{
    vector<int> v{-1, 4, 6, 5, 4, 3, 8};
    buildHeapOptimised(v);
    heapsort(v);

    for (int x : v)
        cout << x << " ";
}
