#include <iostream>
#include <math.h>
using namespace std;

long long GCD(long long a, long long b) // this is for finding the GCD of two numbers
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
long long lcm(long long a, long long b) // this is for finding the LCM of two numbers
{
    return ((a * b) / GCD(a, b));
}
// we use inclusion exclusion principle here to find the number of magical numbers
// in this principal we basically find the number of numbers divisible by a or b and then subtract the number of numbers divisible by both a and b
long long binary_search(long long n, long long a, long long b)
{
    long long mod = 1000000007;
    long long start = min(a, b);
    long long end = n * min(a, b);
    long long ans = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if ((mid / a) + (mid / b) - (mid / lcm(a, b)) == n) // this will tell the megical no. at the nth position
        {
            ans = mid;
            end = mid - 1; // if we are at the nth position and that no is divisible by both a and b then we will have to find the previous magical no. so we will have to decrement the mid
            // return (mid % mod);
        }
        else if ((mid / a) + (mid / b) - (mid / lcm(a, b)) < n)
        {
            start = mid + 1; // if position is less than the nth position then we will have to find the magical no. after the mid
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans % mod;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, a, b;
        cin >> n >> a >> b;
        cout << binary_search(n, a, b) << endl;
    }
}