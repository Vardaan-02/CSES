#include <bits/stdc++.h>
 
using namespace std;
 
// #define int long long int
// #define double long double
// #define INT_MAX LLONG_MAX
// #define INT_MIN LLONG_MIN
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vpin(a) for(int i=0;i<(a).size();i++)cin>>a[i].first>>a[i].second;
#define vpout(a) for(int i=0;i<a.size();i++)cout<<a[i].first<<' '<<a[i].second<<endl;cout<<endl;
#define cout(x) cout<<setprecision(20)<<x<<endl 
#define r(x) {cout<<x<<'\n';return;}
 
const int M = 1000000007;
const int N = 1e5+10;

vector<int> ans(1e6+10,1e9);

void precalc(){}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vin(v);
    vector<vector<int>> dp(n+10,vector<int>(110,0));
    if(v[0]==0) for(int i=1 ; i<=100 ; i++) dp[0][i]++;
    else dp[0][v[0]]++;
    for(int i=1 ; i<n ; i++){
        if(v[i]==0){
            for(int j=1 ; j<=m ; j++){
                if(j>0) dp[i][j] += dp[i-1][j-1];
                dp[i][j]%=M;
                dp[i][j] += dp[i-1][j];
                dp[i][j]%=M;
                if(j<m) dp[i][j] += dp[i-1][j+1];
                dp[i][j]%=M;
            }
        }
        else{
            if(v[i]>0) dp[i][v[i]] += dp[i-1][v[i]-1];
            dp[i][v[i]]%=M;
            dp[i][v[i]] += dp[i-1][v[i]];
            dp[i][v[i]]%=M;
            if(v[i]<m) dp[i][v[i]] += dp[i-1][v[i]+1];
            dp[i][v[i]]%=M;
        }
    }

    int ans = 0;
    for(int i=1 ; i<=m ; i++){
        ans += dp[n-1][i];
        ans %= M;
    }
    cout << ans;
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