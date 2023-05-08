#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<int>getPrime(){ // This function is used to generate prime numbers upto 10e6
    vector<bool>isPrime(10e6,true); // isPrime is a boolean vector of size 10e6
    isPrime[1]=false;
    isPrime[0]=false;
    for(int i =2;i*i<=10e6;i++){ // This loop is used to mark all the composite numbers as false
        if (isPrime[i]){
            for(int j =i;j*i<=10e6;j++){
                isPrime[i*j]=false;
            }
        }
    }
    vector<int>prime;   // This vector is used to store all the prime numbers
    for(int i =0;i<10e6;i++){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
    return prime;
    
}
int  main(){
    vector<int>prime=getPrime(); // This vector is used to store all the prime numbers upto 10e6
    int t;
    cin>>t;
    for(int m =0; m<t;m++){
        int l,r; // 
        cin>>l>>r;
        vector<bool>isprimeinrange(r-l +1,true); // 
            for(int i =0;i<prime.size();i++){ // This loop is used to mark all the composite numbers in the range l to r as false
                int k = ceil((1.0*l)/prime[i]); //  ceil((1.0*l)/prime[i]) is used to find the smallest multiple of prime[i] which is greater than or equal to l
                for(int j = max(k,int(2));prime[i]*j<=r;j++){  // This loop is used to mark all the multiples of prime[i] as false
                    isprimeinrange[prime[i]*j-l]=false;        // prime[i]*j-l is used to find the index of the number in the range l to r
                }
            }
            long long mod = 10e9+7;
            long long mult =1;    
            for(int i =0;i<=r-l;i++){ // This loop is used to find the product of all the prime numbers in the range l to r
                if(isprimeinrange[i]){
                    mult = ((mult % mod) * ((i + l) % mod)) % mod;
                }
            }
            cout<<mult<<endl;
    }
    
        
}