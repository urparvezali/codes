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



void dfs(ll s, vbl &vs, vvll &v, ll par, vll& ans, bool& ok){
    // print(ans);

    if(vs[s] and s!=par)
        ok=true;
    if(vs[s] or ok){
        return;
    }


    vs[s] = 1;

    for (auto &c : v[s]){
        if(!ok)
            ans.push_back(c);
        dfs(c, vs, v, s, ans, ok);
        if(!ok)
            ans.pop_back();
    }
}

void solution(ll &T){
    ll n,e; input(n,e);
    vvll v(n+1);
    ll x,y;
    for (ll i = 0; i < e; i++){
        input(x,y);
        v[x].push_back(y); v[y].push_back(x);
    }
    vbl vs(n+1);
    vll ans;
    bool ok=false;
    dfs(1,vs,v,0,ans,ok);
    if(!ok){
        print("IMPOSSIBLE");
        return;
    }
    cout<<ans.size()+1<<"\n"<<1<<" "; print(ans);
}

int32_t main(){
    Parvez();
    ll TT=1;
    // cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}