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

inline void print(){cout<<endl;}template<typename T,typename... A>inline void print(const T& a,const A&... z){cout<<a<<' ';print(z...);}inline void input(){}template<typename T,typename... A>inline void input(T& a,A&... z){cin>>a;input(z...);}template<typename T>inline void print(vector<T>& v){for(auto& i:v)cout<<i<<' ';cout<<endl;}template<typename T,typename S>inline void print(vector<T>& v,S s){for(auto& i:v)cout<<i<<s;}template<typename T>inline void input(vector<T>& v){for(auto& i:v)cin>>i;}


void dfs(ll i, ll j, vector<vector<char>>& v){
    if(i<0 or j<0 or i>v.size()-1 or j>v[i].size()-1 or v[i][j]=='#') return;
    v[i][j]='#';
    dfs(i,j+1,v);
    dfs(i+1,j,v);
    dfs(i,j-1,v);
    dfs(i-1,j,v);
}

void solution(ll &T){
    ll n,m; input(n,m); vector<vector<char>> v(n,vector<char> (m));
    for(auto &i:v) input(i);
    ll ans=0;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            if(v[i][j]=='.'){
                ans++;
                dfs(i,j,v);
            }
        }
    }
    print(ans);
}

signed main(){
    Parvez();
    ll TT=1;
    // cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}