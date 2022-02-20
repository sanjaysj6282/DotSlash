
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
#define vect(v, n) {vi v; rep(i, 0, n){ll x; cin>>x; v.pb(x);}}

const int M=1e4+3, MOD=1e9+7;

ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b); }
ll lcm(ll a,ll b) {return a/gcd(a,b)*b; }

int main() {
    FAST;

    ll t; cin >> t;
    while (t--) {
        string s; cin >> s;
        ll n=s.length();
        map<char, ll> mp;
        ll mx=0;
        char mxval=' ';
        rep(i, 0, n){
            mp[s[i]]++;
            if(mp[s[i]]>mx){
                mx=mp[s[i]];
                mxval=s[i];
            }
        }
        // cout << mx << " mx " << mxval << " ";

        	
        string ans(n, ' ');
        // ans[n]='\0';
        if(mx>(n+1)/2){
            cout <<"Not Possible\n";
            continue;
        }

        ll i=0;
        ll cnt=1;
        for(; i<n; i+=2){
            if(mp[mxval]>0){
                mp[mxval]--;
                ans[i]=mxval;
            }
            cnt++;
            // cout << i << " ";
        }
        // cout << 44 << "   ";

        map<char, ll> :: iterator it;
        for(it=mp.begin(); it!=mp.end(); it++){
            while(it->second>0){
                if(i>=n){
                    i=1;
                }
                ans[i]=it->first;
                it->second--;
                i+=2;
            }
            // cout << it->ff << " " << it->second << " dd";
        }
        cout << ans;
        cout << "\n";
        
        // while(cnt<s.length()){
        //     if(i==n-1 || i==n-2){
        //         i=1;
        //     }
        //     for(it=mp.begin(); it!=mp.end(); it++){
        //         if(it->second>0){
        //             ans[i]=it->first;
        //             it->second--;
        //         }
        //         cout << it->ff << " " << it->second << " dd";
        //     }
        //     if(!(i==n-1 || i==n-2)){
        //         i+=2;
        //     }
        //     cnt++;
        //     cout << i << " ";
        // }


        // vector<string> vs;
        
        // rep(i, 0, n){
        //     string s; cin >> s;
        //     vs.pb(s);
        //     map<char, ll> mp;
        //     rep(i, 0, s.length()){
        //         mp[s[i]]++;
        //     }
        //     string ans="";
        //     map<char, ll> :: iterator it;
        //     rep(j, 0, 501){
        //         for(it=mp.begin(); it!=mp.end(); it++){
        //             if(it->second>0){
        //                 ans+=it->first;
        //                 it->second--;
        //             }
        //         }
        //     }

        //     rep(i, 0, ans.length()-1){
        //         if(ans[i]==ans[i+1]){
        //             cout << "Not Possible\n";
        //             return 0;
        //         }
        //     }
        //     cout << ans << "\n";

        //     // cout << vs[i] << " ";
        // }
    }

    return 0;
}