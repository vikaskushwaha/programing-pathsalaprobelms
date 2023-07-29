#include <bits/stdc++.h>
using namespace std;
bool sum_lessthen(long long mid, long long arr[], long long n, long long threshold)
{
    if (mid <= 0) // this will help to avoid division by zero
    {
        return false;
    }
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += arr[i] / mid + (arr[i] % mid != 0); // this will help to avoid round off error if arr[i] is not divisible by mid then we have to add 1 to it
    }
    return sum <= threshold;
}
long long maxm(long long arr[], long long n)
{
    long long maxi = INT_MIN;
    for (long long i = 0; i < n; i++)
    {
        maxi = max(arr[i], maxi);
    }
    return maxi;
}
long long smallest_divisor(long long arr[], long long n, long long threshold)
{
    long long start = 0, end = maxm(arr, n); // range of divisor is 1 to maxm(arr)  and we have to find the smallest divisor
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        bool r = sum_lessthen(mid, arr, n, threshold);
        if (!r)
        {
            start = mid + 1;
        }
        else
        {
            bool r1 = sum_lessthen(mid - 1, arr, n, threshold); // this will help to find the smallest divisor
            if (!r1)
            {
                return mid;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
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
    long long thresehold;
    cin >> thresehold;
    cout << smallest_divisor(arr, n, thresehold);
}
