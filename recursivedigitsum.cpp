#include <iostream>
using namespace std;

int digitsum(int n) // this function is used to calculate the sum of digits of a number
{
    if (n < 10)
    {
        return n; // if the number is less than 10, then the sum of digits is the number itself
    }
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return (digitsum(sum));
}

int superdigitsum(string n, int k)
{
    int sum = 0;
    int digit = 0;
    for (int i = 0; i < n.length(); i++) // this loop is for converting string to integer
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            digit = (n[i] - '0') * k; // this is for multiplying the each digit with k
            sum += digitsum(digit);   // this is for calculating the sum of digits of the number
        }
    }

    return (digitsum(sum)); // this is for calculating the sum of digits of the sum of digits of the number
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << superdigitsum(s, k) << endl;
}
