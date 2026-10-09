#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin >>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(v[i]==v[0]){
                a++;
            }
            else if(v[i]==v[n-1]){
                b++;
            }
        }
        if(a==n){
            cout<<"Yes"<<endl;
        }
        else if(n%2==0){
            if(a==n/2&&b==n/2){
                cout <<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            if(a==n/2+1&&b==n/2){
                cout <<"Yes"<<endl;
            }
            else if(a==n/2&&b==n/2+1){
                cout <<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        
    }
}