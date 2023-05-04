#include<iostream>
using namespace std;

int main(){
    int n=1000000;
    int prime[n+1];
    for(int i =1;i<=n;i++){
        prime[i]=1;
    }
    prime[1]=0;
    for(int i =2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j =i;j*i<=n;j++){
                prime[i*j]=0;
            }
        }
    }
    int ps[n+1]={0};        // we use prifix sum look donwn for further explanation.
    for(int i =1;i<=n;i++){ 
        ps[i]=prime[i]+ps[i-1];
    }
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        int k;
        cin>>k;
        cout<<ps[k]-ps[k/2]<<endl;

    }
    

}

//
// //I am assuming that your doubt is about how the final answer is supposed to counts[n]-counts[n/2] for each test case n(where by count[n] you mean the number of primes in 1 to n). 
// Now let us look at the way of finding primes using the second method. 
// Suppose we are looking at the first 10 natural numbers-
// 1 2 3 4 5 6 7 8 9 10
// Start with 10-> cross 5 and 2 and 1 as not primes
// Go to 9-> cross 3 and 1 as not primes
// Go to 8-> Cross 4 and 2 and 1 as not primes
// Got to 7-> Cross 1 as not prime
// Go to 6-> Cross 1 and 2 and 3 as not primes
// Do you see what has happened?
// All the numbers from 1 to n/2 are marked as not primes using the second method.
// All the numbers from n/2 to n are marked as primes using this second method.
// This will happen for all n. It is because 1 to n/2 will always be a factor of all the numbers from n/2 to n(mutiply by 2). So they will always be crossed out. And in the same way, n/2+1 to n will be untouched. 
// So what matters in the end is only the actual number of primes in n/2+1 to n. Now do you realise why for each testcase, the answer is count[n]-count[n/2]?
