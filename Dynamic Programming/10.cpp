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
    string s,t;
    cin >> s >> t;
    
    vector<vector<int>> dp(s.length()+5,vector<int>(t.length()+5,1e9));

    dp[0][0] = 0;

    for(int i=1 ; i<=s.length() ; i++) dp[i][0] = i;
    for(int i=1 ; i<=t.length() ; i++) dp[0][i] = i;

    for(int i=1 ; i<=s.length() ; i++){
        for(int j=1 ; j<=t.length() ; j++){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
                dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }

    cout << dp[s.length()][t.length()];
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // precalc();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}