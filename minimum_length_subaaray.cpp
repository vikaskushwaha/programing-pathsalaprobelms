#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, int arr[], int size, int x) // this is for finding the minimum length subarray with sum >= x
{
    if (mid == 0)
    {
        return false;
    }
    int sum = 0;
    for (int i = 0; i < mid; i++)
    {
        sum += arr[i];
    }
    if (sum >= x)
    {
        return true;
    }
    int s = 0;
    int e = mid - 1;
    while (e < size - 1) // this is sliding window technique
    {
        sum -= arr[s];
        s++;
        e++;
        sum += arr[e];
        if (sum >= x)
        {
            return true;
        }
    }
    return false;
}

int binary_search(int arr[], int size, int x)
{
    int s = 0; // search space
    int end = size;
    while (s <= end)
    {
        int mid = (s + end) / 2;
        bool r = isPossible(mid, arr, size, x); // r is for result
        if (!r)                                 // if r is false
        {
            s = mid + 1; // then we will search in the right half because current length subarray is not possible so we need to increase the length of subarray
        }
        else // if r is true
        {
            bool r1 = isPossible(mid - 1, arr, size, x); // the we will check if the subarray of length mid - 1 is possible or not
            if (!r1)                                     // if r1 is false
            {
                return mid;
            }
            else // if r1 is true
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << binary_search(arr, n, x) << endl;
    }
}