#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int  n =1000000; // this is for the maximum number upto which we want to find the prime factorization
    int  prime[n+1]; // this is for the prime number upto n
    int  spf[n+1];  // this is for the smallest prime factor of the number
    for(int i =1;i<=n;i++){  // this is for the initialization of the prime and spf array
        prime[i]=1;    
        spf[i]=-1;
    }
    prime[1]=0;  // 1 is not a prime number
    for(int i =2;i*i<=n;i++){ // this is for the finding of the prime number upto n
        if(prime[i]==1){      // this is for finding out no is prime or not
            for(int j=i;j*i<=n;j++){  // this is for cutting the multiple of the prime number
                if(prime[i*j]==1){ //  this is for checking smallest prime factor of the number
                    spf[i*j]=i;  //   this is for storing the smallest prime factor of the number
                    prime[j*i]=0; // this is for cutting the multiple of the prime number
                }
            }       

        }
    }
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        int q;
        cin>>q;
        map<int, int> power; // using map  for storing the power of the prime number 
        while(spf[q]!=-1){  // we access spf array to find out exact prime factorization of the number
            power[spf[q]]++; // this is for storing the power of the prime number
            q=q/spf[q];  // this is for finding the next prime factor of the number 
        }
        if(q!=1){ // this is for checking the last prime factor of the number
            power[q]++; // this is for storing the power of the prime number
        }
        for(auto it = power.begin(); it!=power.end(); it++){  // this is for printing the prime factorization of the number 
            cout<<it->first<<" "<<it->second<<endl; // this is for printing the prime factorization of the number

        }   
    }
    
    
}
