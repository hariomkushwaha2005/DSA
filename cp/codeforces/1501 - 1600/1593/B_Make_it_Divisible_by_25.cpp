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
    void solve(){
        string n;
        cin>>n;
        int s=n.size();
        int i=s-1;
        int cnt1=0;
        while(i>0&&n[i]!='0'){
            i--;
            cnt1++;
        }
        if(n[i]=='0'){
            i--;
            while(i>=0&&n[i]!='0'&&n[i]!='5'){
                i--;
                cnt1++;
            }
        }
        int j=s-1;
        int cnt2=0;
        while(j>0&&n[j]!='5'){
            j--;
            cnt2++;
        }
        if(n[j]=='5'){
            j--;
            while(j>=0&&n[j]!='2'&&n[j]!='7'){
                j--;
                cnt2++;
            }
        }
        cout<<min(cnt1,cnt2)<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }