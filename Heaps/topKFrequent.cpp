
#include <bits/stdc++.h>
using namespace std;

 struct compare{
    bool operator()(pair<int,int>p1, pair<int, int>p2){
        
        // second => freq
        if(p1.second==p2.second)
            return p1.first > p2.first;
        return  p1.second < p2.second;
    }
};

void kFreq(int arr[], int n)
{
    unordered_map<int, int>m;

    for (int i = 0; i < n; ++i)
        m[arr[i]]++;
    
    // create pq using unordered_map contents
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq(m. begin(), m.end());
    
    int k = 1;
    for (int i = 0; i < k; ++i)
    {
        cout << pq.top().first << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {2,34,5,3,3,43,3};

    kFreq(arr, 7);

}
