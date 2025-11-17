#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod = 998244353;

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template<class T>inline istream& operator>>(istream& in,vector<T>& v){for(T& x:v){in>>x;}return in;}template<class T>inline ostream& operator<<(ostream& out,vector<T>& v){if(v.empty()) return out;for(ll i=0;i<v.size()-1;i++){out<<v[i]<<' ';}out<<v[v.size()-1];return out;}
inline void inp(){}template<class H,class... T>inline void inp(H&& h,T &&...t){cin>>h;inp(forward<T>(t)...);}inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}

ll fact[200005], invf[200005];

ll power(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void init(ll n) {
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    invf[n] = power(fact[n], mod - 2);
    for (ll i = n - 1; i >= 0; i--) {
        invf[i] = (invf[i+1] * (i+1)) % mod;
    }
}

ll C(ll n, ll k) {
    if (k > n || k < 0) return 0;
    return (fact[n] * invf[k] % mod) * invf[n-k] % mod;
}

void solution(ll &T){
    ll n;
    string s;
    inp(n, s);
    
    ll z = 0, o = 0;
    for (char c : s) {
        if (c == '0') z++;
        else o++;
    }
    
    init(n);
    
    ll ans = 0;
    
    // For each pair (j, i) with j < i in f(f(a)):
    // f(f(a))[i] counts j where f(a)[j] > f(a)[i]
    // f(a)[k] = count of positions p < k where a[p] > a[k] = count of 1s before k (since a[p] in {0,1})
    
    // For binary array: f(a)[k] = number of 1s in positions [0, k-1]
    
    // We sum over all permutations and all positions i: f(f(a))[i]
    // = sum over all permutations, positions i, and j<i: [f(a)[j] > f(a)[i]]
    
    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j < i; j++) {
            // Count permutations where f(a)[j] > f(a)[i]
            // f(a)[j] = #1s in [0..j-1]
            // f(a)[i] = #1s in [0..i-1]
            
            // For f(a)[j] > f(a)[i], need #1s in [0..j-1] > #1s in [0..i-1]
            // But j < i, so [0..j-1] is subset of [0..i-1]
            // This is impossible! f(a)[j] <= f(a)[i] always when j < i
            
            // Wait, let me reconsider...
            // f(a)[i] counts positions p < i where a[p] > a[i]
            // For binary: a[p] > a[i] means a[p]=1 and a[i]=0
            
            // So f(a)[i] = (# of 1s before i) if a[i]=0, else 0
            
            // Now f(f(a))[k] counts positions q < k where f(a)[q] > f(a)[k]
            
            // Let's enumerate: at position j, f(a)[j] depends on a[j] and #1s before j
            // At position i > j, f(a)[i] depends on a[i] and #1s before i
            
            // For f(a)[j] > f(a)[i]:
            // Case 1: a[j]=0, a[i]=0: f(a)[j] = #1s before j, f(a)[i] = #1s before i
            //         Since j < i: impossible (f(a)[j] <= f(a)[i])
            // Case 2: a[j]=0, a[i]=1: f(a)[j] = #1s before j, f(a)[i] = 0
            //         Need #1s before j > 0, so need at least one 1 before j
            // Case 3: a[j]=1, a[i]=0: f(a)[j] = 0, f(a)[i] = #1s before i >= 0
            //         impossible (0 > x)
            // Case 4: a[j]=1, a[i]=1: both are 0, impossible
            
            // So only Case 2: a[j]=0, a[i]=1, and at least one 1 before j
            
            if (z > 0 && o > 0) {
                // Count: a[j]=0, a[i]=1, and k 1s before j (k >= 1)
                for (ll k = 1; k <= min(j, o); k++) {
                    // k 1s in [0..j-1], 0 at j, some 1s in [j+1..i-1], 1 at i, rest anywhere
                    // Total 1s = o, used: k before j, 1 at i = k+1
                    // Remaining: o - k - 1 to place in (j+1..i-1) and (i+1..n-1)
                    
                    for (ll m = 0; m <= min((ll)(i - j - 1), o - k - 1); m++) {
                        // m 1s in [j+1..i-1]
                        ll rem1 = o - k - 1 - m; // 1s in [i+1..n-1]
                        ll rem0 = z - 1; // 0s to place (excluding position j)
                        
                        // Ways: C(j, k) * C(i-j-1, m) * C(n-i-1, rem1)
                        ll ways = C(j, k);
                        ways = (ways * C(i - j - 1, m)) % mod;
                        ways = (ways * C(n - i - 1, rem1)) % mod;
                        
                        
                        // Contribution = k (the value f(a)[j])
                        ans = (ans + (ways * k) % mod) % mod;
                    }
                }
            }
        }
    }
    
    print(ans);
}

signed main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}