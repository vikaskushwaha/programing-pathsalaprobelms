#include<iostream>
#include<vector>
using namespace std;

void printallcomb(string temp,string &digits,int i,vector<vector<char>>digitMap,vector<string>&ans){
    if(digits[i]==0){   // if end of string is reached push the string to vector of strings
        ans.push_back(temp);
        return;
    }
    for(int j=0;j<digitMap[digits[i]-'2'].size();j++){  // loop to iterate over all possible letters corresponding to digits
        printallcomb(temp+digitMap[digits[i]-'2'][j], digits,i+1,digitMap,ans); // call to recursive function to print all possible combinations
    }
}

vector<string>lettercomb(string digits){  // function to return vector of strings containing all possible combinations of letters corresponding to digits
    vector<string>ans;   // vector to store all possible combinations
    vector<vector<char>>digitMap; // vector of vectors to store all possible letters corresponding to digits
    digitMap.push_back({'a', 'b', 'c'});
    digitMap.push_back({'d', 'e', 'f'});
    digitMap.push_back({'g', 'h', 'i'});
    digitMap.push_back({'j', 'k', 'l'});
    digitMap.push_back({'m', 'n', 'o'});
    digitMap.push_back({'p', 'q', 'r', 's'});
    digitMap.push_back({'t', 'u', 'v'});
    digitMap.push_back({'w', 'x', 'y', 'z'});
    if(digits.length()==0){   // if digits is empty return empty vector
        return ans;
    }
    string temp=" ";  // string to store all possible combinations
    printallcomb(temp, digits, 0, digitMap,ans);  // call to recursive function to print all possible combinations
    return ans;

}
int main(){
    string digits;
    cin >> digits;
    lettercomb(digits);
   
    
}