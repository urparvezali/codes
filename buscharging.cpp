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
constexpr ll mod=1000000007;

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }

void gprint(vvll& v){
	for(ll i=0; i < v.size(); i++){
		cout<<i<<": ";
		for(ll j=0; j < v[i].size(); j++){
			cout<<v[i][j]<<' ';
		}
		cout<<endl;
	}
}


vll bfs(ll s,vvll& v,vll& level){
	vll mins; ll dis=-1;

	queue<ll> q; vbl vs(v.size()+1);
	q.push(s); vs[s]=true;
	while(q.size()){
		ll nd=q.front(); q.pop();
		for(auto& u: v[nd]){
			if(!vs[u]){
				q.push(u);
				vs[u]=true;
				level[u]=level[nd]+1;
				if(v[u].size()==1) mins.push_back(u);
			}
		}
	}
	return mins;
}

void solution(ll& T){
	ll n; cin>>n;
	vvll v(n+1,vll());
	ll x;
	for(ll i=0; i < n-1; i++){
		cin>>x;
		v[x].push_back(i+2);
		v[i+2].push_back(x);
	}
	// if(n==1){
	// 	cout<<1<<' '<<0<<endl;return;
	// }

	vll level(v.size()+1,0);
	vll mins=bfs(1,v,level);
	// for(ll i=0; i < level.size(); i++){
	// 	cout<<i<<"-"<<level[i]<<endl;
	// }
	// cout<<endl;
	ll d=INT_MAX,ans=INT_MAX;

	for(auto& u: mins){
		if(d>level[u]){
			d=min(d,level[u]);
		}
	}
	for(ll i=0; i < mins.size(); i++){
		if(mins[i]<ans and level[mins[i]]==d){
			ans=mins[i];
		}
	}
	if(ans==INT_MAX or d==INT_MAX){
		cout<<1<<' '<<0<<endl;return;
	}
	cout<<ans<<' '<<d<<endl;return;
}

signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}