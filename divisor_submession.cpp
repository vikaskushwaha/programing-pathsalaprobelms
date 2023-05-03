#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int m =0;m<t;m++){
        int n;
        cin>>n;
        if(n<=1){   // according to the question we only have to find we don't need to consider same number as divisor
            cout<<0<<endl;
        }
        else{
            int sum =1;
            for(int i =2;i*i<=n;i++){   // this is for finding the divisor of the number we start it from 2 because 1 is always a divisor of the number and we don't have to include same number as divisior
                if(n%i==0){  // for checking the divisor of the number
                    if(i*i==n){   // this is for no which have perfect square root
                        sum+=i;
        
                    }
                    else{   // this for no which don't have perfect square root
                        //cout<<i<<" "<<n/i<<endl;
                        sum+=i;
                        sum+=(n/i);  // n/i is also a divisor of the number because if i in  left side of squreroot then n/i is in right side of the squreroot
                        
                    }
                }
            }
            cout<<sum<<endl; // this is for printing the sum of the divisor of the number
        }
        
    }
}