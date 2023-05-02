#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int  n =100000;            // this is for the maximum number upto which we want to find the prime factorization
    int  prime[n+1];           // this is for the prime number upto n
    int  spf[n+1];            // this is for the smallest prime factor of the number
    for(int i =1;i<=n;i++){  // this is for the initialization of the prime and spf array
        prime[i]=1;    
        spf[i]=-1;
    }
    prime[1]=0;                // 1 is not a prime number
    for(int i =2;i*i<=n;i++){ // this is for the finding of the prime number upto n
        if(prime[i]==1){      // this is for finding out no is prime or not
            for(int j=i;j*i<=n;j++){  // this is for cutting the multiple of the prime number
                if(prime[i*j]==1){   //  this is for checking smallest prime factor of the number
                    spf[i*j]=i;     //   this is for storing the smallest prime factor of the number
                    prime[j*i]=0;  // this is for cutting the multiple of the prime number
                }
            }       

        }
    }
    // this part is modified according to the question
    int t;
    cin>>t;
    for(int i =0;i<t;i++){  
        int q;
        cin>>q;
        int arr[q];
        for(int j =0;j<q;j++){
            cin>>arr[j];
        }
        for(int k=0;k<q;k++){  // this is for finding the uninque prime factorization of the number
            map<int, int> power;   
            while(spf[arr[k]]!=-1){    
                power[spf[arr[k]]]++; 
                arr[k]=arr[k]/spf[arr[k]];     
            }
            if(arr[k]!=1){        
                power[arr[k]]++; 
            }
            int count=0;
            for(auto it = power.begin(); it!=power.end(); it++){  
            //    cout<<it->first<<" "<<it->second<<endl;
               count++;

            }
            cout<<count<<" ";
        }
        
    }
    
    
}
