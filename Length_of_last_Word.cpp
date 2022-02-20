
#include <bits/stdc++.h>
using namespace std;

#define FAST {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

#define ll long long int
#define ld long double

#define pb push_back 
#define pi pair<ll, ll>
#define ff first
#define ss second
#define vi vector<ll> 
#define vb vector<bool>
#define vii vector<pi>
#define vvi vector<vi> 
#define mii map<ll, ll>
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define srt(v) sort(v.begin(), v.end())
#define setcnt(n) __builtin_popcount(n)
#define bitcnt(n) log2(n)+1

#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define pre(a) cout<<fixed<<setprecision(ll a)

const int M=1e4+3, MOD=1e9+7;

ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b); }
ll lcm(ll a,ll b) {return a/gcd(a,b)*b; }
// ll vect(vi v, ll n) {vi v; rep(i, 0, n){ll x; cin>>x; v.pb(x);}}

int main() {
    FAST;

    string s;
    getline(cin, s);
    // cout << s << "\n";
    

    bool flag=false;
    ll spaces=0;
    rep(i, 0, s.length()){
        if(s[i]==' '){
            spaces++;
        }
    }
    // cout << spaces << "dd  ";
    if(spaces==0){
        flag=true;
    }

    if(flag){
        cout << 0 << "\n";
    }
    else{
        ll cnt=0;
        for(ll i=s.length()-1; i>=0; i--){
            if(s[i]==' '){
                break;
            }
            else{
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}