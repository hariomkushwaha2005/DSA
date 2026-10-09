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

    ll misterx(vll v,ll mid, ll x){
        ll n=v.size();
        ll ret=0;
        loop(i,n){
            if((mid-v[i])>0) ret+=(mid-v[i]);
            else return ret;
            if(ret>x) return ret;
        }
        return ret;
    }
    void solve(){
        ll n,x;
        cin>>n>>x;
        vll v(n);
        in(v,n);

        sort(all(v));
        ll low=v[0],high=(x+n-1/n)+v[n-1];
        while(low<=high){
            ll mid=(low+high)/2;
            ll h=misterx(v,mid,x);
            if(h>x) high=mid-1;
            else low=mid+1;
        }

        cout<<high<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }