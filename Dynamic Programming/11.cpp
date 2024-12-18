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

vector<vector<int>> dp(510,vector<int>(510,1e9));

void precalc(){
    for(int i=0 ; i<510 ; i++) dp[i][i] = 0;
    for(int i=1 ; i<=500 ; i++){
        for(int j=1 ; j<=500 ; j++){
            for(int a=1 ; a<i ; a++)  dp[i][j] = min(dp[i][j],1+dp[i-a][j]+dp[a][j]);
            for(int a=1 ; a<j ; a++)  dp[i][j] = min(dp[i][j],1+dp[i][j-a]+dp[i][a]);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    cout << dp[n][m];
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