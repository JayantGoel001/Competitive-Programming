#include<bits/stdc++.h>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
#define forr(a,n) for(int i=a;i<=n;i++)
#define MAX 1000000007LL
#define mod 998244353
#define forn(n,a) for(int i=n;i>=a;i--)
#define all(x) x.begin() , x.end()
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define ll long long
const int N = (int)1e5 + 9;
ll power(ll x,ll y)
{
    if(y == 0)
        return 1;
    ll temp = power(x,y/2);
    if(y%2 == 1)
        return temp*temp*x;
    else    
        return temp*temp;
}
int a[N];
int t = 1;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #else
    
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n , s = 0;
    int mini = INT_MAX , maxi = INT_MIN;
    cin>>n;
    forr(0,n-1)
    {
        cin>>a[i];
        if(a[i] > 0)    s+=a[i];
    }

    if(s%2 == 1)
        cout<<s;
    else
    {
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(a[i] >= 0)
            {
                if((s - a[i]) & 1)
                {
                    ans = max(ans , s-a[i]);
                }
            }
            else{
                if((s + a[i])&1)
                {
                    ans = max(ans , s+a[i]);
                }
            }
        }
        cout<<ans;
    }



    return 0;
}
