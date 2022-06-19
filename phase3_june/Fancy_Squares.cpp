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


void solve(){
    cin >> n;
    int arr[n][n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> arr[i][j];
        }
    }

    ll mdSum=0;
    ll amdSum=0;
    ll r=n;
    rep(i, 0, n){
        mdSum+=arr[i][i];
        amdSum+=arr[i][--r];
    }

    // cout << mdSum << " " << amdSum << endl;
    
    ll rowSum[n]={0};
    ll colSum[n]={0};
    rep(i, 0, n){
        rep(j, 0, n){
            rowSum[i]+=arr[i][j];
            colSum[i]+=arr[j][i];
        }
    }

    vi ans;
    
    for(ll i=n-1; i>=0; i--)
        if(mdSum!=rowSum[i])
            ans.pb((i+1));  

    if(mdSum!=amdSum)
        ans.pb(0);

    rep(i, 0, n)
        if(mdSum!=colSum[i])
            ans.pb((-1*(i+1)));
        

    if(ans.size()==0){
        cout << 0 << endl;
        return;
    }

    ans.pb(ans.size());
    reverse(ans.begin(), ans.end());

    rep(i, 0, (ll) ans.size()){
        cout << ans[i] <<endl;
    }


    // rep(i, 0, n){
    //     cout << rowSum[i] << " ";
    // }
    // cout << endl;

    // rep(i, 0, n){
    //     cout << colSum[i] << " ";
    // }
    // cout << endl;
}

int32_t main() {
    FAST;

    t=1;
    while (t--) {
        solve();
    }

    return 0;
}