#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int m = 0;m<t;m++){
        int n;
        cin>>n;
        int arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        int sum = 0;
        for(int i =0; i<n;i++){
            int count = 0;
            int tempsum=0;
            int val=sqrt(arr[i]);
            if(val*val != arr[i]){ // because only non perfect squre will have even divisors
                for(int j =1;j<=sqrt(arr[i]);j++){  // this is for finding out divisors
                    if(arr[i]%j == 0){
                        count++; // counting the divisor because we are using sqrt() we wll get only left side of numbers
                        tempsum += j +(arr[i]/j); // arr[i]/j is used to find out right side of numbers
                    }
                }
                if(count == 2){  // i use this because for having four divisors count should be equal to 2 which is 
                   sum+=tempsum; // to adding sum of each element of array
                }
                
            }
        }
        cout<<sum<<endl;
    }
}

// hurray 64 yes
// 21 = 1 3 7 21 = 32
// 21 4 7
// 21 21
