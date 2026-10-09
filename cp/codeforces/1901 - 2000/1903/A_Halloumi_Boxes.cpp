#include<iostream>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k==1){
            int x=0;
            for(int j=0;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    x++;
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if(x==0){
                cout<<"YES"<<endl;
            }
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}