#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long int
#define double long double
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vpin(a) for(int i=0;i<(a).size();i++)cin>>a[i].first>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<'\n';return;}
 
const int M = 1000000007;
const int N = 1e6+10;

void precalc(){}

void solve(){
    int n;
    cin >> n;
    int sum = n*(n+1)/2;

    if(sum&1) r(0);

    vector<vector<int>> dp(n+1,vector<int>((sum+1),0));

    for(int i=0 ; i<=n ; i++) dp[i][0] = 1;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=sum ; j++){
            if(j-i>=0) dp[i][j] += dp[i-1][j-i];
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= M;
        }
    }

    cout << dp[n-1][sum/2];
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precalc();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}