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
        ll w,h;
        cin>>w>>h;
        vector<vector<int>>v(4);
        for(int i=0;i<4;i++){
            ll k;
            cin >>k;
            for(int j=0;j<k;j++){
                ll x;
                cin>>x;
                v[i].push_back(x);
            }
        }
        ll maxx=0;
        for(int i=0;i<4;i++){
            ll area;
            if(i<2){
                area=h*(v[i][v[i].size()-1]-v[i][0]);
                maxx=max(maxx,area);
            }
            else{
                area=w*(v[i][v[i].size()-1]-v[i][0]);
                maxx=max(maxx,area);
            }
        }
        cout<<maxx<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }