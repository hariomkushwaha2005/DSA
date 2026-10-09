#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin >>x>>k;
        if(x%k==0){
            if(x%2==0&&k%2==0){
                cout<<"2 "<<endl;
                cout<<x-1<<" 1 "<< endl;
            }
            else if(x%2==0&&k%2!=0){
                cout<<"2 "<<endl;
                cout<<x-2<<" 2 "<< endl;
            }
            else if(x%2!=0&&k%2==0){
                cout<<"2"<<endl;
                cout<<x-2<<" 2 "<<endl;
            }
            else{
                cout<<"2 "<<endl;
                cout<<x-1<<" 1 "<< endl;
            }
        }
        else{
            cout<<"1"<<endl;
            cout<<x<<" "<<endl;
        }
    }
}