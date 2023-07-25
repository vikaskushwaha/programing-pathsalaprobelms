#include <iostream>
#include <math.h>
using namespace std;

long long GCD(long long a, long long b)
{
    long long maximum = max(a, b);
    long long minimum = min(a, b);
    if (minimum == 0)
    {
        return maximum;
    }
    while (maximum % minimum != 0)
    {
        long long temp = maximum;
        maximum = minimum;
        minimum = temp % minimum;
    }
    return minimum;
}
long long lcm(long long a, long long b)
{
    return ((a * b) / GCD(a, b));
}
long long binary_search(long long n, long long a, long long b, long long c)
{
    // long long mod = 1000000007;
    long long start = 1;
    long long end = 2 * 1000000000;
    long long ans = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if ((mid / a) + (mid / b) + (mid / c) - (mid / lcm(a, b)) - (mid / lcm(b, c)) - (mid / lcm(a, c)) + (mid / lcm(lcm(a, b), c)) == n)
        {
            ans = mid;
            end = mid - 1;
            // return (mid % mod);
        }
        else if ((mid / a) + (mid / b) + (mid / c) - (mid / lcm(a, b)) - (mid / lcm(b, c)) - (mid / lcm(a, c)) + (mid / lcm(lcm(a, b), c)) < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, a, b, c;
        cin >> n >> a >> b >> c;
        cout << binary_search(n, a, b, c) << endl;
    }
}