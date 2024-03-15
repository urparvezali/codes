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


void solution(ll &T){
    ll n; input(n); vll v(n); input(v);
    vll jor,bijor;
    
    for(auto& i:v) if(i&1) bijor.push_back(i); else jor.push_back(i);

    sort(jor.rbegin(),jor.rend());
    sort(bijor.rbegin(),bijor.rend());



    if(jor.size()%2!=0 or bijor.size()%2!=0){
        print(-1); return;
    }


    vll ans;
    if(jor.size()){
        for (ll i = 0; i < jor.size()/2; i+=1){
            ll div=(jor[i]-jor[jor.size()-i-1])/2;
            ans.push_back(jor[i]-div);
            ans.push_back(div);
        }
    }
    if(bijor.size()){
        for (ll i = 0; i < bijor.size()/2; i+=1){
            ll div=(bijor[i]-bijor[bijor.size()-i-1])/2;
            ans.push_back(bijor[i]-div);
            ans.push_back(div);
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