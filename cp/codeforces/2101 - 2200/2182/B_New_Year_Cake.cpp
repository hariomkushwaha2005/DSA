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
        ll a,b;
        cin>>a>>b;

        ll p=a,q=b;
        ll x=1,y=2;
        ll cnt=0;
        while(a>=x&&b>=y){
            a=a-x;
            x=x*4;
            b=b-y;
            y=y*4;
            cnt+=2;
        }
        if(a>=x) cnt++;

        x=2, y=1;
        ll cnt2=0;
        while(p>=x&&q>=y){
            p=p-x;
            x=x*4;
            q=q-y;
            y=y*4;
            cnt2+=2;
        }
        if(q>=y) cnt2++;

        cout<<max(cnt,cnt2)<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }