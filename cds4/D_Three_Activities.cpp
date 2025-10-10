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
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod = 00000007;

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
inline void YES(){cout<<"YES"<<endl;}
inline void NO(){cout<<"NO"<<endl;}
inline void MINUS(){cout<<-1<<endl;}
inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}template<class T>inline void print(vector<T> &v){for(auto &i:v){cout<<i;if(&i!=&v.back())cout<<' ';}cout<<endl;}inline void input(){}template<class H,class... T>inline void input(H &&h,T &&...t){cin>>h;input(forward<T>(t)...);}template<class T>inline void input(vector<T> &v){for(auto &i:v)cin>>i;}




void solution(ll &T){
    ll n; input(n);
    vpll a(n),b(n),c(n);
    for (ll i = 0; i < n; i++){
        input(a[i].first);a[i].second=i;
    }
    for (ll i = 0; i < n; i++){
        input(b[i].first);b[i].second=i;
    }
    for (ll i = 0; i < n; i++){
        input(c[i].first);c[i].second=i;
    }
    sort(rall(a)); sort(rall(b)); sort(rall(c));

    ll ans=0;
    for (ll i = 0; i < 10 and i<n; i++){
        for (ll j = 0; j < 10 and j<n; j++){
            for (ll k = 0; k < 10 and k<n; k++){
                if(a[i].second!=b[j].second and b[j].second!=c[k].second and a[i].second!=c[k].second)                
                    ans=max(ans,a[i].first+b[j].first+c[k].first);
            }
        } 
    }
    print(ans);
}

int32_t main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}