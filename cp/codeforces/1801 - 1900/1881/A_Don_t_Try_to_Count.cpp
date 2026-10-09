#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        vector <char> x(n);
        vector <char> s(m);
        
        for(int i=0;i<n;i++){
            cin >> x[i];
        }
        for(int j=0;j<m;j++){
            cin >> s[j];
        }
        vector<int> chut;
        for(int i=0;i<n;i++){
            if(s[0]==x[i]){
                chut.push_back(i);
            }
        }
        if(chut.size()==0){
            cout<<"-1"<<endl;
        }
        else{
            int l=0;
        int r=chut[0];
        int cnt=0;
        int cnt2=0;
        for(int i=0;i<m;i++){
            if(s[i]!=x[r]){
                l++;
                if(l<chut.size()){
                    r=chut[l]-1;
                    i=-1;
                    cnt=0;
                    cnt2=0;
                }
                else{
                    cnt=0;
                    break;
                }
            }
            else{
                cnt++;
                if(r==0&&i!=0){
                    cnt2++;
                }
            }
            r=(r+1)%n;
        }
        int ans = 0;
        if (cnt2 > 0) {
            int need = cnt2 + 1;
            while ((1 << ans) < need) ans++;
        }
        if(cnt==m){
            cout<<ans<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
        }
    }
}