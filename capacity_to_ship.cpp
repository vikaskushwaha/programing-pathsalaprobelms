#include <bits/stdc++.h>
using namespace std;

bool weight_distribution(long long mid, long long arr[], long long size, long long day)
{
    long long cnt = 1;
    long long sum = 0;
    for (long long i = 0; i < size; i++)
    {
        if (arr[i] > mid)
        { // this case is missing in your code
            return false;
        }
        else if (sum + arr[i] > mid)
        {
            cnt++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }
    return cnt <= day;
}
long long max_element(long long arr[], long long size)
{
    long long maxm = LONG_LONG_MIN;
    for (long long i = 0; i < size; i++)
    {
        maxm = max(arr[i], maxm);
    }
    return maxm;
}
long long sum_element(long long arr[], long long size)
{
    long long sum = 0;
    for (long long i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
long long minimum_weight(long long arr[], long long size, long long day)
{
    long long start = max_element(arr, size);
    long long end = sum_element(arr, size);
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        bool r = weight_distribution(mid, arr, size, day);
        if (!r)
        {
            start = mid + 1;
        }
        else
        {
            bool r1 = weight_distribution(mid - 1, arr, size, day);
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
    int t;
    cin >> t;
    while (t--)
    {
        long long day;
        cin >> day;
        cout << minimum_weight(arr, n, day) << endl;
    }
}
