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
        vll v1(n);
        in(v1,n);
        vll v2(n);
        in(v2,n);
        vll v3(n);
        in(v3,n);

        ll x=0;
        ll l=0;
        while(l<n){
            ll cnt=0;
            for(int i=0;i<n;i++){
                if(v1[i]<v2[(i+l)%n]) cnt++;
                else {
                    l++;
                    break;
                }
            }
            if(cnt==n){
                x++;
                l++;
            }
        }
        l=0;
        ll y=0;
        while(l<n){
            ll cnt=0;
            for(int i=0;i<n;i++){
                if(v2[i]<v3[(i+l)%n]) cnt++;
                else {
                    l++;
                    break;
                }
            }
            if(cnt==n){
                y++;
                l++;
            }
        }
        cout<<n*x*y<<endl;
        

    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }