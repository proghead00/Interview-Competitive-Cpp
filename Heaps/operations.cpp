#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;
    bool compare(int a, int b)
    {
        if (minHeap)
            return a < b;
        else
            return a > b;
    }

    void heapify(int idx)
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
            heapify(minIdx);
        }
    }

public:
    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    // 1. Insert element at the last pos
    // 2. Compare w/ its parent
    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;

        // keep pushing element towards the top until we get root or the element is already greater than parent
        while (idx > 1 and compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent /= 2;
        }
    }
    int top()
    {
        return v[1];
    }

    // delete the smallest in min heap and the largest in max heap
    void pop()
    {

        // Swap the first and the last element
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1); // heapify from the root node
    }

    bool empty()
    {
        return v.size() == 1;
    }
};

int main()
{
    Heap h;
    int n;

    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        h.push(num);
    }
    // removing the elements
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
}
