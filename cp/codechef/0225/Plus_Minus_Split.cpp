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
        ll n;
        cin>>n;

        vll v(n);
        in(v,n);

        unordered_map<int,int> mp;
        int a=0,b=0;
        for(int i=0;i<n;i++){
            mp[v[i]]++;
            if(mp.size()==1){
                a=v[i];
            }
            else if(mp.size()==2){
                b=v[i];
            }
            else if(mp.size()>2){
                cout<<"No"<<endl;
                return ;
            }
        }
        if(mp.size()==1){
            cout<<"Yes"<<endl;
            return;
        }
        else{
            if(a+b!=0) {
                cout<<"No"<<endl;
                return ;
            }
            else{
                int cnt=0;
                loop(i,n-1){
                    if(v[i]!=v[i+1]) cnt++;
                    if(cnt>1) {
                    cout<<"No"<<endl;
                    return ;
                }
                }
                
            }
        }
        cout<<"Yes"<<endl;
        return ;
    }
    int main(){
        fast();
        int t;
        cin>>t;
        while(t--){
            solve();
        }  
    }