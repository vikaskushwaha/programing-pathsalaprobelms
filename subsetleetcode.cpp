#include <iostream>
#include <vector>
using namespace std;

void printallsubset(vector<int> &nums, int n, int i, int temp[], int size, vector<vector<int>> &ans)
{
    if (i == n)
    {
        vector<int> v; // This is the used to repsent the subset in vector of vector
        for (int i = 0; i < size; i++)
        {
            v.push_back(temp[i]); // pushed the temp array  in vector
        }
        ans.push_back(v); //  pushed the vector in vector of vector
        return;
    }
    temp[size] = nums[i];                                // if we include the element
    printallsubset(nums, n, i + 1, temp, size + 1, ans); // size is increased by 1
    printallsubset(nums, n, i + 1, temp, size, ans);     // if we don't include the element size remains same
}

int main()
{
    vector<vector<int>> ans;
    vector<int> nums = {1, 2, 3};
    int temp[nums.size()];
    printallsubset(nums, nums.size(), 0, temp, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
