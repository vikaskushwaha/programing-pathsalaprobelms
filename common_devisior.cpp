#include<iostream>
#include<math.h>
using namespace std;

int commondiv(int a, int b){
    int n =min(a,b);
    int m = max(a,b);
    int cnt=1;
    for(int i =2;i<=sqrt(m); i++){     // ittretion from 2 to sqrt(m) because m is greater than n so we cannot miss any divisor.
        if(n%i==0){ // if i is divisor of n then we have to check whether it is divisor of m or not.
            if(i*i==m & n%(i*i)==0){ // this condition is for perfect square and we have check that n is divided by i becsue in some cases i*i become more than n. 
                //cout<<i<<endl;
                cnt++; // if i is divisor of n and m then we have to increase the count by 1.
            }
            else if (m%i==0){ // this condition is for non perfect square.
                if(n%(m/i)==0){ // we have to make sure that m/i is also divisor of n becasue in some cases it is not divisor of n.
                    cnt+=2; // if i is divisor of n and m then we have to increase the count by 2.
                    //cout<<i<<" "<<m/i<<endl;
                    
                }
                else{
                    //cout<<i<<" "<<endl;
                    cnt+=1; // if i is divisor of   m but not n is not diveded by m/i then we have to increase the count by 1.
                }
                
            }
        }

    }
    return cnt;
}

int main(){
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        int a;
        int b;
        cin>>a>>b;
        if(a==b){
            cout<<commondiv(a,b)+1<<endl;
            
        }
        else{
            cout<<commondiv(a,b)<<endl;
        }
        
    }
    
}
