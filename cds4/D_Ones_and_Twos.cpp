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
class segtree
{
    ll size;
    vll sums;

public:
    segtree(ll n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sums.assign(2 * size, 0LL);
    }
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void set(ll i, ll v) { set(i, v, 0, 0, size); }
    ll sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r or l >= rx)
            return 0;
        if (lx >= l and rx <= r)
            return sums[x];
        ll m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
    ll sum(ll l, ll r) { return sum(l, r, 0, 0, size); }
};

void solution(ll &T){
    ll n,q; input(n,q);
    vll v(n); input(v);
    segtree st(n);
    for (ll i = 0; i < n; i++)
        st.set(i,v[i]);

    while(q--){
        ll que; input(que);
        if(que==1){
            ll s; input(s);
            for (ll i = 0; i < n; i++)
            {
                for (ll j = i; j < n; j++)
                {
                    if(st.sum(i,j+1)==s){
                        print("YES");
                        goto LABEL;
                    }
                }
            }
            print("NO");
            
        } else{
            ll i,integer; input(i,integer);
            st.set(i-1,integer);
        }
        LABEL:
            continue;
    }
}

signed main(){
    Parvez();
    ll TT=1;
    cin>>TT;
    for(ll T=1;T<=TT;T++)
        solution(T);
    return 0;
}