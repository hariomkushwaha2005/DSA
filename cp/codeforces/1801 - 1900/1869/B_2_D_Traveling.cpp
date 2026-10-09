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
        ll n,k,a,b;
        cin>>n>>k>>a>>b;

        vector<pair<ll,ll>>v(n);
        for(int i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            v[i]={x,y};
        }
        ll distance=abs(v[a-1].first-v[b-1].first)+abs(v[a-1].second-v[b-1].second);

        ll pro=distance;
        ll pro1=distance;
        for(int i=0;i<k;i++){
            pro=min(pro,abs(v[i].first-v[a-1].first)+abs(v[i].second-v[a-1].second));
            pro1=min(pro1,abs(v[i].first-v[b-1].first)+abs(v[i].second-v[b-1].second));
        }
        cout<<min(distance,pro+pro1)<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }