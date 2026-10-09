#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        long long x=c-a;
        long long y=d-b;
        if(x>y||y<0){
            cout<<"-1"<<endl;
        }
        else{
            cout<<2*y-x<<endl;
        }
    }
}