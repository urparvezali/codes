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

inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(std::forward<T>(t)...);}template<class T>inline void print(vector<T> &v){for(auto &i:v){cout<<i;if(&i!=&v.back())cout<<' ';}cout<<endl;}inline void input(){}template<class H,class... T>inline void input(H &&h,T &&...t){cin>>h;input(std::forward<T>(t)...);}template<class T>inline void input(vector<T> &v){for(auto &i:v)cin>>i;}
#define print(...) print(__VA_ARGS__);
#define input(...) input(__VA_ARGS__);

int rec(int x,vector<int>& v,vector<int>& dp){
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    int z=INT_MAX;
    for(auto& i:v){
        if(x-i>=0)
            z=min(z*1L,rec(x-i,v,dp)+1L);
    }
    return dp[x]=z;
}
void solution(ll &T){
    int n,x; input(n,x); vector<int> v(n); input(v);
    vector<int> dp(1000001,-1);
    ll ans=rec(x,v,dp);
    print((ans==INT_MAX2?-1:ans));
}

signed main(){
    Parvez();
    ll TT=1;
    // cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}