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
void solve() {
    int a,b;
    cin>>a>>b;
    int xk,yk;
    cin>>xk>>yk;
    int xq,yq;
    cin>>xq>>yq;
    vector<pair<int,int>>mp1;
    mp1.push_back({xk+a,yk+b});
    mp1.push_back({xk+a,yk-b});
    mp1.push_back({xk-a,yk+b});
    mp1.push_back({xk-a,yk-b});
    mp1.push_back({xk+b,yk+a});
    mp1.push_back({xk+b,yk-a});
    mp1.push_back({xk-b,yk+a});
    mp1.push_back({xk-b,yk-a});

    vector<pair<int,int>>mp2;
    mp2.push_back({xq+a,yq+b});
    mp2.push_back({xq+a,yq-b});
    mp2.push_back({xq-a,yq+b});
    mp2.push_back({xq-a,yq-b});
    mp2.push_back({xq+b,yq+a});
    mp2.push_back({xq+b,yq-a});
    mp2.push_back({xq-b,yq+a});
    mp2.push_back({xq-b,yq-a});

    sort(mp1.begin(),mp1.end());
    mp1.erase(unique(mp1.begin(), mp1.end()), mp1.end());
    sort(mp2.begin(), mp2.end());
    mp2.erase(unique(mp2.begin(), mp2.end()), mp2.end());

    int i = 0, j = 0, cnt = 0;

    while (i < mp1.size() && j < mp2.size()) {
        if (mp1[i] == mp2[j]) {
            cnt++; i++; j++;
        } else if (mp1[i] < mp2[j]) {
            i++;
        } else j++;
    }
    cout<<cnt<<endl;
}
int main(){
    fast();
    int t;
    cin>>t;
    while(t--){
        solve();
    }  
}