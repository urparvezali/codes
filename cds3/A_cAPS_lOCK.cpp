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
	string s; input(s);
	ll cnt=0;
	for (ll i = 0; i < s.size(); i++)
		if(s[i]>'Z')cnt++;

	if(s[0]>'Z' and cnt==1){
		cout<<char(s[0]-32);
		for (ll i = 1; i < s.size(); i++)
		{
			cout<<char(s[i]+32);
		}
		print();
	}
	else if(cnt==0){
		for (ll i = 0; i < s.size(); i++)
		{
			cout<<char(s[i]+32);
		}
		print();
	}
	else print(s);
}

signed main(){
	Parvez Ali
	ll TT=1;
	// cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}