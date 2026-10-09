#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        int flag=0;
        int minn=INT_MAX;
        int mint;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                flag=1;
                break;
            }
            else{
                mint = arr[i]-arr[i-1];
                minn = min(minn,mint);
            }
        }
        if(flag==1){
            cout<<"0"<<endl;
        }
        else if(minn==0){
            cout<<"1"<<endl;
        }
        else{
            cout<<(minn/2)+1<<endl;
        }
    }
}