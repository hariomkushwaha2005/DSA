    #include <bits/stdc++.h>
    using namespace std;

    // Type aliases
    #define ll long long
    #define vi vector<int>
    #define vll vector<ll>

    // IO & Logic Shortcuts
    #define endl '\n'
    #define pb push_back
    #define yes cout << "YES\n"
    #define no cout << "NO\n"

    // Common operations
    #define all(x) (x).begin(), (x).end()

    // Loops
    #define loop(i, n) for (ll i = 0; i < (n); i++)

    // Input/Output for arrays or vectors
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
        return (a / gcd(a, b)) * b;  // divide first to prevent overflow
    }

    // Fast IO
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
        vll a=v;
        sort(a.begin(),a.end());
        vll b(n);
        b[0]=a[0];
        ll l=n-1;
        for(int i=1;i<n;i++){
            b[i]=b[i-1]+a[i];
        }
        map<ll,ll>mp;
        for(int i=n-2;i>=0;i--){
            if(b[i]<a[i+1]) l=i;
            mp[a[i]]=l;
        }
        mp[a[n-1]]=n-1;
        loop(i,n){
            cout<<mp[v[i]]<<" ";
        }
        cout<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }