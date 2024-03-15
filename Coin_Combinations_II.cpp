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

int rec(vector<int>& coins, int amount, vector<vector<int>>& dp, int idx){
    if(amount==0) return 1;
    if(idx>=coins.size()) return 0;
    if(amount<0) return 0;
    if(dp[idx][amount]!=-1) return dp[idx][amount];
    int z=0;
    for(int i=0;amount-i>=0;i+=coins[idx]){
        z=(z+rec(coins,amount-i,dp,idx+1))%mod;
    }
    return dp[idx][amount]=z;
}
int main() {
    ll n,amount; input(n,amount); vector<int> coins(n); input(coins);
    vector<vector<int>> dp(101,vector<int> (1000001,-1));
    print(rec(coins,amount,dp,0));
}