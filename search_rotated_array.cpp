#include <iostream>
using namespace std;

int find_pivot(int arr[], int n) // this function will return the index of the pivot element
{                                // we find this by using that property that the pivot element is the only element which is greater than its next element
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] <= arr[n - 1])
        {
            e = mid - 1;
        }
        else
        {
            if (arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else
            {
                s = mid + 1;
            }
        }
    }
    return -1;
}

int search_left(int arr[], int piviot, int key) // this function will search the key in the left part of the array
{
    int s = 0;
    int e = piviot;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
int search_right(int arr[], int pivot, int n, int key) // this function will search the key in the right part of the array
{
    int s = pivot + 1;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
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
    int t;
    cin >> t;
    int key;
    while (t--)
    {
        cin >> key;
        int pivot = find_pivot(arr, n);
        if (key > arr[n - 1]) // if the key is greater than the last element of the array then it will be present in the left part of the array
        {
            cout << search_left(arr, pivot, key) << endl;
        }
        else
        {
            cout << search_right(arr, pivot, n, key) << endl; // else it will be present in the right part of the array
        }
    }
}
