#include <cstdio>
#include <algorithm>
typedef long long ll;

using namespace std;
const int N=200005;

int t,n,a[N];ll sum,ans;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),sum=ans=0;
		for(int i=1;i <= n;i++)
			scanf("%d",&a[i]),sum+=a[i];ans=sum;
		for(int i=1;i <= n;i++)
			sum-=2 * a[i],ans=max(ans,sum);
		printf("%lld\n",ans);
	}
}