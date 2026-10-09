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
        ll n;
        cin>>n;

        vector<pair<ll,ll>> v(n);
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            v[i]={x,i+1};
        }
        sort(all(v));

        for(int i=n-1;i>=2;i--){
            if(v[i].first+v[i-1].first!=v[0].first){
                cout<<v[i].second<<" "<<v[i-1].second<<" "<<v[0].second<<endl;
                return;
            }
        }
        cout<<-1<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }