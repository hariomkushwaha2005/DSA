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

    const ll MOD = 1e9+7;

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
        vll a(n);
        in(a,n);
        sort(all(a));
        vll b(n);
        in(b,n);
        sort(all(b));

        ll l=0,r=0;
        ll ans=1;
        while(l<n&&r<n){
            if(a[l]>b[r]){
                ans=(ans*((r-l+1)%MOD))%MOD;
                r++;
            }
            else{
                l++;
            }
        }
        if(r<n){
            cout<<0<<endl;
            return;
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