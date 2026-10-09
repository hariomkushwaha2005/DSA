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
        vll v(n);
        unordered_map<ll,ll>mp;
        loop(i,n){
            cin>>v[i];
            if(i&1) mp[v[i]]=0;
            else mp[v[i]]=1;
        }
        sort(all(v));
        ll cnt=0;
        loop(i,n){
            if(i>0&&mp[v[i]]==mp[v[i-1]]) {
                no;
                return;
            }
        }
        yes;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }