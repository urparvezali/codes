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
#define print(...) print(__VA_ARGS__);
#define input(...) input(__VA_ARGS__);

ll rec(ll i, ll j, ll& n, vector<vector<char>>& v, vvll& dp){
    if(i==n-1 and j==n-1 and v[i][j]=='.') return 1;
    else if(i>n-1 or j>n-1 or v[i][j]=='*') return 0;
    if(dp[i][j]!=INT_MAX) return dp[i][j];
    return dp[i][j]=(rec(i+1,j,n,v,dp)+rec(i,j+1,n,v,dp))%mod;
}

signed main(){
    Parvez();
    ll n; input(n);
    vector<vector<char>> v(n,vector<char> (n));
    for(auto& I:v) input(I);
    vvll dp(n,vll (n,INT_MAX));
    print(rec(0,0,n,v,dp));
}