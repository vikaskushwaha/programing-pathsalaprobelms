#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int no_of_test[t];
    for(int i =0;i<t;i++){
		cin>>no_of_test[i];
    }
    int n=INT_MIN;
    for(int i =0; i<t;i++){
        n=max(n,no_of_test[i]);
    }
    int prime[n+1];
    for(int i =1; i<=n; i++ ){
        prime[i]=1;
    }
    prime[1]=0;
    for(int i =2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j=i;j*i<=n;j++){
                prime[j*i]=0;
            }
        }
    }
    int ps[n+1]={0};
    for(int i =1;i<=n;i++){
        ps[i]=prime[i]+ps[i-1];
    }
    // for(int i =1;i<=n;i++){
    //     cout<<ps[i]<<" ";
    // }
    for(int i =0;i<t;i++){
        cout<<ps[no_of_test[i]]<<endl;
    }
    
    

    
}