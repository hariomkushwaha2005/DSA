#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int l=0,g=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                g++;
                l=max(l,g);
            }
            else{
                g=0;
            }
        }
        cout<<l<<endl;
    }
}