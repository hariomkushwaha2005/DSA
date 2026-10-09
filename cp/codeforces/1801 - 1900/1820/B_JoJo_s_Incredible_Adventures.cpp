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
        string s;
        cin>>s;
        ll n=s.size();
        s+=s;
        ll maxx=0,cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') cnt++;
            else cnt=0;
            maxx=max(maxx,cnt);
        }
        if(maxx>n){
            cout<<n*n<<endl;
            return;
        }
        ll ans =((maxx+1)/2);
        if(maxx%2==1) cout<<ans*ans<<endl;
        else cout<<ans*(ans+1)<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }