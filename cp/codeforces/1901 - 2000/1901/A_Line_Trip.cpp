#include <iostream>
#include <vector>
#include <climits>

using namespace std;
 
int main() {
    int t;
    cin>>t;
    while (t--){
        int n,x;
        cin>>n>>x;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector <int> v;
        v.push_back(0);
        for(int j=0;j<n;j++){
            v.push_back(arr[j]);
        }
        v.push_back(x);
        int maxi=INT_MIN;
        for(int i=0;i<v.size()-1;i++){
            int k=v[i+1]-v[i];
            maxi=max(maxi,k);
        }
        int z=x-v[v.size()-2];
        maxi=max(maxi,2*z);
        cout << maxi<< endl;
    }
}