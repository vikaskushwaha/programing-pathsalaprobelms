#include<iostream>
#include<vector>
using namespace std;
long long mod = 1e9+7;
long long fact(int n){  // this is for calculating factorial
    long long factorial=1;
    for(int i=n;i>0;i--){
        factorial =(factorial*i)%mod;
    }
    return factorial;
} 
int main(){   
    int prime[101];   
    for(int i =1;i<=101;i++){ // this is for sieve of eratosthenes for prime numbers
        prime[i]=1;
    }
    prime[1]=0;
    for(int i=2;i*i<=101;i++){
        if(prime[i]==1){
            for(int j =i;j*i<=101;j++){
                prime[i*j]=0;
            }
        }
    }
    int t;
    cin>>t;
    for(int m =0;m <t;m++){
        int n;
        cin>>n;
        int count =0;
        for(int i =2;i<=n;i++){
            if(prime[i]==1){
                count++;
            }
        }
        cout<<(1LL*fact(count)*fact(n-count))%mod<<endl; // There are K number of primes from 1 to N and there is exactly K number of prime indexes from index 1 to N. So the number of permutations for prime numbers is K!. Similarly, the number of permutations for non-prime numbers is (N-K)!. So the total number of permutations is K!*(N-K)!
    }
    
}