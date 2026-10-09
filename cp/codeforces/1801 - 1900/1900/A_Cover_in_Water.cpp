#include <iostream>
#include <vector>
#include <climits>

using namespace std;
 
int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int d=0;
        int z=0;
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                d++;
                z++;
                if(z>2){
                    break;
                }
            }
            else{
                z=0;
            }
        }
        if(z>=3){
            cout <<"2"<<endl;
        }
        else{
            cout << d <<endl;
        }
    }
}