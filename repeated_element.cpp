#include <iostream>
using namespace std;

int repeated_element(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    if (start == end) // If there is only one element in the array
    {
        return arr[0];
    }
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid == 0) // If the element is the first element of the array
        {
            if (arr[mid + 1] != arr[mid])
            {
                return arr[mid];
            }
            else
            {
                start = mid + 1;
            }
        }
        if (mid == n - 1) // if the element is the last element of the array
        {
            if (arr[mid - 1] != arr[mid])
            {
                return arr[mid];
            }
            else
            {
                end = mid - 1;
            }
        }
        else if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) // If the element is not repeated
        {
            return arr[mid];
        }
        else
        {
            int first_occ, sec_occ;
            if (arr[mid] == arr[mid + 1]) // If the element is repeated on the right side
            {
                first_occ = mid;
                sec_occ = mid + 1;
            }
            else
            {
                first_occ = mid - 1; // If the element is repeated on the left side
                sec_occ = mid;
            }
            if (first_occ % 2 == 0) // If the first occurrence is at an even index
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1; // If the first occurrence is at an odd index
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
    cout << repeated_element(arr, n);
}