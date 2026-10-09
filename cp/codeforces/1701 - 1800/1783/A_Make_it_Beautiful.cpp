#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),greater<int>());
        int cnt=0;
        int x;
        for(int i=1;i<n;i++){
            if(arr[0]==arr[i]){
                cnt++;
            }
            else{
                x=i;
                break;
            }
        }
        if(cnt==n-1){
            cout<<"NO"<<endl;
        }
        else if(cnt>0){
            swap(arr[1],arr[x]);
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
}