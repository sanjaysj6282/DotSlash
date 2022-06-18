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

vector<int> V , P;

vector<vector<vector<int>>> dp;

int maxVitamin(int N , int M , int flag) {
    if(dp[N][M][flag] != -1) 
        return dp[N][M][flag];
     
    // Base Condition
    if(N == 0) 
        return 0;
    
    // Choice Diagram
    if(flag == 1) {
        if(P[N-1] > M) 
            return dp[N][M][flag] = maxVitamin(N-1 , M , flag);
        else 
            return dp[N][M][flag] = max(V[N-1] + maxVitamin(N-1 , M-P[N-1] , flag) , maxVitamin(N-1 , M , flag));
    }
    else {
        if(P[N-1] > M) {
            if(P[N-1]/2 > M) 
                return dp[N][M][flag] = maxVitamin(N-1 , M , flag);
            else 
                return dp[N][M][flag] = max(V[N-1] + maxVitamin(N-1 , M-(P[N-1]/2) , 1) , maxVitamin(N-1 , M , 0));
        }
        else {
            int x = maxVitamin(N-1 , M , flag);
            int y = V[N-1] + maxVitamin(N-1 , M-P[N-1] , 0);
            int z = V[N-1] + maxVitamin(N-1 , M-(P[N-1]/2) , 1);
            return dp[N][M][flag] = max({x , y , z});
        }
    }
}

void solve() {
    int N , M , i;
    
    // Reading N and M
    cin >> N >> M;

    // Initialization
    V = vector<int> (N);
    P = vector<int> (N);
    dp = vector<vector<vector<int>>> (N+5 , vector<vector<int>> (M+5 , vector<int> (2 , -1)));

    // Reading type[i] , V[i] and P[i]
    for(i = 0 ; i < N ; ++i) {
        cin >> V[i] >> P[i];
    }

    // Call for recursive dp function
    int ans = maxVitamin(N , M , 0);

    // Printing the answer
    cout << ans << "\n";
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