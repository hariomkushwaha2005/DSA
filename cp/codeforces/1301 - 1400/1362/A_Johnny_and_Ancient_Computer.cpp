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
        ll a,b;
        cin>>a>>b;
        ll cnt=0;
        if(a==b){
            cout<<cnt<<endl;
            return;
        }
        else if(a>b){
            while(a%b==0&&(a/b)%2==0){
                if(a%8==0&&a/8>=b){
                    a=a/8;
                    cnt++;
                }
                else if(a%4==0&&a/4>=b){
                    a=a/4;
                    cnt++;
                }
                else{
                    a=a/2;
                    cnt++;
                }
            }
            if(a==b) cout<<cnt<<endl;
            else cout<<-1<<endl;
            return;
        }
        else{
            while(b%a==0&&(b/a)%2==0){
                if(a*8<=b){
                    a=a*8;
                    cnt++;
                }
                else if(a*4<=b){
                    a=a*4;
                    cnt++;
                }
                else{
                    a=a*2;
                    cnt++;
                }
            }
            if(a==b) cout<<cnt<<endl;
            else cout<<-1<<endl;
            return;
        }
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }