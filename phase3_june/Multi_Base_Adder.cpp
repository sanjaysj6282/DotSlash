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
ll n, base, m, k, t;
string s, s1, s2;


void solve(){
    cin >> base;
    string norep; cin >> norep;

    mii representation; 
    map<ll, char> representationrev;
    rep(i, 0, base){
        representation[norep[i]]=i;
        representationrev[i]=norep[i];
    }

    string n1; string n2;
    cin >> n1; cin >> n2;

    string max_string, min_string;
    if(n1.length() <= n2.length()){
        min_string=n1;
        max_string=n2;
    }
    else{
        max_string=n1;
        min_string=n2;
    }

    reverse(max_string.begin(), max_string.end());
    reverse(min_string.begin(), min_string.end());

    ll carry=0;
    string ans="";

    // cout << min_string <<endl;
    // cout << max_string << endl;
    rep(i, 0, (ll) min_string.length()){
        ll currVal=representation[min_string[i]]+representation[max_string[i]];
        ll currValwocarry=(currVal+carry)%base;
        // cout << currVal << " ";
        // cout << currValwocarry << endl;
        if(currVal>=base-carry)
            carry=1;
        else
            carry=0;
        ans+=representationrev[currValwocarry];
        // cout << ans << " ";
    }
    
    // carry==0, same --> correct
    // carry==0, diff --> correct
    // carry==1, same --> correct
    // carry==1, diff --> incorrect
    if(carry==1 && min_string.length()==max_string.length()){
        ans+=norep[1];
    }
    else{
        rep(i, (ll) min_string.length(), (ll) max_string.length()){
            ll currVal=representation[max_string[i]];
            ll currValwocarry=(currVal+carry)%base;
            // cout << currVal << " ";
            // cout << currValwocarry << endl;
            if(currVal>=base-carry){
                carry=1;
            }
            else{
                carry=0;
            }
            ans+=representationrev[currValwocarry];
            // cout << ans << " ";
        }
        if(carry==1){
            ans+=norep[1];
        }     
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    // else if(carry==1 && min_string.length()!=max_string.length()){
    //     // cout << ans << endl;
    //     // while(carry==1){
    //         rep(i, (ll) min_string.length(), (ll) max_string.length()){
    //             ll currVal=representation[max_string[i]];
    //             ll currValwocarry=(currVal+carry)%base;
    //             // cout << currVal << " ";
    //             // cout << currValwocarry << " ";
    //             // cout << carry << endl;

    //             ll add=currVal+carry;
    //             if(add>=base){
    //                 carry=1;
    //             }
    //             else{
    //                 carry=0;
    //             }
    //             // cout << carry << endl;
    //             ans+=representationrev[currValwocarry];
    //             // cout << ans << " ";
    //         }
    //         // cout << carry << endl;
    //         if(carry==1){
    //             ans+=norep[1];
    //         }
    //     // }
    // }
}

int32_t main() {
    FAST;

    t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}