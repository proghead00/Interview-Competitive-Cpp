#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKSortedArrays(vector<vector<int>> arr)
{
    vector<int> result;

    priority_queue<node, vector<node>, greater<node>> pq; // min heap

    // insert 0th element of every array into pq

    for (size_t i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}}); // i-> array idx; 0->column
    }

    // remove elements from min heap and add to result vector
    while (!pq.empty())
    {
        node curr = pq.top();
        pq.pop();

        int element = curr.first;
        int x = curr.second.first;  // row in which element is present
        int y = curr.second.second; // col  in which element is present

        result.push_back(element); // smallest element

        // push to the priority queue the next element(of the curr element)
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}}); // row->x ; col ->y+1
        }
    }

    return result;
}

int main()
{

    vector<vector<int>> arr{
        {2, 6, 12, 15},
        {1, 3, 14, 20},
        {3, 5, 8, 10}};

    vector<int> output = mergeKSortedArrays(arr);

    for (auto x : output)
    {
        cout << x << " ";
    }
}
