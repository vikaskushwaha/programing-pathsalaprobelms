#include <bits/stdc++.h>
using namespace std;

bool allocation(long long mid, long long arr[], long long size, long long m)
{
    long long cnt = 1; // because already student one book is allocated
    long long sum = 0; // sum of pages
    for (long long i = 0; i < size; i++)
    {
        if (arr[i] > mid)
        { // this case is missing in your code
            return false;
        }
        else if (sum + arr[i] > mid) // if sum of pages is greater than mid then we will increase the count
        {
            cnt++;        // no of student will increase
            sum = arr[i]; // the next student will start from this book
        }
        else
        {
            sum += arr[i]; // if sum of pages is less than mid then we will add the pages
        }
    }
    return cnt <= m; // if count is less than or equal to m then we will return true
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
long long minimizing_max(long long arr[], long long size, long long m)
{
    long long start = max_element(arr, size); // because minimum pages will be the maximum element
    long long end = sum_element(arr, size);   // suppose there is only one student then he will allocate all the books
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        bool r = allocation(mid, arr, size, m);
        if (!r)
        {
            start = mid + 1;
        }
        else
        {
            bool r1 = allocation(mid - 1, arr, size, m);
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
    long long m;
    cin >> m;
    cout << minimizing_max(arr, n, m);
}