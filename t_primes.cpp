#include<iostream>
#include<math.h>
using namespace std;

// in this question we have check which number has 3 divisiors that is called t_prime
// we have to check whether the number is perfect square or not
// if it is perfect square then we have to check whether the square root of that number is prime or not
// if it is prime then we have to print yes otherwise no
// if the number is not perfect square then we have to print no

// only those no have 3 individual divisors which square root of that number is prime

bool is_prime(int n){     // this function checks whether the number is prime or not
    if(n==1){
        return false;
    }
    int cnt=0;
    for(int i =2;i<=sqrt(n);i++){
        if(n%i==0){
            cnt++;
        }
    }
    if(cnt==0){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int t;
    cin>>t;
    for(int m =0;m<t;m++){
        long long n;
        cin>>n;
        long long val=sqrt(n);
        if(val*val==n){ // this checks whether the number is perfect square or not
            if(is_prime(val)==true){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
        
        
   
    }
}