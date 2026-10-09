#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int>vv;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vv.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(v[i-1]<=v[i]){
                vv.push_back(v[i]);
            }
            else{
                vv.push_back(v[i]);
                vv.push_back(v[i]);
            }
        }
        cout<<vv.size()<<endl;
        for(int i=0;i<vv.size();i++){
            cout<<vv[i]<<" ";
        }
        cout<<endl;
    }
}