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

void dfs(ll s, vbl &vs, vvll &v,vll& group,ll par,bool& bln){

    if(group[s]!=-1 and group[s]==group[par]){
        bln=true;
        return;
    }

    if (vs[s] or bln)
        return;

    if(group[par]&1) group[s]=2;
    else group[s]=1;

    vs[s]=1;

    for (auto &c : v[s])
        dfs(c, vs, v,group,s,bln);
}
void solution(ll &T){
    ll v,e; input(v,e);
    vvll g(v+1,vll ());
    for (ll i = 0; i < e; i++){
        ll x,y; input(x,y);
        g[x].push_back(y); g[y].push_back(x);
    }
    vbl vs(v+1); vs[0]=1;

    vll group(v+1,-1);
        group[0]=2;

    bool bln=false;

    for (ll i = 1; i <=v; i++){
        if(!vs[i]){
            dfs(i,vs,g,group,0,bln);
        }
    }
    if(bln){
        print("IMPOSSIBLE"); return;
    }
    for (ll i = 1; i < group.size(); i++){
        cout<<group[i]<<' ';
    }
}

signed main(){
    Parvez();
    ll TT=1;
    // cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}