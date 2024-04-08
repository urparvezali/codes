
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
constexpr ll mod = 1000000007;

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
inline void YES(){cout<<"YES"<<endl;}
inline void NO(){cout<<"NO"<<endl;}
inline void MINUS(){cout<<-1<<endl;}

inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}template<class T>inline void print(vector<T> &v){for(auto &i:v){cout<<i;if(&i!=&v.back())cout<<' ';}cout<<endl;}inline void input(){}template<class H,class... T>inline void input(H &&h,T &&...t){cin>>h;input(forward<T>(t)...);}template<class T>inline void input(vector<T> &v){for(auto &i:v)cin>>i;}

int rec(int x, vector<pair<int, int>>& v, vector<vector<int>>& dp, int i, int n) {
    if (i == n - 1){
        if(v[n-1].first<=x) return v[n-1].second;
        return 0;
    }
    if (dp[i][x] != -1) return dp[i][x];

    int a = rec(x, v, dp, i + 1, n);
    int b = 0;

    if (v[i].first <= x)
        b = v[i].second + rec(x - v[i].first, v, dp, i + 1, n);

    return dp[i][x] = max(a, b);
}

void solution(ll &T){
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);

    for (auto& [i, j] : v) cin >> i;
    for (auto& [i, j] : v) cin >> j;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    
    cout << rec(x, v, dp, 0, n) << '\n';
}

signed main(){
    Parvez();
    ll TT=1;
    // cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}