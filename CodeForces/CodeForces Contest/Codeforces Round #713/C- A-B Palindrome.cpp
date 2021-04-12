#include<bits/stdc++.h>
#include<stdio.h>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define fore(i,a,n) for (int i = (a); i <= (n); ++i)
#define ford(i,a,b) for (int i = (a); i >= (b); --i)
#define MAX 1000000007LL
#define mod 998244353
#define forn(n,a) for(int i=n;i>=a;i--)
#define all(x) x.begin() , x.end()
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define ll long long
#define pii pair<int,int>
#define pll pair<long,long>
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

void solve() {
    int a,b;
    string s;
    int cnt1 = a , cnt2 = b;
    cin>>a>>b>>s;
    int n = s.length();
    int i=0,j=n-1;

    forr(i,0,n) {
        if(s[i] == '?') continue;
        if(s[i] == '0') a--;
        else b--;
    }

    while(i<=j) {
        if(s[i] == '?' && s[j] == '?') {

        } else if(s[i] == '?') {
            if(s[j] == '0') a--;
            else b--;



            s[i] = s[j];

        } else if(s[j] == '?') {
            if(s[i] == '0') a--;
            else b--;

            s[j] = s[i];
        } else if(s[i] != s[j]) {
            cout<<"-1\n";
            return;
        }
        i++;
        j--;
    }

    if(a<0 || b<0) {
        cout<<"-1\n";
        return;
    }

    i = 0;
    j = n-1;

    while(i <= j) {
        if(s[i] == '?' && s[j] == '?') {
            if(i == j) {
                if(a>=1) {
                    s[i] = '0';
                    a--;
                } else if(b >= 1) {
                    s[i] = '1';
                    b--;
                } else {
                    cout<<"-1\n";
                    return;
                }
            } else {
                if(a >= 2) {
                    s[i] = '0';
                    s[j] = '0';
                    a-=2;
                } else if(b >= 2) {
                    s[i] = '1';
                    s[j] = '1';
                    b-=2;
                } else {
                    cout<<"-1\n";
                    return;
                }
            }
        }
        i++;
        j--;
    }

    if(a!=0 && b!=0) cout<<"-1\n";
    else cout<<s<<"\n";

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);    
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}
