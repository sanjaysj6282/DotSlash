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

string decToBinary(ll n)
{
    string ans="";
    for (int i = 15; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans+="1";
        else
            ans+="0";
    }

    return ans;
}



int32_t main() {
    FAST;

    ll t=1;
    cin >> t;
    while (t--) {
        ll n, m; char shift;
        cin >> n >> m >> shift;
        // cout << n << m << shift << endl;
        string bin=decToBinary(n);

        // cout << bin << endl;

        string ans="";
        ll res;
        if(shift=='L'){
            string torev=bin.substr(0, m);
            // reverse(torev.begin(),torev.end());
            // 11011001001 00011

            ans=bin.substr(m)+torev;
            res=stoi(ans, 0, 2);
        }
        else{
            string torev=bin.substr(16-m);
            // cout << torev << "  ";
            // reverse(torev.begin(),torev.end());

            ans=torev+bin.substr(0, 16-m);
            res=stoi(ans, 0, 2);
        }
        // cout << ans << endl;
        cout << res << endl;
    }

    return 0;
}