#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<vector<char>>Matrixx(10,vector<char>(10));
    int left,right;
    int sum=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>Matrixx[i][j];
            if(Matrixx[i][j]=='X'){
                if(i<5){
                    left=i+1;
                }
                else {
                    left =10-i;
                }
                if(j<5){
                    right =j+1;
                }
                else{
                    right=10-j;
                }
                sum=sum+min(left,right);
            }
        }
    }
    cout<<sum<<endl;
}

int main() {
    int t;
    cin >> t;          // Remove if only 1 test case

    while(t--) {
        solve();
    }
}