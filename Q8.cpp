#include <bits/stdc++.h>
#define int long long
#define inf 5e18
#define MOD (int)(1e9 + 7)
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
using namespace std;
int n,m;
const int N = 2500;
vi a(N);
int dp[N][N];
int f(int id, int sum) {
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(dp[id][sum] != -1) return dp[id][sum];
    int ans = 0;
    for(int i=id;i<m;i++) {
        ans += f(i,sum-a[i]);
    }
    return dp[id][sum] = ans;
}

void solve() {
    cin>>n>>m;
    a.resize(m);
    for(int i=0;i<m;i++) cin>>a[i];
    sort(all(a));
    memset(dp,-1,sizeof(dp));
    cout<<f(0,n);
}

signed main()
{
    solve();
    return 0;   
}
