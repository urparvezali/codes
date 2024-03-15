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

void dfs(ll n, vll& vs, unordered_map<ll,vll>& v){
	if(vs[n]==2) return;
	// cout<<n<<" ";
	vs[n]=2;
	for(auto& c:v[n]){
		dfs(c,vs,v);
	}
}

void solution(ll &T){
	ll n; input(n); vll a(n),b(n);
	input(a); input(b);
	unordered_map<ll,vll> g;
	unordered_set<ll> st;
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < n; j++){
			if(i!=j and a[i]-a[j]>=b[i]-b[j]){
				g[i+1].push_back(j+1);
				st.insert(i+1);
				st.insert(j+1);
			}
		}
	}
	vll ans;
	for(auto &i: st){
		vll vs(n+1,0);
		for(auto &j: st)
			vs[j]=1;
		
		// print();
		dfs(i,vs,g);
		bool tok=true;

		for (ll j = 0; j < n+1; j++){
			// cout<<vs[j]<<" ";
			if(vs[j]==1){
				tok=false;break;
			}
		}
		if(tok) ans.push_back(i);
		// print();
	}
	sort(all(ans));
	print(ans.size());
	print(ans);
}

signed main(){
	Parvez Ali
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}