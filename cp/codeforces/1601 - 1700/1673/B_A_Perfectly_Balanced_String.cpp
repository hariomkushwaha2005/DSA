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

        string a="";
        int flag=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<a.size();j++){
                if(s[i]==a[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0) a+=s[i];
            else break;
        }
        int l=a.size();
        int i=0;
        int z=a.size();
        while(l<s.size()){
            if(s[l]==a[i]){
                l++;
                i=(i+1)%z;
            }
            else {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }