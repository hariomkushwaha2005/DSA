#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==2){
                cnt++;
            }
        }
        if(cnt==0){
            cout<<"1"<<endl;
        }
        else if(cnt%2==0){
            int z=cnt/2;
            int e=0;
            for(int i=0;i<n;i++){
                if(arr[i]==2){
                    e++;
                    if(e==z){
                        cout<<i+1<<endl;
                        break;
                    }
                }
            }
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}