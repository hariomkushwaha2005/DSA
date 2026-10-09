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
        ll dif=0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                ll sum=0;
                ll cnt=0;
                ll last=LLONG_MIN;
                ll first =LLONG_MAX;
                for(int j=0;j<n;j++){
                    sum+=v[j];
                    cnt++;
                    if(cnt==i){
                        last=max(sum,last);
                        first=min(first,sum);
                        sum=0;
                        cnt=0;
                    }
                }
                dif=max(dif,max(last,first)-min(last,first));
            }
        }
        cout<<dif<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }