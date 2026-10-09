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
        vector<ll>v(n);
        in (v,n);
        ll sum=0;
        for(int i=1;i<n;i++){
            sum+=abs(v[i]-v[i-1]);
        }
        ll cont=0;
        ll maxcont=0;
        ll index=-1;
        for(int i=0;i<n;i++){
            if(i==0){
                cont=abs(v[i]-v[i+1]);
            }
            else if(i==n-1){
                cont=abs(v[i]-v[i-1]);
            }
            else{
                cont=abs(v[i]-v[i-1])+abs(v[i]-v[i+1])-abs(v[i-1]-v[i+1]);
            }
            if(cont>maxcont){
                maxcont=cont;
                index=i;
            }
        }
        cout<<sum-maxcont<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }