#include <iostream>
#include <vector>
using namespace std;

int count_element(int x, int m, int n)
{ // If by count function, you mean checker function for the binary search, you can implement it in the following way:

    // Iterate through either of n or m(in this way you are fixing its values).Lets assume we are iterating from 1 to n now.
    // In this way, we are basically fixing n's value and checking how many numbers(less than equal to m) exist, whom we can multiply with i and get a value less than or equal to mid
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        ans += min(x / i, m);
    }

    return ans;
}

int solve(int m, int n, int k)
{
    int start = 1;   // this is minimum in matrix
    int end = m * n; // this is maxim in matrix
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int count = count_element(mid, m, n);
        if (count < k)
        {
            start = mid + 1;
        }
        else
        {
            int count1 = count_element(mid - 1, m, n);
            if (count1 < k)
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
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        int n;
        cin >> n;
        int k;
        cin >> k;
        cout << solve(m, n, k) << endl;
    }

    // print_mat(mat);
}
