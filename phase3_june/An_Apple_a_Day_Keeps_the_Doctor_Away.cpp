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
#define setcnt(n) __builtin_popcount(n) // no of ones(set bits)
#define bitcnt(n) (int)log2(n) // no of bits

#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define pre(a) {cout << fixed << setprecision(a);}
#define vect(v, n) {rep(i, 0, n){ll x; cin>>x; v.pb(x);}}

const int M=1e4+3, MOD=1e9+7;

ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b); }
ll lcm(ll a,ll b) {return a/gcd(a,b)*b; }

// Declaring variables
ll n, m, k, t;
string s, s1, s2;

bool sortbysec(pi &a, pi &b){
    if(a.second == b.second)
        return (a.ff > b.ff);
    else
        return (a.second < b.second);
}

void solve(){
    cin >> n >> m;
    vi vit, price;
    rep(i, 0, n){
        ll x, y; cin >> x >> y;
        vit.pb(x);
        price.pb(y);
    }

    vii v;
    rep(i, 0, n){
        v.pb({vit[i], price[i]});
        // cout << v[i].ff <<" " << v[i].ss << " ";
    }

    sort(v.begin(), v.end(), sortbysec);

    // rep(i, 0, n){
    //     // v.pb({vit[i], price[i]});
    //     cout << v[i].ff <<" " << v[i].ss << endl;
    // }

    ll ans=0;
    priority_queue<ll,vi> pq;
    rep(i, 0, n){
        if(v[i].ss<=m){
            ans+=v[i].ff;
            m-=v[i].ss;

            // cout << v[i].ff << " " << v[i].ss << endl;
        }
        else if(floor(v[i].ss/2)<=m){
            pq.push(v[i].ff);
            // cout << v[i].ff << " ";
        }
    }

    if(!pq.empty())
        ans+=pq.top();

    cout << ans << endl;
}

int32_t main() {
    FAST;

    t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}