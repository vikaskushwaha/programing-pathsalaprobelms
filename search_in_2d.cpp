#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int mat[m][n];
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cin >> mat[row][col];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int key;
        cin >> key;
        int start = 0;
        int end = (m * n) - 1;
        int flag = 0;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (mat[mid / n][mid % n] == key) // this is for converting from 1d to 2d
            {
                flag = 1;
                // cout << "true" << endl;
                break;
            }
            else if (mat[mid / n][mid % n] > key)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        if (flag == 0)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
    }
}