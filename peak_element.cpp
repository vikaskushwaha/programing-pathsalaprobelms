#include <iostream>
using namespace std;

int peak_ele(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1]) // if first element is greater than second element
            {
                return mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (mid == n - 1)
        {
            if (arr[mid] > arr[mid - 1]) // if last element is greater than adjecent last element then its peak element
            {
                return mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        else if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) // if mid element is greater than its adjecent elements then its peak element
        {
            return mid;
        }
        else
        {
            if (arr[mid] <= arr[mid + 1]) // if mid element is less than its adjecent element then move to right side
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1; // if mid element is less than its adjecent element then move to left side
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
    cout << peak_ele(arr, n) << endl;
}