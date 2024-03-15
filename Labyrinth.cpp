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

pair<ll,string> bfs(ll i, ll j, ll n, ll m, vector<vector<bool>>& vs, vector<vector<char>>& v, vvll& level, vector<vector<char>>& dir){
	queue<pair<ll,ll>> q;
	q.push({i,j}); vs[i][j]=1;
	while(!q.empty()){
		ll a=q.front().first, b=q.front().second;
		q.pop();
		if (a>-1 and a<n and b>-1 and b<m and v[a][b]=='B'){
			ll lvl=level[a][b];
			string s;
			while (v[a][b]!='A'){
				// print(dir[a][b]);
				s.push_back(dir[a][b]);
				if(dir[a][b]=='R'){b--;}
				else if(dir[a][b]=='L'){b++;}
				else if(dir[a][b]=='U'){a++;}
				else if(dir[a][b]=='D'){a--;}
			}
			return {lvl,s};
		}
		if(a>-1 and a<n and b+1>-1 and b+1<m and v[a][b+1]!='#' and !vs[a][b+1]) {q.push({a,b+1}); vs[a][b+1]=true; level[a][b+1]=level[a][b]+1; dir[a][b+1]='R';}
		if(a>-1 and a<n and b-1>-1 and b-1<m and v[a][b-1]!='#' and !vs[a][b-1]) {q.push({a,b-1}); vs[a][b-1]=true; level[a][b-1]=level[a][b]+1; dir[a][b-1]='L';}
		if(a+1>-1 and a+1<n and b>-1 and b<m and v[a+1][b]!='#' and !vs[a+1][b]) {q.push({a+1,b}); vs[a+1][b]=true; level[a+1][b]=level[a][b]+1; dir[a+1][b]='D';}
		if(a-1>-1 and a-1<n and b>-1 and b<m and v[a-1][b]!='#' and !vs[a-1][b]) {q.push({a-1,b}); vs[a-1][b]=true; level[a-1][b]=level[a][b]+1; dir[a-1][b]='U';}
	}
	return {-1,""};
}

void solution(ll& T){
	ll n,m; input(n,m);
	vector<vector<char>> v(n,vector<char>(m));
	for(auto& i:v) input(i);
	vector<vector<bool>> vs(n,vbl (m,0));
	vvll level(n+1,vll (m+1,0));
	vector<vector<char>> dir(n,vector<char> (m,'*'));
	pair<ll,string> pp={-1,"janina"};

	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < m; j++){
			if(v[i][j]=='A'){
				pp=bfs(i,j,n,m,vs,v,level,dir);
				break;
			}
		}
	}
	// for(auto& i:dir) print(i);
	if(pp.first!=-1){
		print("YES");
		reverse(all(pp.second));
		print(pp.first);print(pp.second);
	} else print("NO");
}

signed main(){
	Parvez();
	ll TT=1;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}
