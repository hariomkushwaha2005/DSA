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
        for (int i = 0; i < n; i++){
            if(arr[i]==-1){
                cnt++;
            }
        }
        int sum=n-2*cnt;
        int x=0;
        if(sum<0){
            x=(abs(sum)+1)/2;
            cnt=cnt-x;
        }
        if(cnt%2==0){
            cout<<x<<endl;
        }
        else{
            cout<<x+1<<endl;
        }
    }
}