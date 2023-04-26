#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int m = 0;m<t;m++){
        int n;
        cin>>n;
        int arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        int sum = 0;
        for(int i =0; i<n;i++){
            int count = 0;
            int tempsum=0;
            int val=sqrt(arr[i]);
            if(val*val != arr[i]){
                for(int j =1;j<=sqrt(arr[i]);j++){  
                    if(arr[i]%j == 0){
                        count++;
                        tempsum += j +(arr[i]/j);
                    }
                }
                if(count == 2){ 
                   sum+=tempsum;
                }
                
            }
        }
        cout<<sum<<endl;
    }
}

// hurray 64 yes
// 21 = 1 3 7 21 = 32
// 21 4 7
// 21 21