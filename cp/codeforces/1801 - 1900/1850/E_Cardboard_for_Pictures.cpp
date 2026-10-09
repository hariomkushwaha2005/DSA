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

    ll cex(vll v, ll w, ll c){
        ll sum=0;
        for(int i=0;i<v.size();i++){
            sum+=(v[i]*v[i])+(4*w*w)+(4*v[i]*w);
            if(sum>c) break;
        }
        return sum;
    }
    void solve(){
        ll n, c;
        cin>>n>>c;

        vll v(n);
        in(v,n);

        ll low=0,high=(ll)sqrt(c/(4*n))+1;
        ll ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(cex(v,mid,c)==c){
                ans=mid;
                break;
            }
            else if(cex(v,mid,c)>c) high=mid-1;
            else low=mid+1;
        }
        cout<<ans<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }