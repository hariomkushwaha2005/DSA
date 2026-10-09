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
        vector<vector<ll>> v(n,vector<ll>(n));
        ll cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }
        for(ll i=0;i<n/2;i++){
            for(ll j=0;j<n;j++){
                if(v[i][j]!=v[n-1-i][n-1-j]) cnt++;
            }
        }
        if(n%2==1){
            for(ll j=n/2;j<n;j++){
                if(v[n/2][j]!=v[n/2][n-1-j]) cnt++;
            }
        }
        if(k<cnt) no;
        else if(n%2==0&&(k-cnt)%2==1) no;
        else yes;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }