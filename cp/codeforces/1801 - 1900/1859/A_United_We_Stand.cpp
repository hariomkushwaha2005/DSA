#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        vector<int>a;
        vector<int>b;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            maxx=max(maxx,v[i]);
        }
        for(int i=0;i<n;i++){
            if(v[i]==maxx){
                b.push_back(v[i]);
            }
            else{
                a.push_back(v[i]);
            }
        }
        if(a.size()==0||b.size()==0){
            cout<<"-1"<<endl;
        }
        else{
            cout<<a.size()<<" "<<b.size()<<endl;
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
        }
    }
}