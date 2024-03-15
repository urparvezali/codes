// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<ll> vll;
#define endl '\n'
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod (1e9 + 7)

int main()
{
    IOS;
    int n;
    cin >> n;

    int p;
    cin >> p;
    int pa[p];
    for (int i = 0; i < p; i++)
    {
        cin>>pa[i];
    }
    
    int q;
    cin >> q;
    int qa[q];
    for (int i = 0; i < q; i++)
    {
        cin>>qa[i];
    }
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (i + 1 == pa[i])
        {
            arr[i] = pa[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == qa[i])
        {
            arr[i] = qa[i];
        }
    }

    int token=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            token++;
            break;
        }
    }

    if (token==0)
    {
        cout<<"I become the guy."<<endl;
    }
    else
    {
        cout<<"Oh, my keyboard!"<<endl;
    }
    return 0;
}