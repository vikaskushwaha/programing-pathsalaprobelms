#include <iostream>
#include <math.h>
using namespace std;

double myPow(double x, int n)
{
    // if(n<0){

    // }
    if (n == 0)
    {
        return 1;
    }
    double y = myPow(x, n / 2); // this is the recursive call by dividing the n by 2
    if (n % 2 == 0)             // if the n is even then we will return the square of the y
    {
        return y * y;
    }
    else
    {
        if (n < 0) // if the n is negative then we will return the square of the y and multiply it by 1/x
        {
            return y * y * 1 / x;
        }
    }

    return y * y * x; // if the n is odd then we will return the square of the y and multiply it by x
}

int main()
{
    double x;
    int n;
    cin >> x;
    cin >> n;
    cout << myPow(x, n) << endl;
}