    #include <iostream> 
    #include <vector> 
    #include <string> 
    #include <queue> 
    #include <stack>
    #include <map> 
    #include <set> 
    #include <unordered_map> 
    #include <unordered_set>
    #include <algorithm> 
    #include <cmath> 
    #include <climits>
    #include <cstring> 
    #include <iomanip>
    #include <sstream> 
    #include <fstream> 
    #include <numeric> 
    #include <bitset> 
    #include <functional>
    #include <deque> 
    #include <list> 
    #include <tuple> 
    #include <cassert> 
    #include <ctime>
    #include <random> 
    #include <chrono> 
    #include <iterator> 
    #include <utility> 
    #include <type_traits>
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
    void solve(vector<ll>&mpp,int b){
        ll low=0,high=mpp.size()-1;
        ll ans=0;
        while(low<=high){
            ll mid=(low+high)/2;
            if(mpp[mid]>=b) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        cout<<ans+1<<endl;
    }
    int main(){
        fast();
        int n;
        cin>>n;
        vector<int>a(n);
        vector<ll>mpp(n);
        for(int i=0;i<n;i++){ 
            cin>>a[i];
            if(i==0) mpp[i]=a[i];
            else mpp[i]=mpp[i-1]+a[i];
        }
        int m;
        cin>>m;
        vector<int>b(m);
        for(int i=0;i<m;i++) cin>>b[i];
        int t=m;
        int i=0;
        while(t--){
            solve(mpp,b[i]);
            i++;
        }
    }