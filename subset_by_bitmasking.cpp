#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void int_to_binary(int n, int arr[], int size) // this function is for  binary representation of a number
{
    while (n != 0) // this loop will run till the number is not equal to zero
    {
        size = size - 1; // this is used for storing the number in reverse order
        int rem = n % 2;
        arr[size] = rem;
        n = n / 2;
    }
    return;
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
    vector<vector<int>> ans;
    for (int i = 0; i < pow(2, n); i++)
    {
        vector<int> vec;
        int temp[n] = {0};
        int_to_binary(i, temp, n);
        for (int j = 0; j < n; j++)
        {
            if (temp[j] == 1) // if the binary representation of a number contain 1 at a particular index then we will push the element which is at same index in the original array
            {
                vec.push_back(arr[j]);
            }
        }
        ans.push_back(vec);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}