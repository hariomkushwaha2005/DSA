#include <bits/stdc++.h>
    using namespace std;
 
    #define ll long long
    #define vi vector<int>
    #define vll vector<ll>
 
    #define endl '\n'
    #define pb push_back
    #define yes cout << "YES\n"
    #define no cout << "NO\n"
 
    #define all(x) (x).begin(), (x).end()
 
    #define loop(i, n) for (ll i = 0; i < (n); i++)
 
    #define in(arr, n) for (ll i = 0; i < (n); i++) cin >> arr[i]
    #define out(arr) for (ll i = 0; i < (ll)(arr.size()); i++) cout << arr[i] << ' '
 
    ll gcd(ll a, ll b) {
        while (b != 0) {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
 
    ll lcm(ll a, ll b) {
        return (a / gcd(a, b)) * b;
    }
 
    void fast() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    void solve(){
        ll n,k;
        cin>>n>>k;
        vll v(n);
        in(v,n);
        string s;
        cin>>s;

        vll z;
        for(int i=0;i<n;i++){
            if(s[i]=='0') z.push_back(v[i]);
        }
        if(z.size()<k){
            cout<<-1<<endl;
            return;
        }
        sort(z.begin(),z.end());
        ll ans=0;
        for(int i=0;i<k;i++){
            ans+=z[i];
        }
        cout<<ans<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }