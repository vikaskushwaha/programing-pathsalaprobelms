#include <iostream>
using namespace std;

int reptation(int arr[], int n) // match with the index of element and then try to find out the pattern;
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == mid)
        {
            end = mid - 1;
        }
        else // this help in running for unsorted elements like [7 9 7 4 2 8 7 7 1 5]
        {
            if (arr[mid + 1] == arr[mid])
            {
                return arr[mid];
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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << reptation(arr, n);
}