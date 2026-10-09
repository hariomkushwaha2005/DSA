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
    ll max(ll a , ll b){
        if(b>=a) return b;
        else return a;
    }
    void solve(){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++) cin>>v[i];
        vector<ll>ans(n);
        for(ll i=0;i<n;i++) ans[i]=i+1;
        if(v[0]!=v[1]||v[n-1]!=v[n-2]){
            cout<<-1<<endl;
            return;
        }
        for(ll i=1;i<n;i++){
            if(v[i]==v[i-1]){
                swap(ans[i],ans[i-1]);
            }
            else if(i!=n-1&&v[i]!=v[i+1]){
               cout<<-1<<endl;
                return; 
            }
        }
        for(ll i=0;i<n;i++){
            cout<<ans[i]<<" ";
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