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

 void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
 void YES(){cout<<"YES"<<endl;}
 void NO(){cout<<"NO"<<endl;}
 void MINUS(){cout<<-1<<endl;}

 void print(){cout<<endl;}template<typename T,typename... A> void print(const T& a,const A&... z){cout<<a<<' ';print(z...);}template<typename T> void print(vector<T>& v){for(auto& i:v)cout<<i<<' ';cout<<endl;}template<typename T,typename S> void print(vector<T>& v,S s){for(auto& i:v)cout<<i<<s;} void input(){}template<typename T,typename... A> void input(T& a,A&... z){cin>>a;input(z...);}template<typename T> void input(vector<T>& v){for(auto& i:v)cin>>i;}
#define print(...) print(__VA_ARGS__);
#define input(...) input(__VA_ARGS__);

ll dfs(ll i, ll j,vvll &v){
    if(i<0 or j<0 or i>=v.size() or j>=v[i].size() or v[i][j]==0) return 0;
    ll sum=v[i][j];
    v[i][j]=0;
    return sum+dfs(i,j+1,v)+dfs(i,j-1,v)+dfs(i+1,j,v)+dfs(i-1,j,v);
}

void solution(ll &T){
    ll n,m; input(n,m);
    vvll v(n,vll (m,0));
    for(auto &&i:v) input(i);
    ll ans=0;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            if(v[i][j]!=0){
                ans=max(ans,dfs(i,j,v));
            }
        }
    }
    print(ans)
}

signed main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}