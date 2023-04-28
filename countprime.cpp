#include<iostream>
#include<climits>
using namespace std;


// problem statement:-
// this is the most efficient way to find out prime no in a given range
// we will use sieve of eratosthenes to find out prime no in a given range
// we will use prifix sum to handle all the test cases result efficiently
// we will find out all the prime no till the maximum element in all test cases
// and then we will use prifix sum to find out prime no in a given range
// time complexity is O(nlog(logn)) for finding out prime no till n
// and O(1) for finding out prime no in a given range
// space complexity is O(n) for storing prime no till n

int main(){
    int t;
    cin>>t;
    int no_of_test[t];    // for storing the total no of test cases so that we don't have to find out calculate sieve for each test cases.
    for(int i =0;i<t;i++){  //  for input of test cases
	cin>>no_of_test[i];
    }
    int n=INT_MIN;
    for(int i =0; i<t;i++){   // for finding out maximum element in all test cases so that that we can calculate sieve for max element and we will count all the prime no 
        n=max(n,no_of_test[i]); // for other test cases
    }
    int prime[n+1]; // we create a array to store prime no 
    for(int i =1; i<=n; i++ ){ // assume it that all the no form 1 to n is prime
        prime[i]=1;
    }
    prime[1]=0;  // and 1 is not prime no we change it's value to 0;
    for(int i =2;i*i<=n;i++){      // we will start from 2 and go till squre root of n; becacue after that all the no are checked
        if(prime[i]==1){   // if the no is prime 
            for(int j=i;j*i<=n;j++){    // then we all find out multiple of that no 
                prime[j*i]=0;      // and marked it as non- prime because all that no which are multiple that no are not prime no
            }
        }
    }
	// i am using prifix sum to handle all the test cases result efficiently
    int ps[n+1]={0};    // initilize array to zero
    for(int i =1;i<=n;i++){ // then sum all the element till their index
        ps[i]=prime[i]+ps[i-1];
    }
    for(int i =0;i<t;i++){
        cout<<ps[no_of_test[i]]<<endl;  // for printing out all the result of test casese in order 1 times;
    }
    
    

    
}
