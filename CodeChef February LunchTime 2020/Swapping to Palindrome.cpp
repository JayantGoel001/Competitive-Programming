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
    ll ans = 1;
    while(y>0)
    {
        if(y%2 == 1)
            ans = ans*x;
        x=x*x;
        y=y>>1;
    }
    return ans;
}
string s;
int n;
void ok(){
    int i = 0 , j = n-1;
    int vis[n+10] = {0};
    ll cnt = 0;
    while(i<j)
    {
        if(s[i] != s[j])
        {
            if(vis[i] == 0 && vis[i+1] == 0 && (i+1) != j && s[i+1] == s[j])
            {
                swap(s[i] , s[i+1]);
                vis[i] = true;
                vis[i+1] = true;
                cnt++;
            }
            else if(vis[j] == 0 && vis[j-1] == 0 && i != j-1 && s[i] == s[j-1])
            {
                swap(s[j] , s[j-1]);
                vis[j] = true;
                vis[j-1] = true;
                cnt++;
            }
            else
            {
                cout<<"NO\n";
                return;
            }
        }
        i++;
        j--;
    }

    cout<<"YES\n"<<cnt<<"\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
    // freopen("out.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>s;
        ok();
    }
        
    return 0;
}
