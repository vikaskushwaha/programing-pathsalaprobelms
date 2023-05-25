#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,c,t;
    cin>>n>>m>>c>>t;
    int arr[c]={0};
    for(int i =0;i<c;i++){ // this loop is to store the waste cell in the array
        int a,b;
        cin>>a>>b;
        int k = ((b-1)+((a-1))*m); // this is the formula to find the index of the array we are converting 2d array into 1d array
        arr[i]=k;
    }
    for(int i =0;i<t;i++){  // this loop is for the test cases
        int a,b;
        cin>>a>>b;
        int k = ((b-1)+((a-1))*m); // this is the formula to find the index of the array we are converting 2d array into 1d array
        int count=0; // to count the number of waste cell before given query
        int flag =0; // this is to check if the given query is waste cell or not
        for(int j =0;j<c;j++){ // this loop is to check if the given query is waste cell or not
            if(arr[j]==k){
               flag =1;
            }
            else if(arr[j]<k){ // if the given query is not waste cell then we are counting the number of waste cell before the given query
                count++;
            }        
        }
        //cout<<"count : "<<count<<endl;
        if (flag==1){  // if the given query is waste cell then we are printing waste
            cout<<"Waste"<<endl;
        }
        
        else if((k-count)%3==0){ // i did mod 3 because there are 3 types of cell
            cout<<"Carrots"<<endl;
        }
        else if((k-count)%3==1){
            cout<<"Kiwis"<<endl;
        }
        else if((k-count)%3==2){
            cout<<"Grapes"<<endl;
        }       
        

    }
    
    
    // for(int i =0;i<1001;i++){
    //     cout<<Psum[i]<<" ";
    // }
    //  6%5  = 0-4 
    // 15 % 10 = 0---9

    // 2 % 3 = 2 grapes but waste 
    
   // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
}  //     0             0    0   0              0  
