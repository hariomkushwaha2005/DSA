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
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        if(c=='g'){
            cout<<0<<endl;
            return;
        }
        s+=s;
        ll last=-1;
        ll maxx=0;
        char l=c;
        for(int i=0;i<s.size();i++){
            if(s[i]==l){
                last=i;
                l='.';
            }
            if(s[i]=='g'&&last!=-1){
                maxx=max(i-last,maxx);
                last=-1;
                l=c;
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