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
        in(v,n);

        ll x=v[n-1];
        ll ans=-1;
        for(ll i=n-1;i>=0;i--){
            x=__gcd(x,v[i]);
            if(x==1){
                if(i+n+1<=ans) break;
                for(ll j=n-1;j>=i;j--){
                    if(i+j+2<=ans) break;
                    if(__gcd(v[i],v[j])==1){
                        ans=i+j+2;
                    }
                }
            }
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