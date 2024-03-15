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

ll rec(vll& dp, ll n){
    // print(dp);
    if(n==0) return 0;
    if(dp[n]!=INT_MAX){
        return dp[n];
    }
    ll digit,temp=n,z=INT_MAX;
    while(temp){
        digit=temp%10;
        if(digit!=0)
            z=min(z,rec(dp,n-digit)+1);
        temp/=10;
    }
    return dp[n]=z;
}
void solution(ll &T){
    ll n; input(n);
    vll dp(n+1,INT_MAX);dp[0]=0;//dp[1]=dp[2]=dp[3]=dp[4]=dp[5]=dp[6]=dp[7]=dp[8]=dp[9]=1;
    print(rec(dp,n));
    // print(dp);
}

signed main(){
    Parvez();
    ll TT=1;
    // cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}