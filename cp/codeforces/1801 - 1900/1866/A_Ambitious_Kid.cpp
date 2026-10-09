#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int x=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(abs(v[i])<x){
            x=abs(v[i]);
        }
    }
    cout<<x<<endl;
}