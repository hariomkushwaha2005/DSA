#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin >> n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(v[i]==k){
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
    }
}