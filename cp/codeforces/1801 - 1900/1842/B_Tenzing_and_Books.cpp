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
        ll n,x;
        cin>>n>>x;

        ll w=0;

        vll a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        vll b(n);
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }

        vll c(n);
        for(ll i=0;i<n;i++){
            cin>>c[i];
        }

        if(x==0) {
            cout<<"Yes"<<endl;
            return;
        }

        loop(i,n){
            if((x|a[i])==x) w=(w|a[i]);
            else break;
            if(w==x) {
                cout<<"Yes"<<endl;
                return;
            }
        }

        loop(i,n){
            if((x|b[i])==x) w=(w|b[i]);
            else break;
            if(w==x) {
                cout<<"Yes"<<endl;
                return;
            }
        }

        loop(i,n){
            if((x|c[i])==x) w=(w|c[i]);
            else break;
            if(w==x) {
                cout<<"Yes"<<endl;
                return;
            }
        }

        cout<<"No"<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }