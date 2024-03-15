#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<string> vstr;
typedef vector<pll> vpll;
typedef map<ll,ll> mll;
typedef map<string,ll> mstrl;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
const ll mod = 998244353;

void YES(){cout<<"YES"<<endl;}
void NO(){cout<<"NO"<<endl;}
void MINUS(){cout<<-1<<endl;}

void print(){cout<<endl;}template<typename T,typename... A>void print(const T& a,const A&... z){cout<<a<<' ';print(z...);}
void input(){}template<typename T,typename... A>void input(T& a,A&... z){cin>>a;input(z...);}
template<typename T>void print(vector<T>& v){for(auto& i:v)cout<<i<<' ';cout<<endl;}
template<typename T,typename S>void print(vector<T>& v,S s){for(auto& i:v)cout<<i<<s;}
template<typename T>void input(vector<T> &v){for(auto& i:v)cin>>i;}

bool isprime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
ll bpow(ll a,ll b){ll r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
ll mbpow(ll a,ll b){a%=mod;ll r=1;while(b>0){if(b&1)r=r*a%mod;a=a*a%mod;b>>=1;}return r;}
class Sieve{private:vector<bool> vp;public:Sieve(ll np){vp.resize(np+1,true);vp[0]=vp[1]=false;for(ll i=2;i<=np;i++){if(vp[i]==true){for(ll j=2*i;j<=np;j+=i){vp[j]=false;}}}}bool getprime(ll n){return vp[n];}};
ll b2d(string& b){ll n=0;for(ll i=b.length()-1,j=0;i>=0;--i,++j){if(b[i]=='1'){n+=(1<<j);}}return n;}
vector<ll> d2b(ll n){vector<ll> b;ll r;while(n!=0){r=n&1;b.push_back(r);n>>=1;}reverse(all(b));return b;}

class Graph{vvll G;public:Graph(ll V):G(V+1){}void add(ll u,ll v){G[u].push_back(v);G[v].push_back(u);}void dfs(ll s){vector<bool> vs(G.size());stack<ll> st{{s}};while(!st.empty()){ll v=st.top();st.pop();if(!vs[v]){vs[v]=true;cout<<v<<' ';for(ll u:G[v]){if(!vs[u]){st.push(u);}}}}}void bfs(ll s){vector<bool> vs(G.size());queue<ll> q{{s}};while(!q.empty()){ll v=q.front();q.pop();if(!vs[v]){vs[v]=true;cout<<v<<' ';for(ll u:G[v]){if(!vs[u]){q.push(u);}}}}}};


void solution(ll &T){
	ll n; input(n); vll v(n);input(v);
	ll sum1=0,sum2=0;
	if(is_sorted(all(v))){
		print(0); return;
	}
	else{
		ll idx=0;
		for (ll i = n-2; i >= 0; i--)
		{
			if(v[i]>v[i+1]){
				idx=i+1;break;
			}
		}
		print(*max_element(v.begin(),v.begin()+idx));
	}
	// for (ll i = n-2; i >= 0; i--)
	// {
	// 	if(v[i]>v[i+1]){
	// 		sum1+=(v[i]-v[i+1]);
	// 		v[i]-=(v[i]-v[i+1]);
	// 	}
	// }
	// print(v);
	// print(sum1);
}

signed main(){
	Parvez Ali
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}