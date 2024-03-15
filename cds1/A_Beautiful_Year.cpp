// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rfor(i,var) for(int i:var)
int main(){
    IOS;
    int num;
    cin>>num;
    int a[4];
    for (int i = num+1; i < 10000; i++)
    {
        a[0]=i%10;
        a[1]=(i/10)%10;
        a[2]=(i/100)%10;
        a[3]=(i/1000)%10;
        sort(a,a+4);
        if (a[0]==a[1]||a[1]==a[2]||a[2]==a[3])
        {continue;}
        cout<<i<<endl;
        break;
    }
    return 0;
}