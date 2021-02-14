#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min)
{

    // first student
    int student = 1;
    int pages_reading = 0;

    for (int i = 0; i < n; i++)
    {
        if (pages_reading + arr[i] > curr_min)
        {
            student++; // move to next student

            pages_reading = arr[i];

            if (student > m)
            {
                return false;
            }
        }

        else
        {
            pages_reading += arr[i];
        }
    }
    return true;
}

int minNoOfPages(int arr[], int n, int m)
{
    int sum_of_all_pages = 0;

    int start, end;
    int ans = INT_MAX;

    if (n < m)
    {
        return -1;
    }

    else
    { // count no of pages

        for (int i = 0; i < n; i++)
        {
            sum_of_all_pages += arr[i];
        }

        int start = arr[n - 1];
        int end = sum_of_all_pages;
    }

    while (start <= end)
    {
        int mid = (start + end) / 2;

        // if possible to divide books in the array into n students

        // such that no student reads more than m pages
        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);

            // reduce no of pages
            end = mid - 1;
        }
        else
        {
            // not possible to divide at x pages
            // hence, increase the number of pages
            start = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char)
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;

        cin >> n >> m;

        int arr[1000];

        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        cout << minNoOfPages(arr, n, m) << endl;
    }
}