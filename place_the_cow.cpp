#include <bits/stdc++.h>
using namespace std;

bool isPlacingcowPossible(long long mid, long long c, long long arr[], long long size)
{
    long long cnt = 1;       // because we are placing the first cow at the first stall
    long long prev = arr[0]; // this is for tracking the previous stall where we placed the cow
    for (long long i = 1; i < size; i++)
    {
        if ((arr[i] - prev) < mid) // if the current stall is not at least mid distance away from the previous stall, then we will not place the cow at the current stall
        {
            continue;
        }
        else
        {
            cnt++;         // if the current stall is at least mid distance away from the previous stall, then we will place the cow at the current stall
            prev = arr[i]; // updating the previous stall
        }
    }
    return cnt >= c; // if the number of cows placed is greater than or equal to the number of cows given, then we will return true
}

int minadjdist(long long c, long long arr[], long long size)
{
    long long start = 0;
    long long end = LLONG_MAX;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        bool r = isPlacingcowPossible(mid, c, arr, size);
        if (!r)
        {
            end = mid - 1;
        }
        else
        {
            bool r1 = isPlacingcowPossible(mid + 1, c, arr, size);
            if (!r1)
            {
                return mid;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long t;
    cin >> t;
    while (t--)
    {
        long long c;
        cin >> c;
        cout << minadjdist(c, arr, n) << endl;
    }
}