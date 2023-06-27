#include <iostream>
#include <vector>
using namespace std;
int main()

{

    int n;
    int t;
    cin >> n >> t;

    double result[11][11] = {0.0}; // this is for the result which is double
    result[0][0] = t;              // we are taking the first value as t because total volume of wine is t i.e in one second 1 glass field

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {

            if (result[i][j] >= 1) // if the value is greater than 1 then only we will divide it into two parts
            {

                result[i + 1][j] += (result[i][j] - 1) / 2.0;

                result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;

                result[i][j] = 1; // and the value of the current index will be 1
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (result[i][j] == 1) // if the value is 1 then we will increase the count

                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}