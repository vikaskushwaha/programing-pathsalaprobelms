#include <bits/stdc++.h>
using namespace std;

void balancepar(int n, int l, int r, int idx, char s[], int size)
{
    if (idx == 2 * n) // this is termination condition that means all the balance paran are generated
    {
        for (int k = 0; k < size; k++)
        {
            cout << s[k];
        }
        cout << ",";
        return;
    }
    if (l == r) // if left and right are equal
    {
        s[idx] = '('; // then add left
        balancepar(n, l + 1, r, idx + 1, s, size);
    }
    else if (l > r) // left is greater then right
    {
        if (l == n) // if left is equal to n
        {
            s[idx] = ')'; // only option left is right
            balancepar(n, l, r + 1, idx + 1, s, size);
        }
        else
        { // we can add left or right accordingly
            s[idx] = '(';
            balancepar(n, l + 1, r, idx + 1, s, size);
            s[idx] = ')';
            balancepar(n, l, r + 1, idx + 1, s, size);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int size = 2 * n;
    char s[size];
    balancepar(n, 0, 0, 0, s, size);
}