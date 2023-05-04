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
    int ps[n+1]={0};    
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